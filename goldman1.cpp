#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <json/json.h>

using namespace std;

struct Action {
    string type;
    double x, y, t;
    vector<string> delivery_ids;
    string delivery_id;
};

struct Drone {
    string id;
    double max_payload;
    double current_time = 0.0;
    vector<Action> path;
};

struct Delivery {
    string id;
    double x, y, weight, deadline;
    bool assigned = false;
    int fail_count = 0;
};

struct NFZ {
    int type; 
    double cx, cy, r;
    double min_x, max_x, min_y, max_y;
    double t_start, t_end;
    double bb_min_x, bb_max_x, bb_min_y, bb_max_y;
};

struct Station {
    double x, y;
    int slots;
    vector<double> available_times;
    double dist_wh;

    void init(double wX, double wY) {
        if (slots <= 0) slots = 1;
        available_times.assign(slots, 0.0);
        double dx = x - wX;
        double dy = y - wY;
        dist_wh = sqrt(dx * dx + dy * dy);
    }

    double get_earliest_start(double arr_t) const {
        double earliest = available_times[0];
        for (int i = 1; i < slots; ++i) {
            if (available_times[i] < earliest) earliest = available_times[i];
        }
        return max(arr_t, earliest);
    }

    void book_slot(double start_t, double duration) {
        int best_idx = 0;
        double earliest = available_times[0];
        for (int i = 1; i < slots; ++i) {
            if (available_times[i] < earliest) {
                earliest = available_times[i];
                best_idx = i;
            }
        }
        available_times[best_idx] = start_t + duration;
    }
};

struct Intersect {
    double d_in, d_out, t_start, t_end;
};

inline double get_dist(double x1, double y1, double x2, double y2) {
    double dx = x1 - x2;
    double dy = y1 - y2;
    return sqrt(dx * dx + dy * dy);
}

inline void add_wait(vector<Action>& path, double x, double y, double t_arr, double t_dep) {
    if (t_dep > t_arr + 1e-5) {
        path.push_back({"WAIT", x, y, t_dep, {}, ""});
    }
}

void get_intersections(double x1, double y1, double x2, double y2, double cur_t, const vector<NFZ>& nfzs, vector<Intersect>& res) {
    res.clear();
    double L = get_dist(x1, y1, x2, y2);
    if (L < 1e-7) return;

    double l_min_x = min(x1, x2), l_max_x = max(x1, x2);
    double l_min_y = min(y1, y2), l_max_y = max(y1, y2);
    double dx = x2 - x1;
    double dy = y2 - y1;

    for (const auto& nfz : nfzs) {
        if (nfz.t_end <= cur_t) continue; // MASSIVE SPEEDUP: Skip expired NFZs

        if (l_max_x < nfz.bb_min_x - 1e-5 || l_min_x > nfz.bb_max_x + 1e-5 ||
            l_max_y < nfz.bb_min_y - 1e-5 || l_min_y > nfz.bb_max_y + 1e-5) continue;

        double din = -1, dout = -1;
        if (nfz.type == 0) {
            double ux = dx / L, uy = dy / L;
            double vx = x1 - nfz.cx, vy = y1 - nfz.cy;
            double b = 2 * (ux * vx + uy * vy);
            double c = (vx * vx + vy * vy) - nfz.r * nfz.r;
            double delta = b * b - 4 * c;
            
            if (delta >= 0) {
                double sq_delta = sqrt(delta);
                double s1 = (-b - sq_delta) * 0.5;
                double s2 = (-b + sq_delta) * 0.5;
                double s_in = max(0.0, s1), s_out = min(L, s2);
                if (s_in <= s_out + 1e-5) { din = s_in; dout = s_out; }
            }
        } else {
            double u_min = 0.0, u_max = 1.0;
            if (abs(dx) < 1e-7) {
                if (x1 < nfz.min_x - 1e-5 || x1 > nfz.max_x + 1e-5) u_min = 2.0;
            } else {
                double t1 = (nfz.min_x - x1) / dx;
                double t2 = (nfz.max_x - x1) / dx;
                if (t1 > t2) swap(t1, t2);
                u_min = max(u_min, t1);
                u_max = min(u_max, t2);
            }
            if (abs(dy) < 1e-7) {
                if (y1 < nfz.min_y - 1e-5 || y1 > nfz.max_y + 1e-5) u_min = 2.0;
            } else {
                double t1 = (nfz.min_y - y1) / dy;
                double t2 = (nfz.max_y - y1) / dy;
                if (t1 > t2) swap(t1, t2);
                u_min = max(u_min, t1);
                u_max = min(u_max, t2);
            }
            if (u_min <= u_max + 1e-5) {
                din = u_min * L; dout = u_max * L;
            }
        }
        
        if (din >= 0 && din <= dout + 1e-5) {
            res.push_back({din, dout, nfz.t_start, nfz.t_end});
        }
    }
}

double earliest_dep(double x1, double y1, double x2, double y2, double cur_t, const vector<NFZ>& nfzs, vector<Intersect>& shared_inters) {
    get_intersections(x1, y1, x2, y2, cur_t, nfzs, shared_inters);
    if (shared_inters.empty()) return cur_t;
    
    double T = cur_t;
    bool changed = true;
    int attempts = 0;
    while (changed && attempts++ < 15) {
        changed = false;
        for (const auto& in : shared_inters) {
            double e_in = T + in.d_in;
            double e_out = T + in.d_out;
            if (e_in < in.t_end - 1e-5 && e_out > in.t_start + 1e-5) {
                double req = in.t_end - in.d_in + 1e-3;
                if (req > T) { T = req; changed = true; }
            }
        }
    }
    return T;
}

struct TripRes {
    bool valid;
    double final_t;
    double energy;
    vector<Action> acts;
    int st_idx;
    double st_arr, st_start, st_dur;
};

struct StCand { int id; double fin; };

TripRes eval_trip(double start_t, double wX, double wY, const vector<Delivery*>& seq, const vector<NFZ>& nfzs, const vector<Station>& st_state, vector<Intersect>& shared_inters) {
    TripRes res; res.valid = false;
    double t = start_t;
    double cur_w = 0;
    for (auto d : seq) cur_w += d->weight;
    
    double bat = 500.0;
    double cur_x = wX, cur_y = wY;
    vector<Action> path;
    
    vector<string> p_ids;
    for (auto d : seq) p_ids.push_back(d->id);
    path.push_back({"PICKUP", wX, wY, t, p_ids, ""});

    for (auto d : seq) {
        double d_req = earliest_dep(cur_x, cur_y, d->x, d->y, t, nfzs, shared_inters);
        add_wait(path, cur_x, cur_y, t, d_req);
        double d_dist = get_dist(cur_x, cur_y, d->x, d->y);
        t = d_req + d_dist;
        bat -= d_dist * (1.0 + cur_w);
        
        if (bat < -1e-6 || t > d->deadline) return res;
        
        path.push_back({"DELIVER", d->x, d->y, t, {}, d->id});
        cur_w -= d->weight;
        cur_x = d->x; cur_y = d->y;
    }

    double ret_req = earliest_dep(cur_x, cur_y, wX, wY, t, nfzs, shared_inters);
    double ret_dist = get_dist(cur_x, cur_y, wX, wY);
    double ret_arr = ret_req + ret_dist;
    double ret_cost = ret_dist * 1.0;

    if (bat + 1e-6 >= ret_cost) {
        add_wait(path, cur_x, cur_y, t, ret_req);
        path.push_back({"RETURN", wX, wY, ret_arr, {}, ""});
        res.valid = true;
        res.final_t = ret_arr;
        res.energy = (500.0 - bat) + ret_cost;
        res.acts = path;
        res.st_idx = -1;
        return res;
    }

    // Top-2 Station Pre-filtering to avoid evaluating all 50+ stations
    StCand best_sts[2] = {{-1, 1e15}, {-1, 1e15}};
    for (size_t i = 0; i < st_state.size(); ++i) {
        const auto& st = st_state[i];
        double st_dist = get_dist(cur_x, cur_y, st.x, st.y);
        double st_cost = st_dist * 1.0;
        if (bat < st_cost || st.dist_wh > 500.0) continue;
        
        double arr_st = t + st_dist;
        double st_start = st.get_earliest_start(arr_st);
        double c_needed = max(0.0, st.dist_wh - (bat - st_cost));
        double theoretical_fin = st_start + ceil(c_needed / 2.0) + st.dist_wh;
        
        if (theoretical_fin < best_sts[0].fin) {
            best_sts[1] = best_sts[0];
            best_sts[0] = {(int)i, theoretical_fin};
        } else if (theoretical_fin < best_sts[1].fin) {
            best_sts[1] = {(int)i, theoretical_fin};
        }
    }

    double best_st_fin = 1e15;
    int best_st_idx = -1;
    vector<Action> best_st_path;
    double best_st_arr = 0, best_st_st = 0, best_st_dur = 0;

    for (int k = 0; k < 2; ++k) {
        int i = best_sts[k].id;
        if (i == -1) continue;
        
        const auto& st = st_state[i];
        double st_dist = get_dist(cur_x, cur_y, st.x, st.y);
        double st_cost = st_dist * 1.0;

        double st_req = earliest_dep(cur_x, cur_y, st.x, st.y, t, nfzs, shared_inters);
        double arr_st = st_req + st_dist;
        double st_start = st.get_earliest_start(arr_st);
        double c_needed = max(0.0, st.dist_wh - (bat - st_cost));
        double c_time = ceil(c_needed / 2.0);
        double end_c = st_start + c_time;

        double wh_req = earliest_dep(st.x, st.y, wX, wY, end_c, nfzs, shared_inters);
        double arr_wh = wh_req + st.dist_wh;

        if (arr_wh < best_st_fin) {
            best_st_fin = arr_wh;
            best_st_idx = i;
            best_st_arr = arr_st;
            best_st_st = st_start;
            best_st_dur = c_time;
            
            best_st_path = path;
            add_wait(best_st_path, cur_x, cur_y, t, st_req);
            best_st_path.push_back({"CHARGE", st.x, st.y, st_start, {}, ""});
            best_st_path.push_back({"CHARGE_COMPLETE", st.x, st.y, end_c, {}, ""});
            add_wait(best_st_path, st.x, st.y, end_c, wh_req);
            best_st_path.push_back({"RETURN", wX, wY, arr_wh, {}, ""});
        }
    }

    if (best_st_idx != -1) {
        res.valid = true;
        res.final_t = best_st_fin;
        res.energy = (500.0 - bat) + get_dist(cur_x, cur_y, st_state[best_st_idx].x, st_state[best_st_idx].y) + st_state[best_st_idx].dist_wh;
        res.acts = best_st_path;
        res.st_idx = best_st_idx;
        res.st_arr = best_st_arr;
        res.st_start = best_st_st;
        res.st_dur = best_st_dur;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    string input_str((istreambuf_iterator<char>(cin)), istreambuf_iterator<char>());
    Json::Value in_data;
    Json::CharReaderBuilder rb;
    string errs;
    istringstream ss(input_str);
    Json::parseFromStream(rb, ss, &in_data, &errs);

    double wX = in_data["map_size"][0].asDouble() * 0.5;
    double wY = in_data["map_size"][1].asDouble() * 0.5;

    vector<Drone> drones;
    for (const auto& d : in_data["drones"]) {
        Drone dr; dr.id = d["id"].asString(); dr.max_payload = d["max_payload"].asDouble();
        drones.push_back(dr);
    }

    vector<Delivery> dels;
    for (const auto& d : in_data["deliveries"]) {
        Delivery dl; dl.id = d["id"].asString(); dl.x = d["x"].asDouble();
        dl.y = d["y"].asDouble(); dl.weight = d["weight"].asDouble();
        dl.deadline = d["deadline"].asDouble();
        dels.push_back(dl);
    }

    
    vector<NFZ> nfzs;
    for (const auto& n : in_data.get("no_fly_zones", Json::Value(Json::arrayValue))) {
        NFZ nz; nz.t_start = n["T_start"].asDouble(); nz.t_end = n["T_end"].asDouble();
        if (n["shape"].asString() == "circle") {
            nz.type = 0; nz.cx = n["center"][0].asDouble(); nz.cy = n["center"][1].asDouble();
            nz.r = n["radius"].asDouble();
            nz.bb_min_x = nz.cx - nz.r; nz.bb_max_x = nz.cx + nz.r;
            nz.bb_min_y = nz.cy - nz.r; nz.bb_max_y = nz.cy + nz.r;
        } else {
            nz.type = 1; nz.min_x = n["corners"][0][0].asDouble(); nz.min_y = n["corners"][0][1].asDouble();
            nz.max_x = n["corners"][1][0].asDouble(); nz.max_y = n["corners"][1][1].asDouble();
            if (nz.min_x > nz.max_x) swap(nz.min_x, nz.max_x);
            if (nz.min_y > nz.max_y) swap(nz.min_y, nz.max_y);
            nz.bb_min_x = nz.min_x; nz.bb_max_x = nz.max_x;
            nz.bb_min_y = nz.min_y; nz.bb_max_y = nz.max_y;
        }
        nfzs.push_back(nz);
    }
    
    vector<Station> sts;
    for (const auto& s : in_data.get("charging_stations", Json::Value(Json::arrayValue))) {
        Station st; st.x = s["x"].asDouble(); st.y = s["y"].asDouble(); st.slots = s["slots"].asInt();
        st.init(wX, wY); sts.push_back(st);
    }
    sort(dels.begin(), dels.end(), [](const Delivery& a, const Delivery& b) {
        if (abs(a.deadline - b.deadline) > 1e-5) return a.deadline < b.deadline;
        return a.weight > b.weight;
    });

    // sort(dels.begin(), dels.end(), [](const Delivery& a, const Delivery& b) {
    //     return a.deadline < b.deadline;
    // });

    vector<Intersect> shared_inters;
    shared_inters.reserve(200);

    vector<int> dr_order(drones.size());
    iota(dr_order.begin(), dr_order.end(), 0);
    
    for (auto& seed : dels) {
        if (seed.assigned) continue;

        sort(dr_order.begin(), dr_order.end(), [&](int a, int b) {
            return drones[a].current_time < drones[b].current_time;
        });

        bool seed_delivered = false;
        double dist_out = get_dist(wX, wY, seed.x, seed.y);

        for (int dr_idx : dr_order) {
            Drone& dr = drones[dr_idx];
            
            // MATHEMATICAL PRUNING: If the earliest drone fails deadline, ALL drones fail.
            if (dr.current_time + dist_out > seed.deadline) {
                break; 
            }

            if (dr.max_payload < seed.weight) continue;

            vector<pair<double, Delivery*>> cands;
            cands.reserve(400);
            int checked = 0;
            
            for (auto& cand : dels) {
                if (cand.assigned || &cand == &seed) continue;
                if (++checked > 400) break; 
                
                double d_dist = get_dist(seed.x, seed.y, cand.x, cand.y);
                if (d_dist > 80.0) continue; 
                
                // Fast rejection
                if (dr.current_time + dist_out + d_dist > cand.deadline) continue;
                
                cands.push_back({d_dist, &cand});
            }
            sort(cands.begin(), cands.end());

            vector<Delivery*> clus = {&seed};
            double cw = seed.weight;
            for (auto& c : cands) {
                if (clus.size() >= 4) break; // Optimized from 3 to 4
                if (cw + c.second->weight <= dr.max_payload) {
                    clus.push_back(c.second);
                    cw += c.second->weight;
                }
            }

            bool valid_trip = false;
            TripRes b_res;
            vector<Delivery*> b_seq;

            while (clus.size() > 0 && !valid_trip) {
                vector<Delivery*> seq = clus;
                sort(seq.begin(), seq.end(), [](Delivery* a, Delivery* b){ return a->id < b->id; });
                
                b_res.energy = 1e15;
                
                do {
                    TripRes r = eval_trip(dr.current_time, wX, wY, seq, nfzs, sts, shared_inters);
                    if (r.valid && r.energy < b_res.energy) {
                        b_res = r;
                        b_seq = seq;
                        valid_trip = true;
                    }
                } while (next_permutation(seq.begin(), seq.end(), [](Delivery* a, Delivery* b){ return a->id < b->id; }));

                if (valid_trip) {
                    dr.path.insert(dr.path.end(), b_res.acts.begin(), b_res.acts.end());
                    dr.current_time = b_res.final_t;
                    if (b_res.st_idx != -1) {
                        sts[b_res.st_idx].book_slot(b_res.st_start, b_res.st_dur);
                    }
                    for (auto* d : b_seq) d->assigned = true;
                    seed_delivered = true;
                    break;
                } else {
                    clus.pop_back(); 
                }
            }

            if (seed_delivered) break; 
        }

        if (!seed_delivered) {
            seed.fail_count++; // Don't mark as assigned, just increment failure
        }
    }

    Json::Value f_man(Json::arrayValue);
    for (const auto& dr : drones) {
        if (!dr.path.empty()) {
            Json::Value d_ent;
            d_ent["drone_id"] = dr.id;
            Json::Value jp(Json::arrayValue);
            for (const auto& a : dr.path) {
                Json::Value jo;
                jo["action"] = a.type; jo["x"] = a.x; jo["y"] = a.y; jo["t"] = a.t;
                if (a.type == "PICKUP") {
                    Json::Value dids(Json::arrayValue);
                    for (const auto& id : a.delivery_ids) dids.append(id);
                    jo["delivery_ids"] = dids;
                } else if (a.type == "DELIVER") {
                    jo["delivery_id"] = a.delivery_id;
                }
                jp.append(jo);
            }
            d_ent["path"] = jp;
            f_man.append(d_ent);
        }
    }

    Json::Value out; out["flight_manifest"] = f_man;
    Json::StreamWriterBuilder wb; wb["indentation"] = "";
    cout << Json::writeString(wb, out) << "\n";
    return 0;
}
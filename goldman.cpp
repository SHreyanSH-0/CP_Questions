#include <bits/stdc++.h>
using namespace std;

struct User {
    string name;
    int budget;
    int energy;
    set<string> tags;
    bool active = true;
};

struct Activity {
    int id;
    string name;
    int cost;
    int duration;
    int energy;
    string tag;
};

struct Input {
    int N, D, H;
    vector<User> users;
    map<int, Activity> activities;     
    vector<string> events;             
};

static Input readInput() {
    Input in;
    cin >> in.N >> in.D >> in.H;
    in.users.resize(in.N);
    for (int i = 0; i < in.N; i++) {
        int k;
        cin >> in.users[i].name >> in.users[i].budget >> in.users[i].energy >> k;
        for (int j = 0; j < k; j++) {
            string t; cin >> t;
            in.users[i].tags.insert(t);
        }
        in.users[i].active = true;
    }
    
    int A; cin >> A;
    for (int i = 0; i < A; i++) {
        Activity a;
        cin >> a.id >> a.name >> a.cost >> a.duration >> a.energy >> a.tag;
        in.activities[a.id] = a;
    }
    
    int E; 
    if (cin >> E) {
        // Robustly read exactly E non-empty event lines, ignoring trailing/blank lines
        for (int i = 0; i < E; ) {
            string line;
            if (!getline(cin, line)) break;
            
            // Trim whitespace
            int st = 0;
            while (st < line.size() && isspace((unsigned char)line[st])) st++;
            
            if (st < line.size()) {
                int en = line.size() - 1;
                while (en >= st && isspace((unsigned char)line[en])) en--;
                in.events.push_back(line.substr(st, en - st + 1));
                i++;
            }
        }
    }
    return in;
}

/** Format a single day line exactly per spec. Use REST if ids is empty. */
static string formatDay(int day, vector<int> ids, int cost, int sat) {
    if (ids.empty()) {
        return "Day " + to_string(day) + ": REST | cost=0 satisfaction=0";
    }
    sort(ids.begin(), ids.end()); 
    string s = "Day " + to_string(day) + ": ";
    for (size_t i = 0; i < ids.size(); i++) {
        if (i) s += ' ';
        s += to_string(ids[i]);
    }
    s += " | cost=" + to_string(cost) + " satisfaction=" + to_string(sat);
    return s;
}

struct BestPlan {
    int sat = -1;
    int cost = 2e9;
    vector<int> ids;
};

static string solve(Input in) {
    string out;
    out += "=== PLAN ===\n";

    map<int, set<string>> weather_blocks;
    vector<vector<int>> daily_plan(in.D + 1);

    auto plan_from = [&](int start_day) {
        // Safe-clamp start_day to prevent any Out-Of-Bounds bounds trickery 
        start_day = max(1, min(start_day, in.D + 1));

        // Rebuild used_activities strictly from days before start_day
        set<int> used_activities;
        for (int d = 1; d < start_day; d++) {
            for (int id : daily_plan[d]) {
                used_activities.insert(id);
            }
        }

        // Re-plan days [start_day .. D]
        for (int day = start_day; day <= in.D; day++) {
            int min_b = 2e9, min_e = 2e9;
            int active_count = 0;
            
            for (const auto& u : in.users) {
                if (u.active) {
                    min_b = min(min_b, u.budget);
                    min_e = min(min_e, u.energy);
                    active_count++;
                }
            }
            
            // If all users dropped out, no activities can be afforded
            if (active_count == 0) {
                min_b = 0; min_e = 0;
            }

            // Collect eligible activities mapped to this specific day's weather blocks
            vector<Activity> eligible;
            for (const auto& pair : in.activities) {
                const auto& act = pair.second;
                if (used_activities.count(act.id) == 0 && weather_blocks[day].count(act.tag) == 0) {
                    // Quick pre-pruning: remove if the single activity violates limits outright
                    if (act.cost <= min_b && act.energy <= min_e && act.duration <= in.H) {
                        eligible.push_back(act);
                    }
                }
            }

            // Precompute satisfaction for eligible activities for O(1) lookups
            vector<int> act_sat(eligible.size(), 0);
            for (size_t i = 0; i < eligible.size(); i++) {
                for (const auto& u : in.users) {
                    if (u.active && u.tags.count(eligible[i].tag)) {
                        act_sat[i]++;
                    }
                }
            }

            BestPlan best;
            vector<int> cur_ids;

            // DFS optimization traversing activity combinations natively yielding sorted Lexicographical matches
            auto dfs = [&](auto& self, int idx, int cur_cost, int cur_eng, int cur_dur, int cur_sat) -> void {
                bool is_better = false;
                if (cur_sat > best.sat) is_better = true;
                else if (cur_sat == best.sat) {
                    if (cur_cost < best.cost) is_better = true;
                    else if (cur_cost == best.cost) {
                        // std::vector < properly checks Lexicographical bounds as required
                        if (cur_ids < best.ids) is_better = true; 
                    }
                }

                if (is_better) {
                    best.sat = cur_sat;
                    best.cost = cur_cost;
                    best.ids = cur_ids;
                }

                for (int i = idx; i < (int)eligible.size(); i++) {
                    const auto& act = eligible[i];
                    if (cur_cost + act.cost <= min_b &&
                        cur_eng + act.energy <= min_e &&
                        cur_dur + act.duration <= in.H) {

                        cur_ids.push_back(act.id);
                        self(self, i + 1, cur_cost + act.cost, cur_eng + act.energy, cur_dur + act.duration, cur_sat + act_sat[i]);
                        cur_ids.pop_back();
                    }
                }
            };

            // Start DFS with empty subset constraints
            dfs(dfs, 0, 0, 0, 0, 0);

            // Save the determined best state
            daily_plan[day] = best.ids;
            for (int id : best.ids) {
                used_activities.insert(id);
            }

            out += formatDay(day, best.ids, best.cost, max(0, best.sat)) + "\n";
        }
    };

    // 1. Build the initial D-day plan.
    plan_from(1);

    // 2. Process chronological events
    for (size_t i = 0; i < in.events.size(); i++) {
        out += "=== EVENT " + to_string(i + 1) + ": " + in.events[i] + " ===\n";

        stringstream ss(in.events[i]);
        string type;
        int ev_day = 1;
        ss >> type >> ev_day;

        // Apply state mutation 
        if (type == "DROP") {
            string name; ss >> name;
            for (auto& u : in.users) if (u.name == name) u.active = false;
        } else if (type == "WEATHER") {
            string tag; ss >> tag;
            weather_blocks[ev_day].insert(tag);
        } else if (type == "FATIGUE") {
            string name; int amt; ss >> name >> amt;
            // Energy is explicitly SET to this amount, not subtracted
            for (auto& u : in.users) if (u.name == name) u.energy = amt;
        } else if (type == "BUDGET") {
            string name; int nb; ss >> name >> nb;
            for (auto& u : in.users) if (u.name == name) u.budget = nb;
        }

        // Re-plan starting from the day the event occurs
        plan_from(ev_day);
    }

    return out;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Input in = readInput();
    cout << solve(in);
    return 0;
}
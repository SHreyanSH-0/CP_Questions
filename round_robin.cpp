#include <bits/stdc++.h>
using namespace std;
#define int long long

struct Job {
    int id;
    int arrival;
    int burst;
    int remain;
    int complete;
    int turnaround;
    int waiting;
};

int32_t main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    vector<Job> a(n);

    for (int i = 0; i < n; ++i) {
        a[i].id = i + 1;
        cout << "Enter Arrival Time and Burst Time of P" << i + 1 << ": ";
        cin >> a[i].arrival >> a[i].burst;
        a[i].remain = a[i].burst;
    }

    int quantum;
    cout << "Enter Time Quantum: ";
    cin >> quantum;

    sort(a.begin(), a.end(), [](const Job &x, const Job &y) {
        return x.arrival < y.arrival;
    });

    queue<int> ready;
    vector<int> used(n, 0);

    int now = a[0].arrival;
    int done = 0;

    ready.push(0);
    used[0] = 1;

    while (!ready.empty()) {
        int i = ready.front();
        ready.pop();

        if (a[i].remain > quantum) {
            a[i].remain -= quantum;
            now += quantum;
        } else {
            now += a[i].remain;
            a[i].remain = 0;
            a[i].complete = now;
            ++done;
        }

        for (int j = 0; j < n; ++j) {
            if (!used[j] && a[j].arrival <= now && a[j].remain > 0) {
                ready.push(j);
                used[j] = 1;
            }
        }

        if (a[i].remain > 0) {
            ready.push(i);
        }
    }

    double avgT = 0, avgW = 0;

    for (int i = 0; i < n; ++i) {
        a[i].turnaround = a[i].complete - a[i].arrival;
        a[i].waiting = a[i].turnaround - a[i].burst;
        avgT += a[i].turnaround;
        avgW += a[i].waiting;
    }

    avgT /= n;
    avgW /= n;

    cout << "\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for (auto &x : a) {
        cout << "P" << x.id << "\t"
             << x.arrival << "\t"
             << x.burst << "\t"
             << x.complete << "\t"
             << x.turnaround << "\t"
             << x.waiting << "\n";
    }

    cout << "\nAverage Turnaround Time = " << avgT;
    cout << "\nAverage Waiting Time = " << avgW << "\n";

    return 0;
}

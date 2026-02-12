#include <bits/stdc++.h>
using namespace std;

const int N = 4;
int heuristic(vector<int>& board) {
    int attacks = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if (board[i] == board[j])
                attacks++;
            else if (abs(board[i] - board[j]) == abs(i - j))
                attacks++;
        }
    }
    return attacks;
}

void printBoard(vector<int>& board) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[j] == i)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
}

bool hillClimbing() {
    vector<int> current(N);

    for (int i = 0; i < N; i++)
        current[i] = rand() % N;

    while (true) {
        int current_h = heuristic(current);

        if (current_h == 0) {
            cout << "Solution Found:\n";
            printBoard(current);
            return true;
        }

        vector<int> best = current;
        int best_h = current_h;

        for (int col = 0; col < N; col++) {
            for (int row = 0; row < N; row++) {
                if (row == current[col]) continue;

                vector<int> neighbor = current;
                neighbor[col] = row;

                int h = heuristic(neighbor);
                if (h < best_h) {
                    best_h = h;
                    best = neighbor;
                }
            }
        }

        if (best_h >= current_h) {
            cout << "Stuck in local minimum. No solution.\n";
            return false;
        }

        current = best;
    }
}

int main() {
    srand(time(0));
    hillClimbing();
    return 0;
}
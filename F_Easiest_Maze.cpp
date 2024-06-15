#include <bits/stdc++.h>
using namespace std;

void constructMaze(int N, int M, int K) {
    if (K < N || K > N + M - 1) {
        cout << "No" << endl;
        return;
    }

    vector<vector<char>> grid(2 * N + 1, vector<char>(2 * M + 1, '+'));

    // Initialize grid with potential walls
    for (int i = 1; i <= 2 * N; i += 2) {
        for (int j = 1; j <= 2 * M; j += 2) {
            grid[i][j] = 'o';
        }
    }

    // Set path
    int cells = 1;
    int r = 1, c = 2 * M - 1;
    grid[0][c] = 'S'; // Entrance
    grid[2 * N][c] = 'G'; // Exit
    
    while (r < 2 * N && cells < K) {
        grid[r][c] = '.';
        r += 2;
        cells++;
    }
    
    while (cells < K) {
        c -= 2;
        grid[r][c] = '.';
        cells++;
    }

    // Place remaining walls
    for (int i = 1; i <= 2 * N; i += 2) {
        for (int j = 2; j < 2 * M; j += 2) {
            if (grid[i][j] != '.')
                grid[i][j] = '|';
        }
    }
    for (int i = 2; i < 2 * N; i += 2) {
        for (int j = 1; j <= 2 * M; j += 2) {
            if (grid[i][j] != '.')
                grid[i][j] = '-';
        }
    }

    // Output result
    cout << "Yes" << endl;
    for (const auto &row : grid) {
        for (const auto &cell : row) {
            cout << cell;
        }
        cout << endl;
    }
}

int main() {
    int N, M, K;
    cin >> N >> M >> K;

    constructMaze(N, M, K);

    return 0;
}

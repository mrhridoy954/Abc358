#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const int MAX_H = 50;
const int MAX_W = 50;

ll max_fun_value(vector<vector<ll>>& A, int H, int W, ll K, int si, int sj) {
    vector<vector<vector<ll>>> dp(MAX_H, vector<vector<ll>>(MAX_W, vector<ll>(4, LLONG_MIN)));
    vector<vector<vector<ll>>> max_dp(MAX_H, vector<vector<ll>>(MAX_W, vector<ll>(4, LLONG_MIN)));

    auto update = [&](int i, int j, int d, ll value) {
        if (i < 0 || i >= H || j < 0 || j >= W) return;
        if (dp[i][j][d] < value) {
            dp[i][j][d] = value;
        }
    };

    int start_i = si - 1;
    int start_j = sj - 1;
    dp[start_i][start_j][0] = A[start_i][start_j];

    for (int t = 1; t < 4; ++t) {
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                for (int d = 0; d < 4; ++d) {
                    if (dp[i][j][d] == LLONG_MIN) continue;
                    max_dp[i][j][d] = max(max_dp[i][j][d], dp[i][j][d]);
                }
            }
        }
        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                dp[i][j][t] = max_dp[i][j][t];
            }
        }

        for (int i = 0; i < H; ++i) {
            for (int j = 0; j < W; ++j) {
                if (dp[i][j][t] == LLONG_MIN) continue;
                ll current_value = dp[i][j][t];
                update(i - 1, j, t, current_value + A[i][j]);
                update(i + 1, j, t, current_value + A[i][j]);
                update(i, j - 1, t, current_value + A[i][j]);
                update(i, j + 1, t, current_value + A[i][j]);
            }
        }
    }

    ll result = LLONG_MIN;
    for (int t = 0; t < 4; ++t) {
        result = max(result, dp[start_i][start_j][t]);
    }

    if (K <= 3) {
        return result;
    }

    ll max_in_cycle = result;
    vector<vector<ll>> max_value(MAX_H, vector<ll>(MAX_W, LLONG_MIN));

    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            for (int t = 0; t < 4; ++t) {
                max_value[i][j] = max(max_value[i][j], dp[i][j][t]);
            }
        }
    }

    ll sum_per_cycle = 0;
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            sum_per_cycle += max_value[i][j];
        }
    }

    ll full_cycles = (K - 3) / 4;
    ll remainder_moves = (K - 3) % 4;

    ll max_additional_fun = 0;
    for (int i = 0; i < remainder_moves; ++i) {
        for (int j = 0; j < H; ++j) {
            for (int k = 0; k < W; ++k) {
                max_additional_fun = max(max_additional_fun, dp[j][k][i]);
            }
        }
    }

    return max_in_cycle + full_cycles * sum_per_cycle + max_additional_fun;
}

int main() {
    int H, W, si, sj;
    ll K;
    cin >> H >> W >> K >> si >> sj;

    vector<vector<ll>> A(H, vector<ll>(W));
    for (int i = 0; i < H; ++i) {
        for (int j = 0; j < W; ++j) {
            cin >> A[i][j];
        }
    }

    cout << max_fun_value(A, H, W, K, si, sj) << endl;

    return 0;
}

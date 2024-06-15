#include <bits/stdc++.h>
using namespace std;
#define MOD 998244353

int main() {
    int K;
    cin >> K;
    
    vector<int> C(26);
    for (int i = 0; i < 26; ++i) {
        cin >> C[i];
    }
    
    // Initialize DP table
    vector<vector<long long>> dp(K + 1, vector<long long>(27, 0));
    dp[0][0] = 1; // 1 way to make the empty string

    // DP transition
    for (int length = 0; length < K; ++length) {
        for (int char_idx = 0; char_idx < 26; ++char_idx) {
            for (int count = 0; count <= C[char_idx]; ++count) {
                if (length + count <= K) {
                    dp[length + count][char_idx + 1] = (dp[length + count][char_idx + 1] + dp[length][char_idx]) % MOD;
                }
            }
        }
    }
    
    // Sum up all valid strings of length 1 to K
    long long result = 0;
    for (int length = 1; length <= K; ++length) {
        result = (result + dp[length][26]) % MOD;
    }
    
    cout << result << endl;
    return 0;
}

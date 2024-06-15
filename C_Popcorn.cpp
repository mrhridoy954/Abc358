#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<string> stands(N);
    for (int i = 0; i < N; ++i) {
        cin >> stands[i];
    }
    
    int min_stands = N;
    
    for (int subset = 1; subset < (1 << N); ++subset) {
        bitset<10> covered;
        
        for (int i = 0; i < N; ++i) {
            if (subset & (1 << i)) {
                for (int j = 0; j < M; ++j) {
                    if (stands[i][j] == 'o') {
                        covered.set(j);
                    }
                }
            }
        }
        
        if (covered.count() == M) {
            int count = bitset<10>(subset).count();
            min_stands = min(min_stands, count);
        }
    }
    
    cout << min_stands << endl;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main() {
    int N, A;
    cin >> N >> A;
    
    vector<int> T(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i];
    }
    
    int current_time = 0;

    vector<int> result(N);
    
    for (int i = 0; i < N; ++i) {
        if (current_time < T[i]) {
            current_time = T[i]; 
        }
        current_time += A; 
        result[i] = current_time;
    }
    
    for (int i = 0; i < N; ++i) {
        cout << result[i] << endl;
    }
    
    return 0;
}

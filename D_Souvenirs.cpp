#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    
    vector<pair<int, int>> boxes(N);
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        boxes[i] = {A, A};
    }
    
    vector<int> B(M);
    for (int i = 0; i < M; ++i) {
        cin >> B[i];
    }
    
    sort(boxes.begin(), boxes.end());
    sort(B.begin(), B.end());
    priority_queue<int, vector<int>, greater<int>> pq;
    int j = 0;
    long long total_cost = 0;
    
    for (int i = 0; i < M; ++i) {
        while (j < N && boxes[j].first < B[i]) {
            ++j;
        }
        while (j < N && boxes[j].first >= B[i]) {
            pq.push(boxes[j].second);
            ++j;
        }
        if (pq.empty()) {
            cout << -1 << endl;
            return 0;
        }
        total_cost += pq.top();
        pq.pop();
    }
    
    cout << total_cost << endl;
    return 0;
}

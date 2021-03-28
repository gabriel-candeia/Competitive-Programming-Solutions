#include <bits/stdc++.h>

using namespace std;

int main() {
    int n; cin >> n;
    vector<int> arr(n);
    for(auto&a : arr) cin >> a;
    sort(arr.begin(), arr.end());
    int cnt = 0;
    int tmp = 0;
    for(int i = 0; i < n; i++) {
        if(arr[i] <= i) {
            cnt = i+1;
        }
    } // 1 1 4 5 5 5 5 5 5 6
    cout << cnt << '\n';
}
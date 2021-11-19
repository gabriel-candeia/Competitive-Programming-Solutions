#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k; cin >> n >> k;
    vector<array<int, 2>> arr;
    while(n--) {
        int a, b; cin >> a >> b;
        arr.push_back({a, b}); // value, color
    }

    auto aux = arr;

    sort(arr.begin(), arr.end());

    for(int i = 0; i < aux.size(); i++) {
        if(aux[i][1] != arr[i][1]) {
            cout << "N" << endl;
            return 0;
        }
    }

    cout << "Y" << endl;

    return 0;
}
#include <bits/stdc++.h>

using namespace std;

#define endl  '\n'
#define vi  vector<ll>
#define ii  array<int, 2>
#define ll  long long
#define INF (int)1e9

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;

    vi arr(n);
    for(auto& a:arr) cin >> a;
    ll x; cin >> x;
    sort(arr.begin(), arr.end());

    for(int i = 0; i < n-1; i++) {
        x -= (arr.back() - arr[i]);
    }

    if(x%n==0 && x>=0) {
        cout << "Boa Sorte" << endl;
    } else {
        cout << "Sem Sorte" << endl;
    }

    return 0;
}
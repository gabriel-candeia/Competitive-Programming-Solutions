#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, x;
    vector<int> a;
    int mn = 10000, mx = 0;

    cin >> n >> k >> x;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){
        if(k%2==1 && i%2==0){
            a[i]^=x;
        }
        mx = max(mx,a[i]);
        mn = min(mn,a[i]);
    }

    cout << mx << " " << mn << '\n';

    return 0;
}
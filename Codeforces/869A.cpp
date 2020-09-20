#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    vector<int> mp(1<<21+1,false);
    vector<int> x, y;
    int cnt=0;

    cin >> n;
    x.assign(n,0); y.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> x[i];
        mp[x[i]]=1;
    }
    for(int i=0;i<n;i++){
        cin >> y[i];
        mp[y[i]]=1;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cnt+=mp[x[i]^y[j]];
        }
    }

    cout << ((cnt%2==0) ? "Karen" : "Koyomi") <<'\n';

    return 0;
}
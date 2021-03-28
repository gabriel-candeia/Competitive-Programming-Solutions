#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll n, m;
        vector<ll> arr, preff;

        cin >> n >> m;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;

        ll cost=0, mx;
        for(int i=0;i<n;i++){
            cost += arr[i];
            if(i)
                preff.push_back(max(preff.back(),cost));
            else
                preff.push_back(cost);
        }
        mx = preff.back();

        for(int i=0,x;i<m;i++){
            cin >> x;
            ll answ = -1;
            if(mx>=x)
                answ = lower_bound(preff.begin(),preff.end(),x)-preff.begin();
            else if(cost>0){
                ll cycles = (x-mx)/cost;
                x -= cycles*cost;
                while(x>mx){    
                    cycles++;
                    x-=cost;
                }
                int i = lower_bound(preff.begin(),preff.end(),x)-preff.begin();
                answ = cycles*n + i;
            }
            cout << answ << ' ';
        }
        cout<<'\n';
    }
    return 0;
}

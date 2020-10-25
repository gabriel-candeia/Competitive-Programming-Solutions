#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int main(){
    ll n, x, m;
    map<ll,ll> cnt;
    map<ll,ll> seen;

    cin >> n >> x >> m;
    ll i, val=x, sum=0,acm=0;
    for(i=0;i<n && seen[val]==false;i++){
        seen[val] = i+1;
        cnt[val] = sum;
        sum = (sum+val);
        val = (val*val)%m;
    }

    if(i==n){
        cout << sum <<'\n';
    }
    else{
        ll cycle, cycleL, path, pathL;
        path = seen[val]-1;
        pathL = cnt[val];
        cycle = i-path;
        cycleL = sum-pathL;
        
        //cout << cycle << " " << val << '\n';
        sum = pathL + (cycleL)*max((n-path)/cycle,0ll);
        for(i=n-(n-path)%cycle+1;i<=n;i++){
            sum = (sum+val);
            val = (val*val)%m;
        }
        cout << sum <<'\n';
    }



    return 0;
}
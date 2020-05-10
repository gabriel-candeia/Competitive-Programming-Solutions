#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int INF = 1e9;
ll n, m, x;
vector<vector<ll>> a;
vector<ll> c, current;

ll best(int j, ll acm){
    if(j==n){
        for(int i=0;i<m;i++){
            if(current[i]<x){
                return -1;
            }
        }
        return acm;
    }
    ll t1, t2;
    for(int i=0;i<m;i++){
        current[i] += a[j][i];
    }
    t1 = best(j+1,acm+c[j]);

    for(int i=0;i<m;i++){
        current[i] -= a[j][i];
    }
    t2 = best(j+1,acm);
    if(t1==-1 || t2==-1){
        return max(t1,t2);
    }
    return min(t1,t2);
}


int main(){
    

    cin >> n >> m >> x;
    a.assign(n,vector<ll>(m,0));
    c.assign(n,0);
    current.assign(m,0);

    for(int i=0;i<n;i++){
        cin >> c[i];
        for(int j=0;j<m;j++){
            cin >> a[i][j];
        }
    }

    ll answ = best(0,0);
    cout <<  answ << '\n';

    return 0;
}
#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define maxn int(4e5+5)
using namespace std;

int ft[2][maxn];

int lsone(int x){
    return (x&(-x));
}

void update(int k, int r, int v){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[k][r]+=v;
}

int query(int k, int r){
    int sum = 0;
    for(;r;r-=lsone(r))
        sum+=ft[k][r];
    return sum;
}

int query(int k, int l, int r){
    return query(k,r) - query(k,l-1);
}

int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        int n, x, y;
        vector<pair<int,int>> pares;
        map<int,int> compress;

        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x >> y;
            compress[x]; compress[y];
            pares.push_back({x,y});
        }

        int cnt = 0;
        for(auto &p:compress)
            p.second = ++cnt;

        for(auto &p:pares){
            p.first = compress[p.first];
            p.second = compress[p.second];
            update(0,p.first,1);
            update(1,p.second,1);
        }

        int answ = n;
        for(auto &p:pares){
            answ = min(answ,query(1,p.first-1)+query(0,p.second+1,maxn));
        }

        cout << answ <<"\n";

        for(auto &p:pares){
            update(0,p.first,-1);
            update(1,p.second,-1);
        }
    }   

    return 0;
}
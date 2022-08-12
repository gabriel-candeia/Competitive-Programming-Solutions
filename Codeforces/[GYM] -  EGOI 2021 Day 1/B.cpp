#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e6+5)
using namespace std;

int ft[maxn], last[maxn];
int lsone(int x){
    return x&(-x);
}

void update(int r, int v){
    for(;r<maxn;r+=lsone(r)){
        ft[r]+=v;
    }
}

int query(int r){
    if(r<0) return 0;
    int answ = 0;
    for(;r;r-=lsone(r)){
        answ += ft[r];
    }
    return answ;
}

int query(int l, int r){
    if(r<l) return 0;
    return query(r) - query(l-1);
}

int main(){
    int n;
    priority_queue<array<int,3>> pq;

    cin >> n;
    for(int i=1;i<=2*n;i++){
        update(i,1);
        int x;
        cin >> x;
        if(last[x]==0){
            last[x] = i;
        }
        else{        
            pq.push(array<int,3>{-i+last[x],last[x],i});
        }
    }

    ll answ = 0;
    while(pq.size()){
        auto p = pq.top(); pq.pop();
        answ += query(p[1]+1,p[2]-1) + 1;
        update(p[1],-1);
        update(p[2],-1);
    }

    cout << answ <<"\n";

    return 0;
}
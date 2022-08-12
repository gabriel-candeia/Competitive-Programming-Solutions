#include<bits/stdc++.h>
#define ll long long
#define maxn int(2e5+5)
using namespace std;

ll ft[maxn];
int lsone(int x){
    return x&(-x);
}

void update(int r, ll v){
    for(;r<maxn;r+=lsone(r))
        ft[r]+=v;
}

void update(int l, int r, ll v){
    update(l,v);
    update(r+1,-v);
}

ll get(int r){
    if(r==0) return 0;
    ll answ = 0;
    for(;r;r-=lsone(r))
        answ+=ft[r];
    return answ;
}

struct query{
    ll id, op, l, r, x, i, j;

    bool operator<(const query &o){
        if(o.id!=id)
            return id<o.id;
        return op<o.op;
    }
};

int main(){
    int n, m, q;

    cin >> n >> m >> q;
    vector<ll> linha(n+1,0), ultUpdate(n+1,-1);

    int cnt = 0;
    vector<query> arr;
    for(int k=0;k<q;k++){
        int op=0, l=0, r=0, x=0, i=0, j=0;
        cin >> op;
        if(op==1){
            cin >> l >> r >> x;
            arr.push_back({k,op,l,r,x,i,j});
        }
        else if(op==2){
            cin >> i >> x;
            arr.push_back({k,op,l,r,x,i,j});
            ultUpdate[i] = k;
        }
        else{
            cin >> i >> j;
            arr.push_back({k,op,l,cnt,1,i,j});
            arr.push_back({ultUpdate[i],op,l,cnt,-1,i,j});
            cnt++;
        }
    }

    vector<ll> answ(cnt,0);
    sort(arr.begin(),arr.end());
    for(const auto &q:arr){
        //cout << q.id <<"\n";
        if(q.op==1){
            update(q.l,q.r,q.x);
        }
        else if(q.op==2){
            linha[q.i] = q.x;
        }
        else{
            if(q.x==-1)
                answ[q.r] = linha[q.i];
            answ[q.r] += q.x*get(q.j);
        }
    }

    for(int i=0;i<answ.size();i++)
        cout << answ[i] <<"\n";

    return 0;
}
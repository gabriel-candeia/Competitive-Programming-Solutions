#include<bits/stdc++.h>
#define maxn int(2e6+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int ft[maxn];

int lsone(int x){
    return x&(-x);
}

int get(int r){
    int sum = 0;
    for(;r;r-=lsone(r))
        sum += ft[r];
    return sum;
}

void update(int r, int v){
    if(r<=0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]+=v;
}

int bb(int x){
    int l=1, r=maxn-1, med=-1,answ=-1;
    while(l<=r){
        med = l +(r-l)/2;
        if(get(med)>=x){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    return answ;
}

int better(int x){
    int resp = 0;
    for(int k=22;k>=0;k--)
        if(resp+(1<<k)<maxn && ft[resp+(1<<k)]<x)
            x -= ft[resp+(1<<k)], resp += (1<<k);
    return resp+1;
}

int main(){
    fastio();
    int n, q, x;

    cin >> n >> q;
    for(int i=0;i<n;i++){
        cin >> x;
        update(x,1);
    }

    for(int i=0;i<q;i++){
        cin >> x;
        if(x>0) update(x,1);
        else update(better(-x),-1);
    }
    int answ = bb(1);
    if(answ==-1) answ = 0;
    cout << answ <<"\n";
    return 0;
}
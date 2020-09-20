#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;
//using fenwick tree

int ft[maxn], n, arr[maxn], cnt;
map<int,int> compress;

int lsOne(int x){
    return x&(-x);
}

void update(int l, int v){
    if(l==0) return;
    for(;l<maxn;l+=lsOne(l))
        ft[l] = max(ft[l],v);
}

int query(int r){
    int answ = 0;
    for(;r;r-=lsOne(r))
        answ = max(ft[r],answ);
    return answ;
}

int main(){
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
        compress[arr[i]];
    }

    cnt = 0;
    for(auto &p:compress){
        p.second = ++cnt;
    }

    for(int i=0;i<n;i++){
        arr[i] = compress[arr[i]];
        update(arr[i],query(arr[i]-1)+1);
    }

    int answ=0;
    for(int i=0;i<maxn;i++)
        answ = max(answ,ft[i]);
    cout << answ <<'\n';

    return 0;
}
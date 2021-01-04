#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int ft[maxn];

int lsone(int x){
    return x&(-x);
}

void update(int r, int v){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r] = max(v,ft[r]);
}

int get(int r){
    int sum = 0;
    for(;r;r-=lsone(r))
        sum = max(sum,ft[r]);
    return sum;
}

int main(){
    int n, x, y;
    vector<pair<int,int>> arr;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        arr.push_back({y,x});
    }

    sort(arr.begin(),arr.end());

    for(auto p:arr){
        update(p.first,get(p.second-1)+1);
    }
    cout << get(maxn-1) << '\n';
    return 0;
}
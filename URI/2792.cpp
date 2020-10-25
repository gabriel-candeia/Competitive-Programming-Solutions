#include<bits/stdc++.h>
#define maxn int(5e5+5)
using namespace std;

int ft[maxn];

int lsone(int x){
    return x&(-x);
}

void update(int r, int v){
    for(;r<maxn;r+=lsone(r)){
        ft[r] += v;
    }
}

int query(int r){
    int sum =0;
    for(;r;r-=lsone(r)){
        sum += ft[r];
    }
    return sum;
}

int main(){
    int n;
    vector<int> arr;
    
    cin >> n;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        update(arr[i],1);
    }

    for(int i=0;i<n;i++){
        cout << query(arr[i]);
        cout << ((i==n-1) ? "\n" : " ");
        update(arr[i],-1);
    }

    return 0;
}
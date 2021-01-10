#include<bits/stdc++.h>
#define maxn int(4e4)
using namespace std;

int ft[maxn], present[maxn];

int lsone(int x){
    return x&(-x);
}

void update(int r, int v){
    if(r<=0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]+=v;
}

int query(int r){
    int sum = 0;
    for(;r;r-=lsone(r))
        sum+=ft[r];
    return sum;
}

int bb(int x){
    int l=0, r=maxn, med, answ=maxn;
    while(l<=r){
        med = l + (r-l)/2;
        if(query(med)>=x){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    return answ;
}


int main(){
    vector<int> answ;
    for(int i=2;i<maxn;i++)
        update(i,1);
    
    for(int i=bb(1);i<maxn;i=bb(1)){
        answ.push_back(i);
        for(int j=1;j<maxn;j+=(i-1)){
            update(bb(j),-1);
        }
    }

    int n;
    while(cin >> n && n)
        cout << answ[n-1] << "\n";

    return 0;
}
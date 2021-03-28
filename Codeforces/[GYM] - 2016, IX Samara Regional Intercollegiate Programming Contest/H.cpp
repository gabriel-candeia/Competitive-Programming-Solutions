#include<bits/stdc++.h>
using namespace std;
#define maxn 200005

int ft[maxn];

int lsone(int x){
    return x&(-x);
}

void update(int r, int v){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]+=v;
}

int get(int r){
    int sum = 0;
    for(;r;r-=lsone(r))
        sum += ft[r];
    return sum;
}

int bb(int x){
    int l=1, r=maxn-1, med, answ=-1;
    while(l<=r){
        med = l + (r-l)/2;
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

int main(){
    int n;
    
    cin >> n;
    vector<int> answ(n,-1);
    vector<array<int,3>> a(n), b(n);

    for(int i=0;i<n;i++){
        cin >> a[i][0] >> a[i][1]; a[i][2] = i+1;
        b[i][0] = a[i][1], b[i][1] = a[i][0], b[i][2] = a[i][2];
    }

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    for(int i=1, j=0, k=0;i<=n;i++){
        for(;j<n && a[j][0]<=i;j++){
            update(a[j][2],1);
        }
        for(;k<n && b[k][0]<i;k++){
            update(b[k][2],-1);
        }
        answ[i-1] = bb(i);
    }

    for(int i=0;i<n;i++)
        cout << answ[i] << " ";
    cout<<'\n';

    return 0;
}
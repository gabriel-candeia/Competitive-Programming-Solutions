#include<bits/stdc++.h>
#define maxn int(8e5+5)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

const int inf = maxn;
int st[maxn], arr[maxn], dif[maxn];
int n, q, op, x, y;

int build(int p, int l, int r){
    if(l==r)
        return st[p] = dif[l];
    int med = (r+l)/2;
    return st[p] = max(build(2*p,l,med),build(2*p+1,med+1,r));
}

int update(int p, int l, int r, int i, int v){
    if(l==r)
        return st[p] = v;
    int med = l + (r-l)/2;
    if(i<=med)
        return st[p] = max(update(2*p,l,med,i,v),st[2*p+1]);
    return st[p] = max(st[2*p],update(2*p+1,med+1,r,i,v));
}

int get(int p, int l, int r, int i, int j){
    if(r<i || j<l)
        return -1;
    if(i<=l && r<=j)
        return st[p];
    int med = l + (r-l)/2;
    return max(get(2*p,l,med,i,j),get(2*p+1,med+1,r,i,j));
}

int solve(int x, int d){
    int l = 1, r = n-x-1, med, answ=0;

    while(l<=r){
        med = l +(r-l)/2;
        if(get(1,0,n-1,x+1,x+med)<=d){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return x+answ+1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    dif[0] = 0;
    for(int i=1;i<n;i++){
        dif[i] = abs(arr[i]-arr[i-1]);
    }
    build(1,0,n-1);
    
    cin >> q;
    for(int i=0;i<q;i++){
        cin >> op >> x >> y;
        if(op==1){
            x--;
            arr[x] = y;
            if(x){
                dif[x] = abs(arr[x]-arr[x-1]);
                update(1,0,n-1,x,dif[x]);
            }
            if(x+1<n){
                dif[x+1] = abs(arr[x+1]-arr[x]);
                update(1,0,n-1,x+1,dif[x+1]);
            }
        }
        else{
            cout << solve(x-1,y) << '\n';
        }
    }

    return 0;
}

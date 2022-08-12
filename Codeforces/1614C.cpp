#include<bits/stdc++.h>
#define ll long long
#define maxn int(8e5+1)
using namespace std;

int st[maxn], lazy[maxn];
const int mx = (1<<30)-1;
const ll mod = 1e9+7;
ll precomp[maxn];

void push(int p, int l, int r){
    st[p] = st[p]&lazy[p];
    if(l!=r){
        lazy[2*p] = lazy[2*p]&lazy[p];
        lazy[2*p+1] = lazy[2*p+1]&lazy[p];
    }
}

int get(int p, int l, int r, int i){
    push(p,l,r);
    if(l==r)
        return st[p];
    int med = (l+r)/2;
    return ((i<=med) ? get(2*p,l,med,i) : get(2*p+1,med+1,r,i));
}

int update(int p, int l, int r, int i, int j, int v){
    push(p,l,r);
    if(r<i || l>j)
        return st[p];
    if(i<=l && r<=j){
        lazy[p] = lazy[p]&v;
        push(p,l,r);
        return st[p];
    }
    int med = (l+r)/2;
    return st[p] = update(2*p,l,med,i,j,v)&update(2*p+1,med+1,r,i,j,v);
}

int main(){
    int t;
    
    precomp[0] = 1;
    for(int i=1;i<maxn;i++)
        precomp[i] = (precomp[i-1]*2)%mod;

    cin >> t;
    while(t--){
        int n, m, l, r, x;

        cin >> n >> m;

        for(int i=0;i<=min(4*n+1,maxn-1);i++)
            lazy[i] = st[i] = mx;

        for(int i=0;i<m;i++){
            int a, b, x;
            cin >> a >> b >> x;
            update(1,0,n-1,a-1,b-1,x);
        }

        vector<int> arr(n,0);
        for(int i=0;i<n;i++){
            arr[i] = get(1,0,n-1,i);
        }

        vector<int> pot(31,0);
        for(auto &x:arr){
            //cout << x <<" ";
            for(int i=0;i<31;i++,x/=2)
                if(x&1)
                    pot[i]++;
        }//cout<<"\n";

        ll answ = 0;
        for(int i=0;i<=30;i++){
            if(pot[i]){
                ll acm  = (precomp[i]*precomp[n-pot[i]])%mod;
                acm = (acm*precomp[pot[i]-1])%mod;
                answ = (answ + acm)%mod;
            }
        }

        cout << answ <<"\n";
    }

    return 0;
}
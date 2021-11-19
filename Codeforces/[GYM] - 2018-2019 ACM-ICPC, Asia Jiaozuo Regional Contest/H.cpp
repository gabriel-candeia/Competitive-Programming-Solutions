#include<bits/stdc++.h>
#define maxn int(1e6+5)
#define ll long long
using namespace std;

struct suffixArray{
    vector<ll> p, wt, lcp;

    suffixArray(vector<ll> s){
        s.push_back(0);
        ll n = s.size(), N = n;

        vector<ll> compress(s);
        sort(compress.begin(),compress.end());
        unique(compress.begin(),compress.end());

        p.assign(n,0), wt.assign(n,0);
        for(ll i=0;i<n;i++)
            p[i] = i, wt[i] = (lower_bound(compress.begin(),compress.end(),s[i])-compress.begin());
        
        for(ll k=0; k<n; k += ((k) ? 2*k : 1)){
            vector<ll> np(p), nwt(n,0), bucket(N,0);

            for(ll i=0;i<n;i++)
                np[i] = (np[i]-k+n)%n, bucket[wt[np[i]]]++;
            for(ll i=1;i<N;i++)
                bucket[i] += bucket[i-1];
            for(ll i=n-1;i>=0;i--)
                p[--bucket[wt[np[i]]]] = np[i];

            for(ll i=1;i<n;i++)
                nwt[p[i]] = nwt[p[i-1]] + (wt[p[i]]!=wt[p[i-1]] || wt[(p[i]+k)%n]!=wt[(p[i-1]+k)%n]);
            wt = nwt;
        }

        lcp.assign(n,0);
        for(ll i=0, k=0; i<n-1; i++,k=max(k-1,0ll)){
            ll j = p[wt[i]-1];
            while(max(i,j)+k < n && s[i+k]==s[j+k]) k++;
            lcp[wt[j]] = k;
        }
    }
};

int st[maxn], lazy[maxn];
int push(int p, int l, int r){
    if(lazy[p]!=-1)
    st[p] = lazy[p]*(r-l+1);
    if(l!=r){
        lazy[2*p] = lazy[p];
        lazy[2*p+1] = lazy[p];
    }
    lazy[p] = -1;
}

void update(int p, int l, int r, int i, int j, int v){
    if(j<l || r>j){
        return;
    }
    if(i<=l && r<=j){
        lazy[p] = v;
        push(p,l,r);
        return;
    }
    int med = l + (r-l)/2;
    push(p,l,r);
    update(2*p,l,med,i,j,v);
    update(2*p+1,med+1,r,i,j,v);
    st[p] = st[2*p]+st[2*p+1];
}

int get(int p, int l, int r, int i, int j){
    push(p,l,r);
    if(j<l || r>j)
        return 0;
    if(i<=l && r<=j)
        return st[p];
    int med = l + (r-l)/2;
    return get(2*p,l,med,i,j,v) +  get(2*p+1,med+1,r,i,j,v);
}

int main(){
    ll t;
    cin >> t;
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n);
        for(auto &x:arr)
            cin >> x;

        suffixArray sa(arr);
        vector<ll> st; st.push_back(arr.size());
        ll answ = 0;
        
        for(int i=n-1;i>=0;i--){
            

        }
        cout << answ << "\n";
        
        for(ll i=st.size()-1;i>0;i--){
            update(0,arr[st[i]],-arr[st[i]]*(st[i-1]-st[i]));
            update(1,arr[st[i]],-(st[i-1]-st[i]));
        }
    }

    return 0;
}
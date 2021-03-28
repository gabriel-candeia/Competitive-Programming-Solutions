#include<bits/stdc++.h>
#define ll long long
#define maxn int(5e5+5)
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

const ll inf = 1e18;

vector<ll> suffix_array(vector<ll> &arr){
    arr.push_back(-inf);
    int n = arr.size();
    vector<ll> p(n), wt(n);
    map<ll,ll> compress;

    for(auto x:arr)
        compress[x];
    
    int N=0;
    for(auto &p:compress)
        p.second = N++;

    for(int i=0;i<n;i++)
        p[i] = i, wt[i] = compress[arr[i]];
    
    for(int k=0; k<n; k = ((k) ? k<<1 : 1)){
        vector<ll> np(p), nwt(n), cnt(n);

        for(int i=0;i<n;i++)
            np[i] = (np[i]-k+n)%n, cnt[wt[np[i]]]++;
        for(int i=1;i<n;i++)
            cnt[i] += cnt[i-1];
        for(int i=n-1;i>=0;i--)
            p[--cnt[wt[np[i]]]] = np[i];

        nwt[p[0]] = 0;
        for(int i=1;i<n;i++)
            nwt[p[i]] = nwt[p[i-1]] + (wt[p[i]]!=wt[p[i-1]] || wt[(p[i]+k)%n]!=wt[(p[i-1]+k)%n]);
        
        wt = nwt;
    }

    return p;
}

vector<ll> longest_common_preffix(vector<ll> &p, vector<ll> &arr){
    int n = p.size();
    vector<ll> pos(n), lcp(n);

    for(int i=0;i<n;i++)
        pos[p[i]] = i;

    for(int i=0, k=0;i<n-1;i++, k = max(k-1,0)){
        int j = p[pos[i]-1];
        while(max(i,j)+k < arr.size() && arr[i+k]==arr[j+k]) k++;
        lcp[pos[j]] = k;
    }

    return lcp;
}

ll ft[maxn];

ll lsone(ll x){
    return x&(-x);
}

void update(ll r, ll v){
    if(r==0) return;
    for(;r<maxn;r+=lsone(r))
        ft[r]+=v;
}

ll get(ll r){
    ll sum = 0;
    for(;r>0;r-=lsone(r))
        sum += ft[r];
    return sum;
}

ll get(ll l, ll r){
    return max(get(r)-get(l-1),0ll);
}


int main(){
    fastio();
    ll n, l, r;
    vector<ll> arr, sum, sa, lcp;

    cin >> n >> l >> r;
    arr.assign(n,0); sum.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    sum[0] = arr[0];
    for(int i=1;i<n;i++)    
        sum[i] = sum[i-1] + arr[i];
    
    sa = suffix_array(arr);
    lcp = longest_common_preffix(sa,arr);


    ll answ = 0;
    vector<pair<ll,ll>> ord;
    for(ll i=1;i<sa.size();i++)
        ord.push_back({sa[i]+lcp[i],sa[i]});
    sort(ord.rbegin(),ord.rend());

    ll cnt  = 0;
    map<ll,ll> compress;
    for(auto x:sum)
        compress[x];
    for(auto &p:compress)
        p.second = ++cnt;

    int last  = n;
    set<ll> st;
    st.insert(inf); compress[inf] = maxn-1;
    for(auto p:ord){
        ll i = p.first, j = p.second;
        while(i<last)
            update(compress[sum[--last]],1), st.insert(sum[last]);
        
        ll inc = ((j) ? sum[j-1] : 0), lb, ub;
        lb = compress[*(st.lower_bound(inc+l))];
        ub = compress[*(--st.upper_bound(inc+r))];
        //cout << j << " " << i << " " << lb << " " << ub << " " << get(lb,ub) << "\n";
        answ += get(lb,ub);
    }

    cout << answ <<'\n';

    return 0;
}
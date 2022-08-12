#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
#define maxn int(1e6+1)
using namespace std;

const ll mod = 1e9+7;

ll pref[maxn], prefAux[maxn];

ll soma(int l, int r){
    if(l>=r) return 0;
    if(l==-1) return prefAux[r];
    return (prefAux[r]-prefAux[l])%mod;
}

ll get(int l, int r){
    if(l>=r) return 0;
    if(l==-1) return pref[r];
    return (pref[r] - (pref[l]+ (soma(l,r)*(l+1))%mod)%mod)%mod;
}

vector<int> lastGreater(const vector<ll>& arr){
    int n = arr.size();
    vector<int> answ(n,-1);
    stack<int> st;

    for(int i=0;i<n;i++){
        while(st.size() && arr[st.top()]<=arr[i])
            st.pop();
        if(st.size()) answ[i] = st.top();
        st.push(i);
    }
    return answ;
}

int main(){
    fastio();

    int n;
    vector<ll> arr;

    cin >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    ll answ = 0;
    prefAux[0] = arr[0];
    for(int i=1;i<n;i++)
        prefAux[i] = (prefAux[i-1]+arr[i])%mod;
    auto next = lastGreater(arr);
    reverse(next.begin(),next.end());
    for(auto &x:next) x = n-x-1;
    reverse(arr.begin(),arr.end());
    auto last = lastGreater(arr);

    for(int i=0;i<n;i++){
        ll qtdL = i-last[i], qtdR = next[i]-i;
        answ = (answ + (((arr[i]*qtdL)%mod)*qtdR)%mod)%mod;
    }

    for(int iter = 0;iter<2;iter++){
        ll acm = 0;
        for(int i=0;i<n;i++){
            //cout << last[i] << " " <<next[i] <<", ";
            answ = (answ + (get(last[i],i-1)*(next[i]-i))%mod)%mod;
            ll inc = (get(last[i],i-1));
            //cout << inc <<", ";
            acm = (acm + arr[i]*(i+1))%mod;
            pref[i] = acm;
            //cout << pref[i] << " |";
            if(i)
                prefAux[i] = (prefAux[i-1]+arr[i])%mod;
            else
                prefAux[i] = arr[0];
        }
        //cout<<"\n";

        memset(pref,0,sizeof(pref));

        reverse(arr.begin(),arr.end());
        reverse(next.begin(),next.end());
        reverse(last.begin(),last.end());
        for(auto &x:next) x = n-x-1;
        for(auto &x:last) x = n-x-1;
        swap(last,next);
    }

    if(answ<0) answ += mod;
    cout << answ <<"\n";

    return 0;
}
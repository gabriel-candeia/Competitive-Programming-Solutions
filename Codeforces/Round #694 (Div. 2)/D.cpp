#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e6+5)
using namespace std;

int sieve[maxn];
void precomp(){
    for(int i=2;i<maxn;i++){
        if(sieve[i]==0){
            sieve[i] = i;
            for(int j=i;j<maxn;j+=i)
                sieve[j] = i;
        }
    }
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;

    precomp();
    while(t--){
        ll n;
        cin >> n;
        vector<ll> arr(n,0);
        map<ll,ll> mp;
        for(int i=0;i<n;i++)
            cin >> arr[i];

        for(int i=0;i<n;i++){
            ll temp = 1;
            for(ll x=arr[i];x!=1;){
                ll y=sieve[x], acm=0;
                while(x%y==0){
                    x/=y;
                    acm++;
                }
                if(acm%2)
                    temp = temp*y;
            }
            arr[i] =  temp;
            mp[arr[i]]++;
            //cout << arr[i] << " ";
        }//cout<<'\n';

        ll answ1=0, answ2=0;
        for(auto p:mp){
            answ1 = max(answ1,p.second);
        }

        for(auto &p:mp){
            if(p.first!=1 && p.second%2==0){
                mp[1]+=p.second;
                p.second = 0;
            }
        }

        for(auto p:mp){
            answ2 = max(answ2,p.second);
        }

        ll q, w;
        cin >> q;
        while(q--){
            cin >> w;
            if(w==0)
                cout << answ1 << "\n";
            else
                cout << answ2 << "\n";
        }

    }
    return 0;
}
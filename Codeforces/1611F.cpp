#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define LOG 21
#define ll long long
using namespace std;

ll st[maxn][LOG];

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        ll s;
        vector<ll> pref;

        cin >> n >> s;
        pref.assign(n+1,0);
        for(int i=1;i<=n;i++){
            cin >> pref[i];
            pref[i] += pref[i-1];
        }

        pair<int,int> answ = {-1,-1};

        for(int i=n;i>=1;i--){
            st[i][0] = pref[i];
            for(int k=1;k<LOG;k++){
                if(i+(1<<k)<=n){
                    st[i][k] = min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
                }
            }
            ll r=i, x = pref[i-1]-s;
            for(int k=LOG-1;k>=0;k--){
                if(r+(1<<k)<=n && st[r][k]>=x){
                    r+=(1<<k);
                }
            }   
            if(pref[r]<x) r--;
            //cout << i << " " << r << " " << x << "\n";
            if(r-i>=answ.second-answ.first)
                answ = {i,r};
        }
        if(answ.first==-1){
            cout << -1 <<"\n";
        }
        else{
            cout << answ.first << " " << answ.second << "\n";
        }
    }


    return 0;   
}
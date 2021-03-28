#include<bits/stdc++.h>
#define ll long long
#define maxn 21
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

ll f[(1<<maxn)];
// c(n,m) = (!n&m)!=0 par  senão impar

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        ll n, answ;
        vector<ll> arr;

        cin >> n; arr.assign(n,0);
        memset(f,0,sizeof(f));
        for(auto &x:arr)
            cin >> x;

        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++)
            f[arr[i]]++;
        
        for(int i=0;i<maxn;i++)
            for(int mask=0;mask<(1<<maxn);mask++)
                if(mask&(1<<i))
                    f[mask] += f[mask^(1<<i)];

        answ = 0;
        for(int i=0;i<n;i++)
            answ += f[arr[i]];
        
        cout << answ << "\n";
    }

    return 0;
}
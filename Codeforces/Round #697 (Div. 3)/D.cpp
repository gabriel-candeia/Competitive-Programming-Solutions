#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){ 
    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;

        vector<ll> arr(n,0), sum[2];
        for(int i=0;i<n;i++)
            cin >> arr[i];
        
        for(int i=0, x;i<n;i++){
            cin >> x;
            sum[x-1].push_back(arr[i]);
        }

        for(ll i=0;i<2;i++){
            sort(sum[i].begin(),sum[i].end());
            sum[i].push_back(0);
            reverse(sum[i].begin(),sum[i].end());
        }
        
        
        for(ll i=0;i<2;i++)
            for(int j=1;j<sum[i].size();j++)
                sum[i][j] += sum[i][j-1];
        
        ll answ = 1e18; 
        for(ll i=0, j=sum[0].size()-1;i<sum[1].size();i++){
            for(;j>=0 && sum[0][j]+sum[1][i]>=m;j--);
            if(sum[0][j+1]+sum[1][i]>=m && j+1<sum[0].size())
                answ = min(answ,2*i+j+1);
        }

        if(answ==1e18)       
            answ = -1;
        cout << answ << '\n';
    }

    return 0;
}
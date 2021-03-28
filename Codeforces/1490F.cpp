#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        ll n, x;  
        vector<pair<ll,ll>> arr;
        map<ll,ll> mp;

        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x;
            mp[x]++;
        }

        for(auto p:mp)
            arr.push_back({p.second,p.first});

        
        ll total = n, answ = n, smaller=0;
        sort(arr.begin(),arr.end());
        for(int i=0;i<arr.size();i++){
            if(i && arr[i].first != arr[i-1].first)
                for(int j=i-1;j>=0 && arr[i-1].first==arr[j].first;j--)
                    smaller+=arr[j].first;
            total -= arr[i].first;
            answ = min(answ,smaller + total-((ll) arr.size()-i-1)*arr[i].first);
        }

        cout << answ << '\n';
    }

    return 0;
}
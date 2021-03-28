#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        ll a, b, k;
        vector<pair<ll,ll>> arr;
        map<ll,ll> cnt; 
        cin >> a >> b >> k;
        arr.assign(k,{0,0});
        for(int i=0;i<k;i++){
            cin >> arr[i].first;
            cnt[arr[i].first]++;
        }
        for(int i=0;i<k;i++){
            cin >> arr[i].second;
            arr[i].second+=a;
            cnt[arr[i].second]++;
        }


        ll answ = 0;
        for(int i=0;i<k;i++){
            answ += (k-cnt[arr[i].first]-cnt[arr[i].second]+1);
        }
        cout << answ/2 << '\n';
    }

    return 0;
}
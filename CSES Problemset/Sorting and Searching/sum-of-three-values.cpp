#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, x;
    vector<pair<ll,ll>> arr;

    cin >> n >> x;
    arr.assign(n,{0,0});
    int cnt = 0;
    for(auto &x:arr)
        cin >> x.first, x.second = ++cnt;

    sort(arr.begin(),arr.end());
    for(int i=1;i<n-1;i++){ 
        ll target = x-arr[i].first;
        for(int l = 0, r = arr.size()-1;l<i;l++){
            while(r>i && arr[l].first+arr[r].first>target) r--;
            if(r==i) break;
            if(arr[l].first+arr[r].first==target){
                cout << arr[l].second << " " << arr[i].second << " " << arr[r].second <<"\n";
                return 0;
            }
        }
    }

    cout << "IMPOSSIBLE" <<"\n";

    return 0;
}
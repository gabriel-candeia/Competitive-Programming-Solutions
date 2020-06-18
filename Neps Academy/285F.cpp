#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n;
    vector<ll> arr;
    vector<pair<ll,ll>> p;

    cin >> n;
    arr.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> arr[i];
    }
    for(int i=1;i<=n;i++){
        if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
            p.push_back({arr[i],-1});
        }
        else if(arr[i]<arr[i-1] && arr[i]<arr[i+1]){
            p.push_back({arr[i],1});
        }
    }

    sort(p.begin(),p.end());
    ll answ=2, cnt=2;
    for(auto x:p){
        cnt+=x.second;
        answ=max(answ,cnt);
    }

    cout << answ << '\n';

    return 0;
}

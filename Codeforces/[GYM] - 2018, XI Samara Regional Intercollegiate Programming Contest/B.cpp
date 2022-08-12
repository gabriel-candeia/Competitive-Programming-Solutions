#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll area(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
    return (a.first*b.second + b.first*c.second + c.first*a.second - a.second*b.first - b.second*c.first - c.second*a.first);
}

int main(){
    int n;

    vector<pair<ll,ll>> arr;

    cin >> n;
    arr.assign(n,{0,0});
    for(auto &x:arr)
        cin >> x.first >> x.second;


    ll minarea = area(arr[0],arr[(1)%n],arr[(2)%n]);
    for(int i=0;i<n;i++){
        minarea = min(minarea,area(arr[i],arr[(i+1)%n],arr[(i+2)%n]));
    }

    cout << minarea <<"\n";

    return 0;
}
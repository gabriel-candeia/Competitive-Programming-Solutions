#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool teste(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
    return (a.first*b.second + a.second*c.first + b.first*c.second - a.first*c.second - a.second*b.first - b.second*c.first)!=0;
}

int main(){
    int n;
    vector<pair<ll,ll>> a;
    cin >> n;
    for(int i=0;i<n;i++){
        int x, y;
        cin >> x >> y;
        a.push_back({x,y});
        
    }
    
    ll answ = 0;    
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                answ += teste(a[i],a[j],a[k]);
            
    cout << answ <<"\n";
    return 0;
}
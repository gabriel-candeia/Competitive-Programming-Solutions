#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int n, a, d;
    vector<pair<int,int>> p;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a >> d;
        p.push_back({a,d});
    }

    sort(p.begin(),p.end());

    ll time=0, points=0;
    for(auto x:p){
        time+=x.first;
        points+= x.second-time;
    }

    cout << points <<'\n';
    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll bb(ll x){
    ll l=0, r=x, med, answ=-1;
    while(l<=r){
        med = l + (r-l)/2;
        if(med*med<=x){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}

int main(){
    int t, n;
    string s;

    cin >> t;
    while(t--){
        cin >> n;
        ll lim = bb(n);
        vector<pair<int,int>> arr;
        for(int i=n-1;i>3;i--){
            if(i==lim){
                arr.push_back({n,i});
                lim = bb(lim);
            }
            arr.push_back({i,n});
        }
        arr.push_back({3,2});
        arr.push_back({3,2});
        while(arr.size()<n+5)
            arr.push_back({n,2});

        cout << arr.size() <<'\n';
        for(auto p:arr){
            cout << p.first << " " << p.second <<'\n';
        }
    }


    return 0;
}

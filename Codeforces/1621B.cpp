#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<vector<ll>> arr;
        pair<ll,ll> mx = {-1e17,-1}, mn = {1e17,-1}, lg = {-1,-1};

        cin >> n;
        arr.assign(n,vector<ll>(3,0));
        
        for(int i=0;i<n;i++){
            cin >> arr[i][0] >> arr[i][1] >> arr[i][2];
            if(arr[i][1]-arr[i][0]+1 > lg.first || (arr[i][1]-arr[i][0]+1 == lg.first && arr[i][2]<lg.second)){
                lg.first = arr[i][1]-arr[i][0]+1, lg.second = arr[i][2];
            }
            if(arr[i][1] > mx.first || (arr[i][1] == mx.first && arr[i][2]<mx.second)){
                mx.first = arr[i][1], mx.second = arr[i][2];
            }
            if(arr[i][0] < mn.first || (arr[i][0] == mn.first && arr[i][2]<mn.second)){
                mn.first = arr[i][0], mn.second = arr[i][2];
            }
            if(lg.first > mx.first-mn.first+1){
                cout << lg.second <<"\n";
            }
            else if(lg.first < mx.first-mn.first+1){
                cout << mx.second+mn.second <<"\n";
            }
            else{
                cout << min(lg.second,mx.second+mn.second) <<"\n";
            }
        }

    }

    return 0;
}
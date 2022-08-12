#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;

        vector<pair<int,int>> arr;
        arr.assign(n,{0,0});
        for(int i=0;i<n;i++){
            cin >> arr[i].first;
        }
        for(int i=0;i<n;i++){
            cin >> arr[i].second;
        }

        sort(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            if(arr[i].first<=k){
                k+=arr[i].second;
            }
        }

        cout << k <<"\n";

    }
    return 0;
}
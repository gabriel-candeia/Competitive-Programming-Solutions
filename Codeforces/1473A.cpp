#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        vector<int> arr;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        
        sort(arr.begin(),arr.end());
        if(arr[n-1]<=d || arr[0]+arr[1]<=d){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
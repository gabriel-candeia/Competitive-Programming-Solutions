#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, l, r;
        vector<int> arr;
        cin >> n >> l >> r;
        arr.assign(n,0);
        for(auto &x:arr) cin >> x;

        ll answ = 0;
        sort(arr.begin(),arr.end());    
        
        for(int i=0;i<n;i++){
            answ += (upper_bound(arr.begin()+i+1,arr.end(),r-arr[i])-lower_bound(arr.begin()+i+1,arr.end(),l-arr[i]));
            //cout << arr[i] <<" "<< (upper_bound(arr.begin()+i+1,arr.end(),r-arr[i])-lower_bound(arr.begin()+i+1,arr.end(),l-arr[i])) <<"\n";
        }
        cout << answ <<'\n';
    }
    return 0;
}
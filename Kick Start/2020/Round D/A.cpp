#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int t, caso=0;

    cin >> t;
    while(t--){
        int answ = 0, n;
        vector<int> arr;

        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr) cin >> x;

        int mx = -1;
        for(int i=0;i<n;i++){
            answ += (arr[i]>mx && (i==n-1 || arr[i]>arr[i+1]));
            mx = max(arr[i],mx);
        }

        cout << "Case #" << ++caso << ": " << answ <<'\n';
    }

    return 0;
}
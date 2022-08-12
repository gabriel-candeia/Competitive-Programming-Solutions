#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, l, r, k;
        vector<int> arr;

        cin >> n >> l >> r >> k;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        sort(arr.begin(),arr.end());

        int answ = 0;
        for(int i=0;i<n;i++){
            if(arr[i]>=l && arr[i]<=r && arr[i]<=k)
                k-=arr[i], answ++;
        }

        cout << answ <<"\n";

    }

    return 0;
}
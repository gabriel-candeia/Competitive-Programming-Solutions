#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, mn=0, mx=0;
        vector<int> arr;

        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr) cin >> x;

        for(int i=0;i<n;i++) if(arr[i]<arr[mn]) mn = i;
        for(int i=0;i<n;i++) if(arr[i]>arr[mx]) mx = i;

        if(mn>mx) swap(mn,mx);

        int answ = min({(mn+1)+(n-mx),mx+1,n-mn});
        cout << answ <<'\n';

    }

    return 0;
}
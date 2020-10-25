#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        map<int,int> mp;
        int n;
        vector<int> arr;

        cin >> n;
        arr.assign(2*n,0);
        for(auto &x:arr){
            cin >> x;
            if(x==2) x = -1;
        }

        int sum = 0;
        for(int i=0;i<n;i++)
            sum+=arr[i];

        mp[sum] = 0;
        for(int i=n-1;i>=0;i--){
            sum-=arr[i];
            if(mp.find(sum)==mp.end())
                mp[sum] = 2*n;
            mp[sum] = min(mp[sum],n-i);
        }

        sum = 0;
        for(int i=n;i<2*n;i++)
            sum+=arr[i];

        if(mp.find(-sum)==mp.end())
            mp[-sum] = 2*n;

        int total = min(mp[-sum],2*n);
        for(int i=n;i<2*n;i++){
            sum-=arr[i];
            if(mp.find(-sum)==mp.end())
                mp[-sum] = 2*n;
            total = min((i-n+1)+mp[-sum],total);
        }

        cout << total <<'\n';
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int cnt = 0, t;
    cin >> t;
    while(t--){
        int n, k, answ=0;
        vector<int> arr;

        cin >> n >> k;
        arr.assign(n,0);
        for(auto &x : arr)
            cin >> x;


        for(int i=0, j=0;i<=n-k;i++){
            for(j=0;j<k && arr[i+j]==k-j;j++);
            answ += (j==k);
        }

        cout << "Case #" << ++cnt << ": " << answ <<'\n';
    }
    return 0;
};
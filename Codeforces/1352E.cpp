#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    vector<int> arr;

    cin >> t;
    while(t--){
        cin >>  n;

        arr.assign(n+1,0);
        map<int,int> cnt;

        for(int i=1;i<=n;i++){
            cin >> arr[i];
            cnt[arr[i]]++;
        }

        for(int i=1;i<=n;i++){
            arr[i]+=arr[i-1];
        }

        int answ=0;
        for(int l=1;l<=n;l++){
            for(int r=l+1;r<=n;r++){
                if(cnt.find(arr[r]-arr[l-1])!=cnt.end()){
                    answ+=cnt[arr[r]-arr[l-1]];
                    cnt.erase(arr[r]-arr[l-1]);
                }
            }
        }
        cout << answ << '\n';
    }

    return 0;
}
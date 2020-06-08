#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    vector<int> arr;

    cin >> t;
    while(t--){
        cin >> n;
        arr.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        vector<int> cnt(1500,0);
        vector<bool> seen(1500,false);
        for(int i=0;i<n;i++){
            seen.assign(1500,false);
            for(int j=0;j<n;j++){
                if(!seen[arr[i]^arr[j]]){
                    cnt[arr[i]^arr[j]]++;
                    seen[arr[i]^arr[j]] = true;
                }
            }
        }

        int answ = -1;
        for(int i=1;i<=1024;i++){
            if(cnt[i]==n){
                answ = i;
                break;
            }
        }

        cout << answ << '\n';

    }

    return 0;
}
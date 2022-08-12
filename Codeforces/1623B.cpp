#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<vector<int>> freq;
        vector<pair<int,int>> arr;

        cin >> n;
        arr.assign(n,{0,0});
        freq.assign(n+1,vector<int>(n+1,0));
        for(int i=0;i<n;i++){
            cin >> arr[i].first >> arr[i].second;
            freq[arr[i].first][arr[i].second]++;
        }

        for(int i=0;i<n;i++){
            for(int k=arr[i].first;k<=arr[i].second;k++){
                bool ok = true;
                if(k!=arr[i].first){
                    ok = ok && freq[arr[i].first][k-1];
                }
                if(k!=arr[i].second){
                    ok = ok && freq[k+1][arr[i].second];
                }
                if(ok){
                    cout << arr[i].first << " " << arr[i].second << " " << k <<"\n";
                    break;
                }
            }
        }
        cout << '\n';
    }

    return 0;
}
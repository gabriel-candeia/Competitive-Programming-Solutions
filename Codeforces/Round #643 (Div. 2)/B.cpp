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
        sort(arr.begin(),arr.end());
        int grupo=0, cnt=0;
        for(int i=0;i<n;i++){
            grupo++;
            if(arr[i]==grupo){
                cnt++;
                grupo=0;
            }
        }
        cout << cnt << '\n';

    }

    return 0;
}
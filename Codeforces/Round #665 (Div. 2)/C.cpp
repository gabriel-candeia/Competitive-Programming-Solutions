#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> arr(n,0), cpy(n,0);
        int mn = 1e9;
        for(int i=0;i<n;i++){
            cin >> arr[i];
            cpy[i] = arr[i];
            mn = min(arr[i],mn);

        }
        sort(cpy.begin(),cpy.end());
        bool poss=true;
        for(int i=0;i<n;i++){
            if(arr[i]%mn!=0 && arr[i]!=cpy[i]){
                poss = false;
            }
        }

        if(poss){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }


    return 0;
}
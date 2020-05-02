#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k, x;

    cin >> t;
    while(t--){
        map<int,bool> seen;
        vector<int> arr;

        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> x;
            if(!seen[x]){
                seen[x] = true;
                arr.push_back(x);
            }
        }

        if(arr.size()>k){
            cout << -1 << '\n';
        }
        else{
            cout << n*k << '\n';
            for(int i=0;i<n;i++){
                for(int j=0;j<k;j++){
                    cout << arr[j%arr.size()] << ' ';
                }   
            }
            cout << '\n';
        }

    }

    return 0;
}
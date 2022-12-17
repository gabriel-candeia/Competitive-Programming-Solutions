#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, k;
        vector<int> arr;

        cin >> n >> k;
        arr.assign(n,0);

        for(auto &x:arr)
            cin >> x;

        bool answ = *max_element(arr.begin(),arr.end());

        cout << ((answ) ? "YES" : "NO") <<"\n";
    }

    return 0;
}
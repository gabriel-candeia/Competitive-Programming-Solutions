#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        cout << ((arr[0]==1)  ? "Yes" : "No") <<"\n";
    }

    return 0;
}
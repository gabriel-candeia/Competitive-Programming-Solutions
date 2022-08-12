#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<int> arr;

        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x;
        sort(arr.rbegin(),arr.rend());
        cout << arr[0]+arr[1] <<"\n";
    }

    return 0;
}
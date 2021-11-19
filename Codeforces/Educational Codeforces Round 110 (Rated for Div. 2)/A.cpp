#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        vector<int> arr(4,0);
        for(auto &x:arr) cin >> x;

        int a = max(arr[0],arr[1]), b = max(arr[2],arr[3]);
        if(a<b) swap(a,b);

        sort(arr.rbegin(),arr.rend());
        if(arr[0]!=a || arr[1]!=b)
            cout <<"NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
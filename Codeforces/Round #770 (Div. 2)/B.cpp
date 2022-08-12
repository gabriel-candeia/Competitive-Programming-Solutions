#include<bits/stdc++.h>
#define int long long 
using namespace std;

int32_t main(){
    int t;

    cin >> t;
    while(t--){
        int n, x, y, sum=0;
        vector<int> arr;
        cin >> n >> x >> y;
        arr.assign(n,0);
        for(auto &x:arr)
            cin >> x, sum = (sum^x)&1;

        
        if((sum^x)%2 == y%2){
            cout << "Alice\n";
        }
        else{
            cout << "Bob\n";
        }
    }


    return 0;
}
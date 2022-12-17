#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n,0);
        for(auto &x:arr)
            cin >> x;
        cout << 1 << " " << n <<"\n";
    }

    return 0;
}
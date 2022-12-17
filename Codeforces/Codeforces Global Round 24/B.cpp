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

        sort(arr.begin(),arr.end());

        bool ok = true;
        for(auto x:arr){
            if(x%arr[0]!=0)
                ok = false;
        }

        if(ok==false){
            cout << arr.back() <<"\n";
        }
        else{
            cout << arr.back()/arr[0] <<"\n";
        }
    }

    return 0;
}
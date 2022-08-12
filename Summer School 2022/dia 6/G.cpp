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

        bool ok = true;
        vector<int> preff, suff;
        preff.push_back(arr[0]), suff.push_back(0);
        for(int i=1;i<n;i++){
            int x = min(preff[i-1],arr[i]-suff[i-1]);
            if(x<0)
                ok = false;
            preff.push_back(x);
            suff.push_back(arr[i]-x);
        }

        /*for(auto x:preff)
            cout << x << " ";
        cout<<"\n";

        for(auto x:suff)
            cout << x << " ";
        cout<<"\n";*/

        cout << ((ok) ? "YES" : "NO") <<"\n";
        
        
    }


    return 0;
}
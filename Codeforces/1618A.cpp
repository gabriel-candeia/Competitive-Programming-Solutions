#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        vector<int> arr(7,0), answ(3,0);

        for(auto &x:arr)
            cin >> x;
        
        answ[0] = arr[0]; 
        answ[1] = arr[1];
        answ[2] = ((arr[2]!=arr[0]+arr[1]) ? arr[2] : arr[3]);

        for(auto x:answ)
            cout << x << " " ;
        cout<<"\n";

    }
    return 0;
}
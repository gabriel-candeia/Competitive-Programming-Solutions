#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        vector<ll> arr, c;
        ll n, y;
        cin >> n >> y;
        arr.assign(n,0);
        c.assign(y,0);

        for(auto &x:arr){
            cin >> x;   
            x--;
        }

        for(auto &x:c)
            cin >> x;  

        ll answ=0, ptr=0;
        sort(arr.begin(),arr.end());

        for(int i=n-1;i>=0;i--){
            if(ptr>=arr[i]){
                answ+=c[arr[i]];
            }
            else{
                answ+=c[ptr++];
            }
        }
    
        cout << answ << "\n";

    }

    return 0;
}
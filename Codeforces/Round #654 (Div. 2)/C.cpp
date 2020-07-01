#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){
    ll t, a, b, n, m;

    cin >> t;
    while(t--){
        cin >> a >> b >> n >> m;
        if(min(a,b)==0 && m!=0){
            cout << "No";
        }
        else if(a+b>=n+m && (min(a,b)>=m)){
            cout << "Yes";
        }
        else{
            cout << "No";
        }
        cout << '\n';
    }


    return 0;
}
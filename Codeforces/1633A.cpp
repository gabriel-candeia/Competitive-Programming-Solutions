#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, r;
        cin >> n;

        r = n%7;
        if(n%10>=r){
            cout << n-r <<"\n";
        }
        else{
            cout << n+(7-r) <<"\n";
        }
    }
    return 0;
}
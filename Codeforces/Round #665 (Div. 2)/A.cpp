#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;

    cin >> t;
    while(t--){
        int n, k;
        cin >> n >> k;
        if(n>k){
            cout << (n%2!=k%2) <<'\n';
        }
        else{
            cout << k-n << '\n';
        }
    }

    return 0;
}
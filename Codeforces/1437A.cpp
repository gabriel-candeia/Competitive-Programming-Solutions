#include<bits/stdc++.h>
using namespace std;

int ceil(int a, int b){
    return a/b + (a%b!=0);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        int l, r;
        cin >> l >> r;
        if(l>=ceil(r+1,2)){
            cout << "YES\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
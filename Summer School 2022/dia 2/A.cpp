#include <bits/stdc++.h>

using namespace std;

int main(){
    int T; cin >> T;
    while(T--){
        int n; cin >> n;
        if(n<=5){
            cout << "-1" <<"\n";
        }
        else if((n-2)%2 ==0 && (n-2) != 2 && (n-2) != 1){
            cout << "2 " << n-2 << "\n";
        }
        else if((n-3)%2 ==0 && (n-3) != 2 && (n-3) != 1){
            cout << 3 << " " << n-3 <<"\n";
        }else{
            cout << "-1\n";
        }
    }
    return 0;
}
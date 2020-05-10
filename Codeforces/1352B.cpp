#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        if(n<k){
            cout << "NO\n";
        }
        else if((n-(k-1))%2==1 && n-(k-1)>0){
            cout << "YES\n";
            cout << n-(k-1) << ' ';
            for(int i=1;i<k;i++){
                cout << 1 << ' ';
            }
            cout << "\n";
        }
        else if((n-2*(k-1))%2==0 && n-2*(k-1)>0){
            cout << "YES\n";
            cout << n-2*(k-1) << ' ';
            for(int i=1;i<k;i++){
                cout << 2 << ' ';
            }
            cout << "\n";
        }
        else{
            cout << "NO\n";
        }
    }

    return 0;
}
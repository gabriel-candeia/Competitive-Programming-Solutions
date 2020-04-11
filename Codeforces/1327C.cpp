#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, k;
    int mx=0, my=0, t;
    string answ = "";

    cin >> n >> m >> k;
    while(k--){
        cin >> t;
        mx = max(mx,t);
        cin >> t;
        my = max(my,t);
        cin >> t >> t;
    }

    cout << m*n+mx+my-3 <<'\n';
    for(int i=1;i<mx;i++){
        cout << "U";
    }
    for(int i=1;i<my;i++){
        cout << "L";
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<m;j++){
            cout << ((i%2) ? "R" : "L");
        }
        if(i!=n) cout << "D";
    }
    cout << '\n';
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x, y;

    cin >> t;
    while(t--){
        cin >> n;
        x = 0;
        y = 0;

        while(n%2==0){
            x++;
            n/=2;
        }
        
        while(n%3==0){
            y++;
            n/=3;
        }

        if(n==1 && x<=y){
            cout << 2*y-x << '\n';
        }
        else{
            cout << -1 << '\n';
        }
    }

    return 0;
}
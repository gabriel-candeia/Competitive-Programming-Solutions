#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, t;
    
    cin >> t;
    while(t--){
        cin >> n;
        int pow = 1;
        vector<int> answ;
        while(n){
            if(n%10){
                answ.push_back((n%10)*pow);
            }
            pow*=10;
            n/=10;
        }
        cout << answ.size() << '\n';
        for(auto x:answ){
            cout << x << ' ';
        }
        cout << '\n';
    }
    return 0;
}
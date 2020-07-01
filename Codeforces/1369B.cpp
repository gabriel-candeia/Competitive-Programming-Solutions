#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int t, n;
    string s;

    cin >> t;
    while(t--){
        cin >> n >> s;
        int zero=0, ones=0;
        while(s[zero]=='0'){
            zero++;
        }
        while(s[n-ones-1]=='1'){
            ones++;
        }
        if(zero+ones!=n){
            zero++;
        }
        cout << string(zero,'0')+string(ones,'1') << '\n';
    }

    return 0;
}
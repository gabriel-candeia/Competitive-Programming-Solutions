#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int acm = (s[0]-'0')*10 + (s[2]-'0');

        int a = ((500-acm*6)/4);

        cout << a/10 << "." << a%10 <<"\n";
        
    }

    return 0;
}
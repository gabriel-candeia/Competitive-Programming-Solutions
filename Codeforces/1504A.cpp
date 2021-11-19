#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int t;
    cin >> t;
    while(t--){
        string s;
        int pos = 0;
        cin >> s;
        for(pos=0;pos<s.size() && s[pos]=='a';pos++);
        if(pos==s.size())
            cout << "NO\n";
        else{
            cout << "YES\n";
            cout << s.substr(0,s.size()-pos) + "a" + s.substr(s.size()-pos) << "\n";
        }
    }


    return 0;
}
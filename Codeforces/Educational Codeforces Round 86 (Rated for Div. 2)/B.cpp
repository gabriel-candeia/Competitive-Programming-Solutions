#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;
    bool mixed;

    cin >> t;
    while(t--){
        mixed = false;
        cin >> s;
        for(int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){
                mixed = true;
                break;
            }
        }

        if(!mixed || s.size()<=2){
            cout << s << '\n';
        }
        else{
            for(int i=0;i<s.size();i++){
                cout << "01";
            }
            cout << '\n';
        }
    }
}
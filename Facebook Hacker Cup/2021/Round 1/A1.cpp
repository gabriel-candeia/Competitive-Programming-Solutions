#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

int main(){
    int t;
    int caso = 0;

    cin >> t;
    while(t--){
        int n;
        char last = '.';
        string s;

        cin >> n >> s;
        
        ll answ = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='O' || s[i]=='X'){
                answ += (last!='.' && last!=s[i]);
                last = s[i];
            }
        }
        
        cout << "Case #" << ++caso << ": " << answ <<"\n";

    }

    return 0;
}
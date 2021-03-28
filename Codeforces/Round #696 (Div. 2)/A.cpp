#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s, asnw = "1";

        cin >> n >> s;
        for(int i=1;i<s.size();i++){
            if(asnw[i-1]+s[i-1] == s[i]+'1'){
                asnw.push_back('0');
            }
            else{
                asnw.push_back('1');
            }
        }
        cout << asnw <<'\n';

    }

    return 0;
}
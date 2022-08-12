#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s, answ;
        cin >>n >>  s;
        answ = string(1,s[0]);
        for(int i=1;i<n && (s[i]<s[i-1] || (s[i]==s[i-1] && s[i]<s[0]));i++){
            answ += s[i];
        }

        cout << answ;
        reverse(answ.begin(),answ.end());
        cout << answ << "\n";
    }


    return 0;
}
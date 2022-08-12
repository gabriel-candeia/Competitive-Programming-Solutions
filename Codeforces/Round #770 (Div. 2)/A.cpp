#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, k;
        string s, t;
        cin >> n >> k;
        cin >> s;
        t = string(s.rbegin(),s.rend());

        int answ = 0;
        if(k==0 || s==t){
            answ = 1;
        }
        else{
            answ = 2;
        }

        cout << answ <<"\n";

    }

    return 0;
}
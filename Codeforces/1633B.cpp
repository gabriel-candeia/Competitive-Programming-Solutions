#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;

        cin >> s;
        n = s.size();

        int cnt = 0;
        for(auto &c:s)
            cnt += c=='0';

        int answ = 0;
        if(n%2){
            answ = min(cnt,n-cnt);
        }
        else{
            if(cnt!=n-cnt){
                answ = min(cnt,n-cnt);
            }
            else{
                answ = min(cnt-1,n-cnt+1);
            }
        }
        cout << answ <<"\n";
    }


    return 0;
}
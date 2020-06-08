#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;

        int last[3], answ = s.size()+2;
        last[0] = -1;
        last[1] = -1;
        last[2] = -1;

        for(int i=0;i<s.size();i++){
            last[s[i]-'1'] = i;
            int l = min({last[0],last[1],last[2]}), r = max({last[0],last[1],last[2]});
            if(l!=-1){
                answ = min(answ,r-l+1);
            }
        }

        if(answ==s.size()+2){
            answ = 0;
        }

        cout << answ <<'\n';
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    int n, m, pos, answ = 0;
    vector<int> rg;

    cin >> s >> t;
    n = s.size(); m = t.size();
    rg.assign(m+1,0);

    pos = m-1;
    rg[m] = n;
    for(int i=n-1;i>=0;i--){
        if(pos>=0 && s[i]==t[pos]){
            rg[pos--] = i;
        }
    }

    pos = 0;
    for(int i=0;i<n;i++){
        if(pos<=m){
            answ = max(answ,rg[pos]-i);
            pos +=(s[i]==t[pos]);
        }
    }

    cout << answ << '\n';

    return 0;
}
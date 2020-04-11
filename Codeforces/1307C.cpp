#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s;
    ll cnt1[26], cnt2[26][26], answ=0;

    for(int i=0;i<26;i++){
        cnt1[i] = 0;
        for(int j=0;j<26;j++){
            cnt2[i][j] = 0;
        }
    }

    cin  >> s;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<26;j++){
            cnt2[j][s[i]-'a'] += cnt1[j];
            answ = max(answ,cnt2[j][s[i]-'a']);
        }
        cnt1[s[i]-'a']++;
        answ = max(answ,cnt1[s[i]-'a']);
    }

    cout << answ << '\n';

    return 0;
}
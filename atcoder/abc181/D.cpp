#include<bits/stdc++.h>
using namespace std;
int cnt[11];

int ok(int x){
    vector<int> digits(11,0);
    while(x){
        digits[x%10]++;
        x/=10;
    }

    bool poss = true;
    for(int i=0;i<=9;i++)
        poss = poss && (digits[i]<=cnt[i]);

    return poss;
}

int main(){
    string s;
    cin >> s;
    for(auto c:s)
        cnt[c-'0']++;

    bool poss = false;
    for(int i=(s.size()==1) ? 8 : (s.size()==2) ? 16 : 104;i<=1000;i+=8){
        poss = poss || ok(i);
    }

    cout << ((poss) ? "Yes" : "No") << '\n';

    return 0;
}
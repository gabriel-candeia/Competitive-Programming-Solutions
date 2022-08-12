#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    vector<int> pref;
    int answ, n;

    cin >> s;
    n = s.size(), answ = n;

    pref.assign(n,0);
    pref[0] = (s[0]=='1');
    for(int i=1;i<n;i++)
        pref[i] = pref[i-1] + (s[i]=='1');
    pref.push_back(pref.back());
    for(int i=0;i<=n;i++){
        for(int j=i;j<=n;j++){
            int val = ((j!=0) ? pref[j-1] : 0) - pref[i];
            if(j-1<i+1) val = 0;
            if(val == max(j-i-1,0)){
                int temp = ((i!=0) ? pref[i-1] : 0) + pref[n-1] - ((j!=0) ? pref[j-1] : 0);
                answ = min(answ,temp);
            }
        }
    }

    cout << answ <<"\n";

    return 0;
}
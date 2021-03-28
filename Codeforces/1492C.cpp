#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    string s, t;

    cin >> n >> m >> s >> t;

    vector<int> preff(m,0), suff(m,0);
    for(int i=0, j=0;i<n && j<m;i++)
        if(s[i]==t[j])
            preff[j++] = i;
    
    for(int i=n-1, j=m-1;i>=0 && j>=0;i--)
        if(s[i]==t[j])
            suff[j--] = i;
    
    int answ = 1;
    for(int i=0;i<m-1;i++)
        answ = max(answ,suff[i+1]-preff[i]);
    
    cout << answ <<'\n';

    return 0;
}
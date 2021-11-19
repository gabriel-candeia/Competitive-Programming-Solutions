#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, q;
    string s, t;
    

    cin >> n >> k >> q;
    cin >> t >> s;

    bitset<2049> mp;
    mp = bitset<2049>(t);
    for(int i=0;i<q;i++){
        t = "";
        for(int j=0;j<n;j++){
            int temp = ((s[j]-'0')<<k);
            for(int len=1;len<=k;len++)
                temp+=((s[(j-len+n)%n]-'0')<<(len+k)) + ((s[(j+len+n)%n]-'0')<<(k-len));
            t.push_back(mp[temp]+'0');
        }
        s = t;
    }

    cout << s <<'\n';

    return 0;
}
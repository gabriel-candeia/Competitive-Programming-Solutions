#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    vector<string> cols(m,"");

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            cols[j].push_back(c);
        }
    }

    map<string,int> mp;
    for(auto c:cols)
        mp[c]++;

    cols.assign(m,"");
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            char c;
            cin >> c;
            cols[j].push_back(c);
        }
    }

    for(auto c:cols)
        mp[c]--;

    bool ok = true;
    for(auto x:mp)
        if(x.second!=0)
            ok = false;

    cout << ((ok) ? "Yes" : "No") <<"\n";


    return 0;
}
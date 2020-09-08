#include<bits/stdc++.h>
using namespace std;


int main(){
    map<string,string> mp;
    int n, m;
    string op, ip;

    cin >> n >> m;
    while(n--){
        cin >> op >> ip;
        mp[ip+";"] = "#"+op;
    }

    while(m--){
        cin >> op >> ip;
        cout << op+" "+ip+" "+mp[ip] << '\n';
    }

    return 0;
}
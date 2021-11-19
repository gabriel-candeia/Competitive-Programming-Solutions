#include<bits/stdc++.h>
using namespace std;

map<string,string> mp;
bool match(string s, string sufixo){
    if(s.size()<sufixo.size()) return false;
    for(int i=0;i<sufixo.size();i++)
        if(s[s.size()-1-i]!=sufixo[sufixo.size()-1-i])
            return false;
    return true;
}

int main(){
    int t;
    string s;

    mp["imasu"] = "tte";
    mp["chimasu"] ="tte";
    mp["rimasu"] = "tte";
    mp["mimasu"] = "nde";
    mp["bimasu"] = "nde";
    mp["nimasu"] = "nde";
    mp["kimasu"] = "ite";
    mp["gimasu"] = "ide";
    mp["shimasu"] = "shite";

    cin >> t;
    while(t--){
        cin >> s;

        int sz = 0;
        string suff = "";
        for(auto p:mp){
            if(match(s,p.first) && p.first.size() > sz){
                sz = p.first.size();
                suff = p.second;
            }
        }
        if(s=="ikimasu")
            cout << "itte" << "\n";
        else
            cout << s.substr(0,s.size()-sz) + suff  << "\n";
    }

    return 0;
}
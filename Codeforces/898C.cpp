#include<bits/stdc++.h>
using namespace std;

bool ehsufixo(string s, string t){
    int n1 = s.size()-1, n2 = t.size()-1;
    if(n1>n2)
        return false;
    while(n1>=0 && s[n1]==t[n2]){
        n1--;
        n2--;
    }
    return n1==-1;
}

int main(){
    int n, m;
    string s, s1;
    map<string,set<string>> mp;

    cin >> n;
    while(n--){
        cin >> s >> m;
        while(m--){
            cin >> s1;
            mp[s].insert(s1);
        }
    }

    cout << mp.size() << '\n';
    for(auto p:mp){
        vector<string> answ;
        for(auto s1:p.second){
            int coloca = 0;
            for(auto s2:p.second){
                if(ehsufixo(s1,s2)){
                    coloca++;
                }
            }
            if(coloca==1)
                answ.push_back(s1);
        }
        cout << p.first << " " << answ.size() << " ";
        for(auto s:answ)
            cout << s <<  " ";
        cout <<'\n';
    }



    return 0;
}
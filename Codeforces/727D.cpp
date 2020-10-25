#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, ptr;
    string s, a, b;
    map<string,int>  mp;
    map<int,string> rv;
    vector<int> cnt(6,0);
    vector<tuple<int,int,int>> p;
    vector<string> camisa;
    mp["S"] = 0; mp["M"] = 1; mp["L"] = 2; mp["XL"] = 3; mp["XXL"] = 4; mp["XXXL"] = 5;
    rv[0] = "S"; rv[1] = "M"; rv[2] = "L"; rv[3] = "XL"; rv[4] = "XXL"; rv[5] = "XXXL";

    for(int i=0;i<6;i++)
        cin >> cnt[i];

    cin >> n;
    camisa.assign(n,"");
    for(int i=0;i<n;i++){
        cin >> s;
        
        for(ptr=0;ptr < s.size() && s[ptr]!=',';ptr++);

        if(ptr!=s.size()){
            a = s.substr(0,ptr);
            b = s.substr(ptr+1,s.size());
            p.push_back({min(mp[a],mp[b]),max(mp[a],mp[b]),i});
        }
        else{
            cnt[mp[s]]--;
            camisa[i] = s;
        }
    }

    sort(p.begin(),p.end());

    int f, sec, id;
    for(auto x:p){
        tie(f, sec, id) = x;
        if(cnt[f]>0){
            cnt[f]--;
            camisa[id] = rv[f];
        }
        else{
            cnt[sec]--;
            camisa[id] = rv[sec];
        }
    }

    bool poss = true;
    for(int i=0;i<6;i++){
        if(cnt[i]<0)
            poss = false;
    }
    
    cout << ((poss) ? "YES" : "NO" ) << '\n';

    if(poss){
        for(int i=0;i<n;i++){
            cout << camisa[i] << '\n';
        }
    }   

    return 0;
}
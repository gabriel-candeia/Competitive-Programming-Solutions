#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll ptr;
vector<string> s(3);
vector<ll> mp(200,-1), num;

bool testa(vector<ll> &p){
    num.assign(3,0);

    for(int i=0;i<s.size();i++){
        if(p[mp[s[i][0]]]==0) return false;
        for(auto c:s[i]) num[i] = 10*num[i] + p[mp[c]];
    }   
    return (num[0]+num[1]==num[2]);
}

int main(){

    for(ll i=0;i<3;i++){
        cin >> s[i];
        for(auto c:s[i])
            if(mp[c]==-1)
                mp[c] = ptr++;
    }
    
    bool poss = true;
    if(ptr > 10){
        poss = false;
    }
    else{
        vector<ll> p(10,0);
        for(ll i=0;i<10;i++) p[i] = i;
        for(poss=testa(p);!poss && next_permutation(p.begin(),p.end());poss = testa(p));
    }    

    if(poss){
        for(auto x:num)
            cout << x << "\n";
    }
    else{
        cout << "UNSOLVABLE" << '\n';
    }

    return 0;
}
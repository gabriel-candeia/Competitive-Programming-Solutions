#include<bits/stdc++.h>
#define maxn int(6e5+5)
using namespace std;

int k, n;
string s;
int winners[maxn];
vector<int> mp, passos;

string normaliza(string s){
    int n = s.size();
    string answ = "#";
    vector<pair<char,int>> aux, acm;
    mp.assign(s.size()+1,0);
    reverse(s.begin(),s.end());
    for(int i=1;i<=n;i++){
        acm.push_back({s[i-1],n-(i-1)-1});
        if(((i)&(i+1))==0){
            reverse(acm.begin(),acm.end());
            for(auto p:acm) aux.push_back(p);
            acm.clear();
        }
    }

    for(int i=0;i<n;i++){
        mp[aux[i].second+1] = i+1;
        answ+=aux[i].first;
    }

    return answ;
}

int merge(int a, int b, char flag){
    if(flag=='0') return a;
    if(flag=='1') return b;
    return a+b;
}

int converte(int p){
    return (p-(1<<(k)));
}

int build(int p){
    if(p<s.size())
        return winners[p] = merge(build(2*p),build(2*p+1),s[p]);
    else 
        return winners[p] = 1;
}

int update(int p, int i){
    //cout << p << " " << i << "\n";
    if(i==passos.size()) 
        return winners[p] = merge(winners[2*p],winners[2*p+1],s[p]);
    if(passos[i]==0)
        return winners[p] = merge(update(2*p,i+1),winners[2*p+1],s[p]);
    return winners[p] = merge(winners[2*p],update(2*p+1,i+1),s[p]);
}

int main(){
    cin >> k >> s;
    n = s.size();
    s = normaliza(s);
    build(1);
    int q, i;
    char x;
    cin >> q;


    for(int z=0;z<q;z++){
        cin >> i >> x;
        s[mp[i]] = x;
        passos.clear();
        for(int j=mp[i];j!=1;j/=2) passos.push_back(j%2);
        reverse(passos.begin(),passos.end());
        update(1,0);
        cout << winners[1] <<'\n';
    }
    

    return 0;
}   

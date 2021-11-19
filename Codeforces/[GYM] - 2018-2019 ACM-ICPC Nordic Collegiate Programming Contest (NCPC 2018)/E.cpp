#include<bits/stdc++.h>
#define maxn 6
#define maxm 101
#define ld double
#define ll long long
using namespace std;

int n, m, d, soman, somam;
map<pair<vector<int>,vector<int>>,ld> mp;

int soma(const vector<int> &a){
    int answ = 0;
    for(auto &x:a) answ+=x;
    return answ;
}

ld solve(vector<int> a, vector<int> b){
    if(a.size() && a.back()==0) a.pop_back();
    if(b.size() && b.back()==0) b.pop_back();
    if(b.size()==0 || (soman-soma(a)+somam-soma(b)==d))
        return (ld) (b.size()==0);
    if(mp.find({a,b})!=mp.end())
        return mp[{a,b}];
    auto &x = mp[{a,b}];
    int qtd = a.size()+b.size();
    x = 0;
    
    for(int i=a.size()-1, last = a.size()-1;i>=0;i--){
        if(i==a.size()-1 || a[i]!=a[i+1])
            last = i;
        if(a[i])
            a[last]--, x += (solve(a,b))*1.0/qtd, a[last]++;
    }
    for(int i=b.size()-1, last = b.size()-1;i>=0;i--){
        if(i==b.size()-1 || b[i]!=b[i+1])
            last = i;
        if(b[i])
            b[last]--, x += (solve(a,b))*1.0/qtd, b[last]++;
    }
    return x;
}


int main(){
    cin >> n >> m >> d;

    vector<int> a(n), b(m);
    for(auto &x:a)
        cin >> x, soman += x;
    
    for(auto &x:b)
        cin >> x, somam += x;

    sort(a.rbegin(),a.rend());
    sort(b.rbegin(),b.rend());
    cout << fixed << setprecision(10) << solve(a,b) << "\n";
    
    return 0;
}
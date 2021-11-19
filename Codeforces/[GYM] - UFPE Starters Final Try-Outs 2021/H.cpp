#include<bits/stdc++.h>
#define ll long long
using namespace std;

bool isok(string s){
    for(int i=0;i<s.size()-1;i++)
        if(s[i]!=i+1+'0')
            return false;
    return true;
}

vector<int> c;
int dx[4] = {1,-1,0,0}, dy[4] = {0,0,1,-1};
string troca(string s, int k, ll &cost){
    cost = -1;
    string answ = s;
    int u=0, i, j;
    for(u=0;s[u]!='0';u++);
    i = u/3, j = u%3;
    i+=dx[k], j+=dy[k];
    if(i>=0 && j>=0 && i<3 && j<3){
        int v = i*3+j;
        cost = c[s[v]-'0'];
        swap(answ[v],answ[u]);
    }
    return answ;
}

int main(){
    string s, t;
    ll d=0;

    for(int i=0;i<9;i++){
        char ca;
        cin >> ca;
        s.push_back(ca);
    }
    
    c.assign(9,0);
    for(int i=1;i<=8;i++) cin >> c[i];

    map<string,ll> dist;
    priority_queue<tuple<ll,string>> pq;

    
    dist[s] = 0;
    pq.push({-dist[s],s});
    while(pq.size()){
        tie(d,s) = pq.top(), pq.pop();
        d = -d;
        if(isok(s)){
            cout << d << "\n";
            return 0;
        }
        if(d>dist[s]) continue;
        for(int i=0;i<4;i++){
            ll cost = 0;
            t = troca(s,i,cost);
            if(cost!=-1 && (dist.find(t)==dist.end() || d+cost<dist[t])){
                dist[t] = d+cost;
                pq.push({-dist[t],t});
            }
        }
    }
    cout <<"ruim\n";
    return 0;
}
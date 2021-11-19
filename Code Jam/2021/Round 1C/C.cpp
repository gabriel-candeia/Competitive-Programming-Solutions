#include<bits/stdc++.h>
using namespace std;

int inverte(int x){
    int answ = 0;
    if(x==0) return 1;
    for(int i=0;x;i++, x/=2){
        answ = answ + (1-x%2)*(1<<i);
    }
    return answ;
}

int solve(int s, int t){
    vector<int> visited((1<<20),0);
    queue<int> q;

    q.push(t); visited[t] = true;
    while(q.size()){
        t = q.front(), q.pop();
        if(t>(1<<20)) continue;
        if(t==s) break;
        if(inverte(t) < visited.size() && !visited[inverte(t)]){
            visited[inverte(t)] = 1;
            q.push(inverte(t));
            visited[inverte(t)] = visited[t]+1;
        }
        if(2*t<visited.size() && !visited[2*t]){
            visited[2*t] = 1;
            q.push(2*t);
            visited[2*t] = visited[t]+1;
        }
    }

    return visited[s]-1;
}

int converte(string s){
    int acm = 0;
    for(int i=0;i<s.size();i++){
        acm = 2*acm + (s[i]-'0');
    }
    return acm;
}

int main(){
    int t, caso=0;

    cin >> t;
    while(t--){
        string s, t;
        cin >> s >> t;
        int answ = solve(converte(t),converte(s));
        
        if(answ==-1)
            cout << "Case #" << ++caso << ": " << "IMPOSSIBLE" <<'\n';
        else
            cout << "Case #" << ++caso << ": " << answ <<'\n';

    }

    return 0;
}
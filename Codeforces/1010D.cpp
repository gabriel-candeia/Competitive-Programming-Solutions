#include<bits/stdc++.h>
#define maxn int(1e6+5)
using namespace std;

int n;
bool val[maxn], dp[maxn][2];
vector<int> adj[maxn];
vector<string> op;

bool f(int i, bool a, bool b){
    if(op[i]=="AND")
        return a&b;
    else if(op[i]=="OR")
        return a|b;
    else if(op[i]=="XOR")
        return a^b;
    else
        return !a;
}

bool precomp(int u){
    if(op[u]=="IN")
        return val[u];
    else
        return val[u] = f(u,precomp(adj[u][0]),(op[u]=="NOT") ? 0 : precomp(adj[u][1]));
}

void solve(int u, int p){
    if(p==-1){
        dp[u][0] = 0;
        dp[u][1] = 1;
    }
    else{
        dp[u][0] = dp[p][f(p,0,(op[p]=="NOT") ? 0 : val[adj[p][0]^adj[p][1]^u])];
        dp[u][1] = dp[p][f(p,1,(op[p]=="NOT") ? 0 : val[adj[p][0]^adj[p][1]^u])];
    }
    if(op[u]!="IN"){
        for(auto v:adj[u])
            solve(v,u);
    }
}

int main(){
    cin >> n;
    int a, b;
    op.assign(n+1,"");
    for(int i=1;i<=n;i++){
        cin >> op[i]; 
        if(op[i]=="NOT"){
            cin >> a;
            adj[i].push_back(a);
        }
        else if(op[i]=="IN"){
            cin >> a;
            val[i] = a;
        }
        else{
            cin >> a >> b;
            adj[i].push_back(a);
            adj[i].push_back(b);
        }
    }
    
    precomp(1);
    solve(1,-1);
    for(int i=1;i<=n;i++)
        if(op[i]=="IN")
            cout << dp[i][!val[i]];
    cout <<'\n';

    return 0;
}
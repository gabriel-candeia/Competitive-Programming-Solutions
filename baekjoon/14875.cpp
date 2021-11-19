#include<bits/stdc++.h>
#define maxn int(3e5+5)
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const ll inf = 1e12;
ll n, k;
vector<int> adj[maxn];
pair<ll,ll> first[maxn], second[maxn];
ll nxt[maxn], a[maxn], pos[maxn];

void precomp(int u, int p){
    first[u] = second[u] = {-inf,1};

    for(auto v:adj[u]){
        if(v!=p){
            precomp(v,u);
            auto cmp = first[v], op = pair<ll,ll>{a[v]-1,-v};

            cmp.first--;
            if(op>cmp)
                cmp = op;

            if(cmp>first[u]){
                second[u] = first[u];
                first[u] = cmp;
            }
            else if(cmp>second[u]){
                second[u] = cmp;
            }
        }
    }
}

stack<tuple<int,int>> st;
int ptr[maxn];
void precomp_iter(int u, int p){
    st.push({u,p});
    while(st.size()){
        tie(u,p) = st.top();

        if(ptr[u]==0){
            first[u] = second[u] = {-inf,1};
        }
        int last = ptr[u]-1;
        if(last>=0 && adj[u][last]==p) last--;
        if(last>=0){
            int v = adj[u][last];
            auto cmp = first[v], op =  pair<ll,ll>{a[v]-1,-v};

            cmp.first--;
            if(op>cmp)
                cmp = op;

            if(cmp>first[u]){
                second[u] = first[u];
                first[u] = cmp;
            }
            else if(cmp>second[u]){
                second[u] = cmp;
            }
        }
        if(ptr[u]<adj[u].size() && adj[u][ptr[u]]==p){
            ptr[u]++;
        }
        if(ptr[u]<adj[u].size()){
            st.push({adj[u][ptr[u]],u});
            ptr[u]++;
        }
        else{
            st.pop();
        }
    }
}

void solve(int u, int p){
    nxt[u] = -first[u].second;

    for(auto v:adj[u]){
        if(v!=p){
            pair<ll,ll> old = first[v], old2 = second[v], cmp, op;    
            cmp = ((first[u].second==first[v].second || first[u].second==-v) ? second[u] : first[u]);
            cmp.first--;
    
            op = {a[u]-1,-u};
            if(op>cmp)
                cmp = op;

            if(cmp>first[v])
                first[v] = cmp;
            else if(cmp>second[v])
                second[v] = cmp;

            solve(v,u);
            first[v] = old;
            second[v] = old2;
        }
    }

}

pair<ll,ll> old1[maxn], old2[maxn];
void solve_iter(int u, int p){
    st.push({u,p});
    while(st.size()){
        tie(u,p) = st.top();

        if(ptr[u]==0){
            nxt[u] = -first[u].second;
        }
        int last = ptr[u]-1;
        if(last>=0 && adj[u][last]==p) last--;
        if(last>=0){
            int v = adj[u][last];
            first[v] = old1[u];
            second[v] = old2[u];
        }
        if(ptr[u]<adj[u].size() && adj[u][ptr[u]]==p){
            ptr[u]++;
        }
        if(ptr[u]<adj[u].size()){
            int v = adj[u][ptr[u]];
            old1[u] = first[v], old2[u] = second[v];
            pair<ll,ll>  cmp = ((first[u].second==first[v].second || first[u].second==-v) ? second[u] : first[u]), op;
            cmp.first--;
            op = {a[u]-1,-u};
            if(op>cmp)
                cmp = op;
            if(cmp>first[v])
                first[v] = cmp;
            else if(cmp>second[v])
                second[v] = cmp;

            st.push({v,u});
            ptr[u]++;
        }
        else{
            st.pop();
        }
    }
}

int main(){
    fastio();
    cin >> n >> k;

    for(int i=1;i<=n;i++)
        cin >> a[i];

    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    precomp_iter(1,-1);
    for(int i=0;i<=n;i++)
        ptr[i] = 0;
    solve_iter(1,-1);
    
    int cnt = 0, curr = 1;
    for(;pos[curr]==0;curr = nxt[curr], cnt++)
        pos[curr] = cnt;

    ll begin = pos[curr], ciclo = cnt-pos[curr];

    int answ;
    if(k<=begin){
        answ = 1;
    }
    else{
        k = (k-begin)%ciclo;
        answ = curr;
    }

    while(k--)
        answ = nxt[answ];

    cout << answ << "\n";

    return 0;
}
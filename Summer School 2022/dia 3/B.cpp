#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define LOG 21
using namespace std;

int n;
vector<int> adj[maxn];
int ht[maxn], parent[maxn][LOG], siz[maxn];

bool comp(int a, int b){
    return siz[a] > siz[b];
}

void precomp(int u, int p){
    siz[u] = 1;
    ht[u] = ((p==-1) ? 0 : ht[p]+1);
    parent[u][0] = p;
    for(int k=1;k<LOG;k++){
        if(parent[u][k-1]!=-1){
            parent[u][k] = parent[parent[u][k-1]][k-1];
        }
    }
    for(auto v:adj[u]){
        if(v!=p){
            precomp(v,u);
            siz[u] += siz[v];
        }
    }
    sort(adj[u].begin(),adj[u].end(),comp);
}

int lift(int u, int x){
    for(int k=LOG-1;k>=0;k--){
        if(parent[u][k]!=-1 && x>=(1<<k)){
            u = parent[u][k];
            x -= (1<<k);
        }
    }
    return u;
}

vector<int> arr;
void get(int u, int p, int x){
    if(x==0)
        arr.push_back(u);
    sort(adj[u].begin(),adj[u].end());
    for(auto v:adj[u]){
        if(v!=p){
            get(v,u,x-1);
        }
    }
}

int main(){
    cin >> n;
    for(int i=0;i<n-1;i++){
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    memset(parent,-1,sizeof(parent));
    precomp(1,-1);
    
    int x;
    cout << "? 1 1" << endl;
    cin >> x;
    get(1,-1,x);

    if(x==0){
        cout <<"! 1"<< endl;
        return 0;
    }

    int l = 0, r = arr.size()-1, med, answ, d, p, v;
    while(l<=r){
        med = l + (r-l)/2;
        cout << "? 1" <<" "<< arr[med] <<endl;
        cin >> d;
        if(d==0){
            answ = med;
            break;
        }

        p = lift(arr[med],d/2-1);
        cout << "? 2" <<" "<< parent[p][0] <<endl;
        cin >> v;
        
        if(v<p){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    
    cout <<"! "<< arr[answ] << endl;

    return 0;
}
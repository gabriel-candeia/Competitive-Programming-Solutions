#include<bits/stdc++.h>
#define maxm int(1e6+5)
#define maxn int(2e3+5)
#define ll long long
#define LOG 23
using namespace std;

vector<int> adj[maxm];
int lvl[maxm], dad[maxm][LOG];
char mat[maxn][maxn];
 
void dfs(int u, int p, int h){
	lvl[u] = h;
	dad[u][0] = p;
	for(int i = 1; i < LOG; i++)
		if(dad[u][i-1] != -1)
			dad[u][i] = dad[dad[u][i-1]][i-1];
	for(int v:adj[u])
		if(v != p)
			dfs(v, u, h+1);
}
 
int LCA(int u, int v){
	if(lvl[u] < lvl[v]) swap(u, v);
	for(int i = LOG-1; i >= 0; i--)
		if(dad[u][i] != -1 && lvl[dad[u][i]] >= lvl[v])
			u = dad[u][i];
	if(u == v) return u;
	for(int i = LOG-1; i >= 0; i--){
		if(dad[u][i] != dad[v][i]){
			u = dad[u][i];
			v = dad[v][i];
		}
	}
	return dad[u][0];
}

int distancia(int u, int v){
    return lvl[u]+lvl[v] - 2*lvl[LCA(u,v)];
}

int main(){
    int h, w;
    string s;
    
    cin >> h >> w;
    getline(cin,s);
    for(int i=0;i<h+1;i++){
        getline(cin,s);
        for(int j=0;j<2*w+1;j++){
            mat[i][j] = s[j];
        }
    }

    /*for(int i=0;i<h+1;i++){
        for(int j=0;j<2*w+1;j++){
            cout << mat[i][j];
        }
        cout<<"\n";
    }cout<<"\n";*/

    for(int i=1;i<=h;i++){
        int plin = i, pcol = 1;
        for(int j=1;j<=w;j++){
            if(mat[plin][pcol]!='_'){
                int u = (i-1)*w+(j-1), v = (i)*w+j-1;
                adj[v].push_back(u);
                adj[u].push_back(v);
                //cout << i << ", " << j << " " << u << " " << v <<"\n";
            }
            if(mat[plin][pcol+1]!='|'){
                int u = (i-1)*w+j-1, v = (i-1)*w+j;
                adj[v].push_back(u);
                adj[u].push_back(v);
                //cout << u << " " << v <<"\n";
            }
            pcol+=2;
        }
    }

    memset(dad, -1, sizeof(dad));
    dfs(0,-1,0);

    vector<int> arr;
    int q;
    cin >> q;
    while(q--){
        int a, b;
        cin >> a  >> b;
        //cout << a <<" "<< b <<"\n";
        arr.push_back((a-1)*w+(b-1));
    }

    ll acm = 0;
    for(int i=1;i<arr.size();i++){
        //cout << arr[i-1] << " " << arr[i] << "\n";
        acm = acm + ((long long) distancia(arr[i-1],arr[i]));
    }

    cout << acm <<"\n";

    return 0;
}
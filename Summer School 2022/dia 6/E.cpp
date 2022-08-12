// C++ program for centroid decomposition of Tree
#include <bits/stdc++.h>
using namespace std;
 
#define MAXN int(1e5+10)
int n;

int dist[MAXN];
vector<int> g[MAXN];
bool tk[MAXN];
int fat[MAXN]; // father in centroid decomposition
int szt[MAXN]; // size of subtree
int calcsz(int x, int f){
	szt[x]=1;
	for(auto y:g[x])if(y!=f&&!tk[y])szt[x]+=calcsz(y,x);
	return szt[x];
}
void cdfs(int x=1, int f=-1, int sz=-1){ // O(nlogn)
	if(sz<0)sz=calcsz(x,-1);
	for(auto y:g[x])if(!tk[y]&&szt[y]*2>=sz){
		szt[x]=0;cdfs(y,f,sz);return;
	}
	tk[x]=true;fat[x]=f;
	for(auto y:g[x])if(!tk[y])cdfs(y,x);
}
void centroid(){memset(tk,false,sizeof(tk));cdfs();}

int main()
{
	cin.tie(0); ios_base::sync_with_stdio(0);
 	cin >> n;
	int u, v;
	for(int i = 1; i < n; i++){
		cin >> u >> v;
		g[u].push_back(v);
        g[v].push_back(u);
	}
	
    centroid();
    int mx = 0;
    memset(dist,-1,sizeof(dist));
	for(int i=1;i<=n;i++){
        if(dist[i]==-1){
            stack<int> st;
            int u;
            for(u=i;fat[u]!=-1 && dist[u]==-1;u=fat[u]){
                st.push(u);
            }
            if(fat[u]==-1)
                dist[u] = 0;
            while(st.size()){
                dist[st.top()] = dist[u]+1;
                u = st.top();
                st.pop();
            }
        }
        mx = max(mx,dist[i]);
    }

    if(mx>25){
        cout <<"impossible\n";
        return 0;
    }

    for(int i=1;i<=n;i++){
        cout << (char (dist[i]+'A')) <<" ";
    }cout<<"\n";
	
    return 0;
}

#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

vector<int> adj[maxn];
int vivo[maxn], upto[maxn], parent[maxn];

int main(){
    int q, cnt = 1, rei = 1;
    fastio();
    vivo[1] = 1;
    parent[rei] = -1;

    cin >> q;
    for(int i=0;i<q;i++){
        int a, b;
        cin >> a >> b;
        if(a==1){
            adj[b].push_back(++cnt);
            vivo[cnt] = 1;
            parent[cnt] = b;
        }
        else{
            vivo[b] = 0;
            while(vivo[rei]==0){
                if(upto[rei]<adj[rei].size()){
                    rei = adj[rei][upto[rei]++];
                }
                else{
                    rei = parent[rei];
                }
            }
            cout << rei <<"\n";
        }
    }

    return 0;
}

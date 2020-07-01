#include<bits/stdc++.h>
using namespace std;

vector<int> candidate;
vector<int> visited;
int t, n, x, y, dist, r1, r2, curr;

void dfs(vector<vector<int>>& adj, int i, int distancia, int mk){
    visited[i] = 2;
    if(mk==distancia){
        candidate.push_back(i);
        return;
    }

    for(auto w:adj[i]){
        if(!visited[w]){
            dfs(adj,w,distancia+1,mk);
        }
    }
}

int main(){
    cin >> t;
    while(t--){
        cin >> n;
        vector<vector<int>> adj(n+1,vector<int>());

        for(int i=0;i<n-1;i++){
            cin >> x >> y;
            adj[x].push_back(y);
            adj[y].push_back(x);
        }

        cout << "? ";
        cout << n << " ";
        for(int i=1;i<=n;i++){
            cout << i << ' ';
        }
        cout << endl;

        cin >> curr >> dist;
        int l=dist, next, cmp;
        int cnt=1;
        visited.assign(n+1,false);
        while(cnt<=8){
            cnt++;
            candidate.clear();
            dfs(adj,curr,0,l);
            if(candidate.size()==0){
                break;
            }
            cout << "? ";
            cout << candidate.size() << " ";
            for(auto folha:candidate){
                cout << folha << ' ';
            }
            cout << endl;
            cin >> next >> cmp;

            if(cmp==dist){
                curr = next;
                for(int i=0;i<=n;i++){
                    if(visited[i]==2){
                        visited[i] = 1;
                    }
                }
            }
            else{
                for(int i=0;i<=n;i++){
                    if(visited[i]==2){
                        visited[i] = 0;
                    }
                }
            }
            l/=2;
            if(l==0){
                l = 1;
            }
        }
        visited.assign(n+1,false);
        candidate.clear();
        dfs(adj,curr,0,dist);
        cout << "? ";
        cout << candidate.size() << " ";
        for(auto folha:candidate){
            cout << folha << ' ';
        }
        cout << endl;
        cin >> next >> cmp;

        cout << "! " << curr <<" " << next << '\n';

        string s;
        cin >> s;
    }


    return 0;
}

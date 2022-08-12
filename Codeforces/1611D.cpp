#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int parent[maxn];
vector<int> adj[maxn];

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, root=-1;
        cin >> n;
        for(int i=1;i<=n;i++){
            int x;
            cin >> x;
            parent[i] = x;
            if(x!=i)
                adj[x].push_back(i);
            else 
                root = i;
        }
        
        bool poss = true;
        int d = -1;
        set<int> st;
        vector<int> answ(n+1,0);
        st.insert(root);

        for(int i=0;i<n;i++){
            int t;
            cin >> t;
            if(st.find(t)!=st.end()){
                answ[t] = ++d;
                st.erase(st.find(t));
                for(auto v:adj[t])
                    st.insert(v);
            }
            else{
                poss = false;
            }
        }
        
        if(poss){
            for(int i=1;i<=n;i++){
                cout << answ[i]-answ[parent[i]] <<" ";
            }cout<<"\n";
        }
        else{
            cout << -1 <<"\n";
        }

        for(int i=1;i<=n;i++){
            adj[i].clear();
        }
    }

    return 0;
}
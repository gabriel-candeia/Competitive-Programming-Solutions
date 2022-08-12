#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    ifstream rd;
    rd.open("topo.in",std::ifstream::in); 

    rd >> t;
    while(t--){
        int n;
        vector<int> fst, lst;

        rd >> n;
        fst.assign(n+1,0), lst.assign(n+1,0);

        for(int i=1;i<=n;i++)
            rd >> fst[i];
        for(int i=1;i<=n;i++)
            rd >> lst[i];

        vector<pair<int,int>> ciclo, dag;

        for(int i=1;i<=n;i++){
            if(lst[i]==0){
                dag.push_back({fst[i],i});
            }
            else{
                ciclo.push_back({i,lst[i]});
            }
        }

        
        sort(dag.begin(),dag.end());
        for(auto &p:dag) swap(p.first,p.second);

        bool ok = true;
        vector<pair<int,int>> edges;
        for(int i=0;i<dag.size();i++){
            int u = dag[i].first;
            if(fst[u]>i){
                ok = false;
            }
            else{
                for(int j=0;j<fst[u];j++){
                    edges.push_back({dag[j].first,u});
                }
            }
        }

        if(ciclo.size()==1) ok = false;
        //cout << ciclo.size() <<"\n";
        for(int i=0;i<ciclo.size();i++){
            int u = ciclo[i].first;
            if(fst[u]-lst[u]){
                ok = (ok && (fst[u]-lst[u]) <= dag.size());
                for(int j=0;j<min((int)dag.size(),(fst[u]-lst[u]));j++){
                    edges.push_back({dag[j].first,u});
                }
            }
            if(lst[u] > ((int)ciclo.size())-1) ok = false;
            for(int j=i+1, qtd=0;qtd<lst[u];j++, qtd++){
                j = j%ciclo.size();
                //cout <<"->"<< ciclo[j].first << " " << j << " " << u <<"\n";
                edges.push_back({ciclo[j].first,u});
            }
        }

        if(ok){
            cout << edges.size() <<"\n";
            for(auto e:edges){
                cout << e.first << " " << e.second<<"\n";
            }
        }
        else{
            cout << -1 <<"\n";
        }


    }

    return 0;
}
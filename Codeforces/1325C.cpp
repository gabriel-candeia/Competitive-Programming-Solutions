#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<pair<int,int> > edges;
    vector<int> dg;
    int n, u, v, target;
    int qtd, cont;
    cin >> n;
    dg.assign(n+1,0); 
    for(int i=0;i<n-1;i++){
        cin >> u >> v;
        dg[u]++;
        dg[v]++;
        edges.push_back(make_pair(u,v));
        if(dg[u]>=3){
            target = u;
        }
        else if(dg[v]>=3){
            target = v;
        }
    }

    n-=2;
    cont = 0;
    for(auto e:edges){
        u = e.first;
        v = e.second;
        if((u==target || v==target) && cont<3){
            cout << cont++ <<'\n';
        }
        else{   
            cout << n << '\n';
            n--;
        }
    }    

    return 0;
}
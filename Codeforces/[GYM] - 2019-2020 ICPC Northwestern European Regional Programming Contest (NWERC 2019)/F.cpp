#include<bits/stdc++.h>
using namespace std;

int n, m, qtd;
map<int,int> compress;
vector<int> decompress, representante, pai, rnk;
vector<vector<int>> pessoas;

int find(int i){
    return (pai[i]==i) ? i : pai[i] = find(pai[i]);
}

bool _union(int x, int y){
    x = find(x);
    y = find(y);
    if(x!=y){
        if(rnk[x]>rnk[y]){
            pai[x] = y;
        }
        else{
            pai[y] = x;
            rnk[x]+=(rnk[y]==rnk[x]);
        }
        qtd--;
        return true;
    }
    return false;
}

int main(){
    qtd=0;
    cin >> n;
    pessoas.assign(n,vector<int>());
    for(int i=0;i<n;i++){
        cin >> m;
        pessoas[i].assign(m,0);
        for(int j=0;j<m;j++){
            cin >> pessoas[i][j];
            if(compress.find(pessoas[i][j])==compress.end()){
                compress[pessoas[i][j]] = decompress.size();
                pai.push_back(decompress.size());
                rnk.push_back(0);
                decompress.push_back(pessoas[i][j]);
                representante.push_back(i);
                qtd++;
            }
            pessoas[i][j] = compress[pessoas[i][j]];
            _union(pessoas[i][j],pessoas[i][0]);
        }
    }

    if(qtd!=1){
        cout << "impossible\n";
    }
    else{
        pai.assign(n,0);
        rnk.assign(n,0);    
        for(int i=0;i<n;i++)
            pai[i] = i;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<pessoas[i].size();j++){
                if(_union(i,representante[pessoas[i][j]])){
                    cout << i+1 << " " << representante[pessoas[i][j]]+1 << " " << decompress[pessoas[i][j]] <<'\n';
                }
            }
        }
    }

    return 0;
}
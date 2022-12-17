#include<bits/stdc++.h>
using namespace std;

vector<int> bola;
vector<int> id, inv;
vector<vector<int>> boxes;

void combine(int y, int x){
    if(boxes[id[x]].size() < boxes[id[y]].size()){
        swap(id[x],id[y]);
        inv[id[x]] = x;
        inv[id[y]] = y;
    }
    for(auto z:boxes[id[y]]){
        boxes[id[x]].push_back(z);
        bola[z] = id[x];
    }
    boxes[id[y]].clear();
    
}

int main(){
    int n, q;
    cin >> n >> q;
    
    boxes.assign(n+1,vector<int>());
    bola.assign(n+1,0);
    inv.assign(n+1,0);
    id.assign(n+1,0);

    for(int i=1;i<=n;i++){
        boxes[i].push_back(i);
        bola[i] = i;
        id[i] = i;
        inv[i] = i;
    }

    int novo = n;
    for(int i=0;i<q;i++){
        int op;
        cin >> op;
        if(op==1){
            int x, y;
            cin >> x >> y;
            combine(y,x);
        }
        else if(op==2){
            int x;
            cin >> x;
            boxes[id[x]].push_back(++novo);
            bola.push_back(id[x]);
        }
        else{
            int x;
            cin >> x;
            cout << inv[bola[x]] <<"\n";
        }
    }


    return 0;
}
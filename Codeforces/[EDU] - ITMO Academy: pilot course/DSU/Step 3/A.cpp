#include<bits/stdc++.h>
using namespace std;

struct PDSU{
    struct state{
        int x, rx, y, ry;

        state(int x, int rx, int y, int ry) : x(x), y(y), rx(rx), ry(ry) {

        }
    };

    vector<int> parent, rnk;
    stack<int> checkpoints;
    stack<state> st;
    int cc = 0;

    PDSU(int n) : rnk(n+1,0), parent(n+1,0) {
        iota(parent.begin(),parent.end(),0), cc = n;
    }   

    int find(int x){
        return (x==parent[x]) ? x : find(parent[x]);
    }

    void _union(int x, int y){
        x = find(x); 
        y = find(y);
        if(x!=y){
            if(rnk[x] > rnk[y]) swap(x,y);
            st.push({x,rnk[x],y,rnk[y]});
            parent[x] = y;
            rnk[y] += (rnk[x]==rnk[y]);
            cc--;
        }
    }

    void rollback(){
        if(st.size()==0) return;
        auto p = st.top(); st.pop();
        parent[p.x] = p.x, rnk[p.x] = p.rx;
        parent[p.y] = p.y, rnk[p.y] = p.ry;
        cc++;
    }

    void createCheckpoint(){
        checkpoints.push(st.size());
    }

    void rollbackToCheckpoint(){
        if(checkpoints.size()==0) return;
        while(st.size()>checkpoints.top()){
            rollback();
        }
        checkpoints.pop();
    }
};


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    PDSU st(n);

    while(m--){
        string op;
        int x, y;
        cin >> op;
        if(op=="persist"){
            st.createCheckpoint();
        }
        else if(op=="union"){
            cin >> x >> y;
            st._union(x,y);
            cout << st.cc <<"\n";
        }
        else{
            st.rollbackToCheckpoint();
            cout << st.cc <<"\n";
        }
        
    }

    return 0;
}
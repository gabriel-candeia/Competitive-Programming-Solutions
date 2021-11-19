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
        checkpoints.push(0);
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
        while(st.size()>checkpoints.top())
            rollback();
        if(checkpoints.size()>1)
            checkpoints.pop();
    }
};

int block  = 300;
struct query{
    int id, l, r;

    query(int id, int l, int r) : id(id), l(l), r(r) {

    }

    bool operator<(query o){
        if(l/block == o.l/block)
            return r < o.r;
        return l/block < o.l/block;
    }

};


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;
    cin >> n >> m;

    PDSU st(n);
    vector<pair<int,int>> edges;
    vector<query> arr;
    vector<int> answ;
    for(int i=0;i<m;i++){
        int a, b;
        cin >> a >> b;
        edges.push_back({a,b});
    }


    int k;
    cin >> k;
    answ.assign(k,0);
    for(int i=0;i<k;i++){
        int a, b;
        cin >> a >> b;
        arr.push_back(query(i,a-1,b-1));
    }

    sort(arr.begin(),arr.end());
    int l=0, r=m, atual = -1;
    for(auto q:arr){
        if(q.l/block == q.r/block){
            st.rollbackToCheckpoint();
            for(l=q.l;l<=q.r;l++)
                st._union(edges[l].first,edges[l].second);
            answ[q.id] = st.cc;
            st.rollbackToCheckpoint();
        }
        else{
            if(q.l/block!=atual){
                st.rollbackToCheckpoint();
                atual = q.l/block;
                r = block+q.l-q.l%block;
            }
            while(r<=q.r)
                st._union(edges[r].first,edges[r].second), r++;
            st.createCheckpoint();
            for(l=block-1+q.l-q.l%block;l>=q.l;l--)
                st._union(edges[l].first,edges[l].second);
            answ[q.id] = st.cc;
            st.rollbackToCheckpoint();
        }
        /*
            se a query ta completamente dentro do bloco 

            senao
                se r crescer então 
                    move r até q.r
                se r decrescer
                    rollback
                salva
                move l do final do bloco ate q.l
                responde
                rollback
        */
    }

    for(auto x:answ)
        cout << x << "\n";

    return 0;
}
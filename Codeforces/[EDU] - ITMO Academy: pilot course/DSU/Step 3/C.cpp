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

    PDSU(){

    }

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

struct query{
    int type, id, l, r, x, y;

    query(int type, int id, int l, int r, int x, int y) : type(type), id(id), l(l), r(r), x(x), y(y) {

    }
};

PDSU st;
vector<int> answ;
void solve(int l, int r, vector<query> queries){
    st.createCheckpoint();
    if(l==r){
        for(auto q:queries){
            if(q.type==1){
                if(q.l<=l && r<=q.r)
                    st._union(q.x,q.y);
            }
        }
        for(auto q:queries){
            if(q.type==0 && q.l==l)
                answ[q.id] = st.cc;
        }
    }
    else{
        vector<query> queries2;
        for(auto q:queries){
            if(q.type == 1 && q.l<=l && r<=q.r){
                st._union(q.x,q.y);
            }
            else if((l<=q.l && q.l<=r) || (q.l<=l && l<=q.r)){       
                queries2.push_back(q);
            }
        }

        int med = (l+r)/2;
        solve(l,med,queries2);
        solve(med+1,r,queries2);
    }
    st.rollbackToCheckpoint();
}


int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m;

    cin >> n >> m;

    st = PDSU(n);
    
    vector<query> queries;
    map<pair<int,int>,int> mp;
    for(int i=0;i<m;i++){
        char op;
        int x, y;
        cin >> op;
        if(op=='?'){
            queries.push_back(query(0,i,i,i,0,0));
        }
        else{
            cin >> x >> y;
            if(x>y) swap(x,y);
            if(mp.find(pair<int,int>{x,y})==mp.end())
                mp[pair<int,int>{x,y}] = -1;
            int &last = mp[pair<int,int>{x,y}];
            if(last==-1){
                last = i;
            }
            else{
                queries.push_back(query(1,i,last,i,x,y));
                last = -1;
            }
        }
    }

    for(auto p:mp){
        if(p.second!=-1){
            queries.push_back(query(1,m,p.second,m,p.first.first,p.first.second));
        }
    }

    answ.assign(m,-1);
    solve(0,m,queries);

    for(int i=0;i<m;i++){
        if(answ[i]!=-1)
            cout << answ[i] << "\n";
    }

    return 0;
}
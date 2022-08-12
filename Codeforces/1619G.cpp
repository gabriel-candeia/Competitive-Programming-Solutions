#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

struct dsu{
    vector<int> parent, rnk, val;

    dsu(int n, vector<int> aux){
        parent.assign(n,0), rnk.assign(n,0), val.assign(n,0);
        for(int i=0;i<n;i++)
            parent[i] = i, rnk[i] = 0, val[i] = aux[i];
    }

    int find(int x){
        return ((x==parent[x]) ? x : parent[x] = find(parent[x]));
    }

    void _union(int x, int y){
        x = find(x), y = find(y);
        if(x!=y){
            if(rnk[x]>rnk[y]) swap(x,y);
            parent[x] = y;
            val[y] = min(val[y],val[x]);
            rnk[y] += (rnk[x]==rnk[y]);
        }
    }
};

int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        int n, k;
        vector<array<int,3>> pts;
        vector<int> val;

        cin >> n >> k;  

        val.assign(n,0), pts.assign(n,{0,0,0});
        for(int i=0;i<n;i++){
            cin >> pts[i][0] >> pts[i][1] >> val[i], pts[i][2] = i;
        }

        dsu st(n,val);
        sort(pts.begin(),pts.end());
        for(int i=0;i+1<n;i++){
            if(pts[i][0] == pts[i+1][0] && (pts[i+1][1]-pts[i][1] <= k)){
                st._union(pts[i][2],pts[i+1][2]);
            }
        }

        for(auto &x:pts){
            swap(x[0],x[1]);
        }

        sort(pts.begin(),pts.end());
        for(int i=0;i+1<n;i++){
            if(pts[i][0] == pts[i+1][0] && pts[i+1][1]-pts[i][1] <= k){
                st._union(pts[i][2],pts[i+1][2]);
            }
        }

        vector<int> tempos;
        for(int i=0;i<n;i++){
            if(st.find(i)==i){
                tempos.push_back(st.val[i]);
            }
        }
        sort(tempos.rbegin(),tempos.rend());

        /*for(auto x:tempos)
            cout << x << " ";
        cout<<"\n";*/
        //while(tempos.size() && tempos.back()==0) tempos.pop_back();

        tempos.push_back(0);
        int answ = tempos[0];
        for(int i=0;i<tempos.size()-1;i++){
            //cout << tempos[i] <<" ";
            answ = min(answ,max(i,tempos[i+1]));
        }
    
        cout << answ <<"\n";

    }

    return 0;
}
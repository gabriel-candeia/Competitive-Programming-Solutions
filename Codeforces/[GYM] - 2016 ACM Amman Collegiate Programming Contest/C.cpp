#include<bits/stdc++.h>
using namespace std;
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define maxn 100100

int t, n, q, pe, p, answ;
int pt[maxn];

int main(){
    fastio();

    cin >> t;
    while(t--){
        cin >> n >> q;
        vector<pair<int,int>> queries;
        set<pair<int,int>> st;
        int answ=0;
        memset(pt,0,sizeof(pt));
        for(int i = 1; i <= n; i++){
            st.insert({-pt[i],i});
        }


        int mx=0;
        for(int i = 1; i <= q; i++){
            cin >> p >> pe;
            auto it = st.begin();
            int winner = ((it==st.end())) ? 0 : (*it).second;
            st.erase({-pt[p],p});
            pt[p]+=pe;
            st.insert({-pt[p],p});
            it = st.begin();
            int winner1 = ((it==st.end())) ? 0 : (*it).second;
            if(winner!=winner1)
                answ = i;
        }
            
        cout << answ << '\n';
    }
}

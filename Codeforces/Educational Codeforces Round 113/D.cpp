#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
#define ll long long
using namespace std;

int main(){
    fastio();
    int t;

    cin >> t;
    while(t--){
        set<ll> x, y;
        int n, m, k;
        map<int,vector<int>> linha, coluna;
        cin >> n >> m >> k;

        x.insert(int(1e6+6));
        y.insert(int(1e6+6));

        for(int i=0;i<n;i++){
            ll val;
            cin >> val;
            x.insert(val);
        }

        for(int i=0;i<m;i++){
            ll val;
            cin >> val;
            y.insert(val);
        }
        ll answ = 0;
        vector<ll> hor, vert;

        for(int i=0;i<k;i++){
            ll a, b;
            cin >> a >> b;
            bool q1 = x.find(a)!=x.end(), q2 = y.find(b)!=y.end();
            if(q1 && !q2){
                vert.push_back(b);
                coluna[a].push_back(b);
            }
            else if(!q1 && q2){
                hor.push_back(a);
                linha[b].push_back(a);
            }
        }

        sort(vert.begin(),vert.end());
        for(int i=0, j=1;i<vert.size();i++){
            ll ub = *(y.upper_bound(vert[i]));
            for(;j<vert.size() && vert[j]<ub;j++);
            //cout << vert[i] << " " << ub << " " << j  << " " << j-i-1 << ", ";
            answ += j-i-1;
        }//cout<<"\n";
        //cout << answ <<"\n";

        sort(hor.begin(),hor.end());
        for(int i=0, j=1;i<hor.size();i++){
            ll ub = *(x.upper_bound(hor[i]));
            for(;j<hor.size() && hor[j]<ub;j++);
            //cout << j << " " << i <<" "<< hor[i] <<"\n";
            answ += j-i-1;
        }

        for(auto p:coluna){
            sort(p.second.begin(),p.second.end());
            for(int i=0,j=1;i<p.second.size();i++){
                ll ub = *(y.upper_bound(p.second[i]));
                for(;j<p.second.size() && p.second[j]<ub;j++);
                answ -= j-i-1;
            }
        }

        for(auto p:linha){
            sort(p.second.begin(),p.second.end());
            for(int i=0,j=1;i<p.second.size();i++){
                ll ub = *(x.upper_bound(p.second[i]));
                for(;j<p.second.size() && p.second[j]<ub;j++);
                answ -= j-i-1;
            }
        }

        cout << answ <<"\n";

    }

    return 0;
}
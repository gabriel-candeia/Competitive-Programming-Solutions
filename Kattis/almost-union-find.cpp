#include<bits/stdc++.h>
#define ll long long
using namespace std;

class DSU{
    private:
        vector<ll> parent, rank, size, sum;
    public:
        DSU(ll n){
            parent.assign(2*n+1,0);
            rank.assign(2*n+1,0);
            size.assign(2*n+1,0);
            sum.assign(2*n+1,0);
            for(ll i=1;i<=2*n;i++){
                parent[i] = i;
            }
            for(ll i=1;i<=n;i++){
                parent[i] = i+n;
                size[parent[i]] = 1;
                sum[parent[i]] = i;
            }
        }

        ll find(ll x){
            return (x==parent[x]) ? x : (parent[x] = find(parent[x]));
        }

        ll tamanho(ll x){
            return size[find(x)];
        }

        ll soma(ll x){
            return sum[find(x)];
        }

        void _union(ll x, ll y){
            x = find(x);
            y = find(y);
            if(x!=y){
                if(rank[x]>rank[y]){
                    parent[y] = x;

                    size[x]+=size[y];
                    sum[x]+=sum[y];
                }
                else{
                    parent[x] = y;
                    rank[y] += (rank[x]==rank[y]);

                    size[y]+=size[x];
                    sum[y]+=sum[x];
                }
            }
        }

        void move(ll x, ll y){
            ll px = find(x);
            y = find(y);
            if(px!=y){
                size[px]--; sum[px]-=x;
                size[y]++; sum[y]+=x;
                parent[x] = y;
            }
        }
};

int main(){
    ll n, m, op, x, y;
    while(cin >> n >> m){
        DSU alg(n);
        for(ll i=0;i<m;i++){
            cin >> op >> x;
            if(op==3){
                cout << alg.tamanho(x) << " " << alg.soma(x) << '\n';
            }
            else if(op==2){
                cin >> y;
                alg.move(x,y);
            }   
            else{
                cin >> y;
                alg._union(x,y);
            }
        }
    }

    return 0;
}

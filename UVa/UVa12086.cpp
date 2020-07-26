#include<bits/stdc++.h>
#define ll long long
using namespace std;

class FenwickTree{
    private:
        vector<ll> ft;
        ll n;
    public:
        ll lsOne(ll x){
            return (x&(-x));
        }

        FenwickTree(vector<ll>& A){
            n = A.size();
            ft.assign(n,0);
            for(int i=1;i<n;i++){
                update(i,A[i]);
            }
        }

        void update(ll i, ll v){
            for(;i<n;i+=lsOne(i)){
                ft[i]+=v;
            }
        }

        ll query(ll r){
            ll sum = 0;
            for(;r;r-=lsOne(r)){
                sum+=ft[r];
            }
            return sum;
        }

        ll query(ll l, ll r){
            return query(r) - query(l-1);
        }
};

int main(){
    string op;
    int x, y, n, caso=0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin >> n){
        if(n==0) break;
        if(caso) cout << '\n';
        cout << "Case " << ++caso << ":\n";
        vector<ll> A(n+1,0);
        for(int i=1;i<=n;i++) cin >> A[i];
        FenwickTree t(A);

        while(cin >> op){
            if(op=="END") break;
            else{
                cin >> x >> y;
                if(op=="S"){
                    t.update(x,y-A[x]);
                    A[x] = y;
                }
                else{
                    cout << t.query(x,y) << '\n';
                }
            }
        }
    }

    return 0;
}

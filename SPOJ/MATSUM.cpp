#include<bits/stdc++.h>
#define ll long long
#define N (1024+3)
using namespace std;

class FenwickTree{
    private:
        vector<ll> ft;
        int n;

    public:
        FenwickTree(){
        }

        void clear(int siz){
            n = siz+1;
            ft.assign(n,0);
        }

        ll lsOne(ll x){
            return (x&(-x));
        }

        ll query(ll r){
            ll sum=0;
            for(;r;r-=lsOne(r)){
                sum += ft[r];
            }
            return sum;
        }

        ll query(ll l, ll r){
            return query(r)-query(l-1);
        }

        void update(ll i, ll v){
            for(;i<n;i+=lsOne(i)){
                ft[i] += v;
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t, x, y, s, n, x1, y1;
    string op;
    int mat[N][N];
    FenwickTree ft[N];
    cin >> t;

    while(t--){
        cin >> n;
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){
                mat[i][j] = 0;
            }
            ft[i].clear(n);
        }
        while(cin >> op){
            if(op=="END"){
                break;
            }
            if(op=="SET"){
                cin >> x >> y >> s;
                x++; y++;
                ft[x].update(y,s-mat[x][y]);
                mat[x][y] = s;
            }
            else{
                cin >> x >> y >> x1>> y1;
                ll answ=0;
                x++; y++; x1++; y1++;
                for(int i=x;i<=x1;i++){
                    answ+=ft[i].query(y,y1);
                }
                cout << answ << '\n';
            }
        }
    }
    return 0;
}

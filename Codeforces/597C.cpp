#include<bits/stdc++.h>
#define ll long long
#define K 20
using namespace std;

class FenwickTree{
    private:
        typedef vector<ll> Node;
        vector<Node> ft;
        ll n, k;

    public:
        FenwickTree(ll siz, ll param){
            n = siz+1;
            ft.assign(n,Node(K,0));
            k = param+1;
        }

        ll lsOne(ll x){
            return (x&(-x));
        }

        void acumular(Node& a,Node b){
            for(ll i=k;i>=0;i--){
                a[i]+=b[i];
            }
        }

        Node desloc(Node answ){
            for(ll i=k;i>0;i--){
                answ[i] = answ[i-1];
            }
            answ[1] = 1;
            return answ;
        }

        Node query(ll r){
            Node answ(K,0);
            for(;r;r-=lsOne(r)){
                acumular(answ,ft[r]);
            }

            return answ;
        }

        void update(ll i, Node v){
            for(;i<n;i+=lsOne(i)){
                acumular(ft[i],v);
            }
        }
};

int main(){
    ll n, k, x;
    cin >> n >> k;
    FenwickTree t(n,k);
    for(ll i=0;i<n;i++){
        cin >> x;
        /*vector<ll> temp = t.desloc(t.query(x-1));

        cout << x << ": ";
        for(ll i=0;i<=k+1;i++){
            cout << temp[i] << ' ';
        }cout << '\n';*/

        t.update(x,t.desloc(t.query(x-1)));
    }
    cout << t.query(n)[k+1] << '\n';

    return 0;
}

/*
1: 0 1 0 0
2: 0 2 1 0





*/
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class FenwickTree{
    private:
        vector<ll> ft;
        int n;
    public:
        ll lsOne(ll x){
            return (x&(-x));
        }

        FenwickTree(int siz){
            n = siz+1;
            ft.assign(n,0);
        }

        void update(int i, int v){
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

        ll query(ll a, ll b){
            return query(b)-query(a-1);
        }
};

int main(){
    int t, n, x;

    cin >> t;
    while(t--){
        cin >> n;

        vector<int> A(n+1,0);
        map<int,int> pos;

        for(int i=1;i<=n;i++){
            cin >> A[i];
            pos[A[i]]++;
        }
        
        int cnt=0;
        for(auto& p:pos){
            p.second = ++cnt;
        }

        for(int i=1;i<=n;i++){
            A[i] = pos[A[i]];
        }

        FenwickTree ft(n);
        ll answ = 0;
        for(int i=n;i;i--){
            answ += ft.query(A[i]-1);
            ft.update(A[i],1);
        }
        cout << answ << '\n';


    }


    return 0;
}
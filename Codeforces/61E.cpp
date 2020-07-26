#include<bits/stdc++.h>
#define ll long long
using namespace std;

class FenwickTree{
    private:
        vector<ll> ft;
        int n;
    public:
        FenwickTree(int siz){
            n = siz+1;
            ft.assign(n,0);
        }

        ll lsOne(ll x){
            return (x&(-x));
        }

        ll query(ll r){
            ll sum=0;
            for(;r;r-=lsOne(r)){
                sum+=ft[r];
            }
            return sum;
        }

        ll query(ll l,ll r){
            return query(r)-query(l-1);
        }

        void update(ll i, ll v){
            for(;i<n;i+=lsOne(i)){
                ft[i]+=v;
            }
        }
};

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, cnt=0, sum=0, temp;
 
    vector<int> A;
    map<int,int> pos;

    cin >> n;
    A.assign(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> A[i];
        pos[A[i]] = 1;
    }

    for(auto& p:pos){
        p.second = ++cnt;
    }

    for(int i=1;i<=n;i++){
        A[i] = pos[A[i]];
    }

    FenwickTree ls(n);
    //Only possible since there are no repeated powers in the army
    //i<j<k && ai>aj>ak we are fixing the i
    for(int i=1;i<=n;i++){
        temp = ls.query(A[i]+1,n);
        sum += temp*(A[i]-1-(i-1-temp));
        ls.update(A[i],1);
    }

    cout << sum << '\n';

    return 0;
}
#include<bits/stdc++.h>
#define maxn int(2)
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

const ll mod = 1e9+7;
struct matrix{
    int n;
    ll a, b;
    ll c, d;

    matrix(int pn, bool id=false){
        n = pn;
        a = b = c = d = 0;
        if(id) a = d = 1;
    }

    matrix operator*(const matrix &o){
        matrix x(n);

        x.a = (a*o.a + b*o.c)%mod;
        x.b = (a*o.b + b*o.d)%mod;
        x.c = (c*o.a + d*o.c)%mod;
        x.d = (c*o.b + d*o.d)%mod;

        return x;
    }
};

matrix fexp(matrix x, int k){
    matrix result(x.n,true);
    for(;k;k>>=1){
        if(k&1)
            result = result*x;
        x = x*x;
    }
    return result;
}

int main(){
    fastio();
    ll n, m;
    matrix base(2);
    base.a = 1, base.b = 1;
    base.c = 1, base.d = 0;

    cin >> n >> m;
    vector<int> holes(m);
    for(auto &x:holes){
        cin >> x;
    }

    sort(holes.begin(), holes.end());
    while(holes.size() && holes.back()>n)
        holes.pop_back();
    ll curr = 0, a = 1, b = 0;

    if(holes.size()==0 || holes.back()!=n){
        holes.push_back(n);
        for(const auto &x:holes){
            //cout << x <<"\n";
            auto mat = fexp(base,x-curr);
            ll na = ((mat.a*a)%mod + (mat.b*b)%mod)%mod;
            ll nb = ((mat.c*a)%mod + (mat.d*b)%mod)%mod;
            curr = x;
            a = na, b = nb;
            if(x!=n)
                a = 0;
        }
    }
    else{
        a = 0;
    }

    cout << a << "\n";

    return 0;
}

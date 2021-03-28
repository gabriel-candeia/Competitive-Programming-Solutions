#include<bits/stdc++.h>
#define maxn int(8e5+20)
#define maxm 2
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
using namespace std;

ll mod;
struct Matrix{
    int mat[maxm][maxm];

    Matrix(){
        for(int i=0;i<maxm;i++)
            for(int j=0;j<maxm;j++)
                mat[i][j] = 0;
    }

    int* operator[](const int& i){
        return mat[i];
    }

    Matrix operator*(Matrix b){
        Matrix c;
        for(int i=0;i<maxm;i++)
            for(int j=0;j<maxm;j++)
                for(int k=0;k<maxm;k++)
                    c[i][j] = (c[i][j] + mat[i][k]*b[k][j])%mod;
        return c;
    }
};

const ll inf = 1e18;
Matrix st[maxn], arr[maxn], id;

Matrix build(ll p, ll l, ll r){
    if(l==r)
        return st[p] = arr[l];
    ll med = l + (r-l)/2;
    return st[p] = build(2*p,l,med)*build(2*p+1,med+1,r);
}

Matrix get(ll p, ll l, ll r, ll i, ll j){
    if(j < l || r < i)
        return id;
    else if(i<=l && r<=j)
        return st[p];
    ll med = l + (r-l)/2;
    return get(2*p,l,med,i,j)*get(2*p+1,med+1,r,i,j);
}

int main(){
    fastio();
    ll n, m, x, y;
    cin >> mod >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<maxm;j++)
            for(int k=0;k<maxm;k++)
                cin >> arr[i][j][k];

    id[0][0] = id[1][1] = 1;
    id[1][0] = id[0][1] = 0;

    build(1,0,n-1);
    for(int i=0;i<m;i++){
        cin >> x >> y;
        Matrix answ = get(1,0,n-1,x-1,y-1);
        for(int i=0;i<maxm;i++){
            for(int j=0;j<maxm;j++)
                cout << answ[i][j] << " ";
            cout<<'\n';
        }cout<<'\n';
    }
    return 0;
}
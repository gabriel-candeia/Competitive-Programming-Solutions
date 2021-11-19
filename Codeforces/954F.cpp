#include<bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9+7;

struct matrix{
    ll mat[3][3];

    matrix(bool id=false){
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                mat[i][j] = id*(i==j);
    }

    ll* operator[](int i){
        return mat[i];
    }

    matrix operator*(matrix b){
        matrix c(false);
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                for(int k=0;k<3;k++)
                    c[i][j] = (c[i][j] + (mat[i][k]*b[k][j])%mod)%mod;
        return c;
    }
};

matrix binpow(matrix c, int k){
    matrix result(true);
    while(k){
        if(k%2){
            result = result*c;
        }
        c = c*c;
        k/=2;
    }
    return result;
}

int main(){
    matrix base;

    base[0][0] = 1, base[0][1] = 1, base[0][2] = 0;
    base[1][0] = 1, base[1][1] = 1, base[1][2] = 1;
    base[2][0] = 0, base[2][1] = 1, base[2][2] = 1;

    vector<pair<ll,ll>> obstacles[3];
    ll n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        ll linha, a, b;
        cin >> linha >> a >> b;
        obstacles[linha-1].push_back({a,b});
    }

    vector<tuple<ll,ll,ll>> intervals;

    for(int i=0;i<3;i++){
        for(auto p:obstacles[i]){
            intervals.push_back({p.first,i,1});
            intervals.push_back({p.second+1,i,-1});
        }
    }

    

    ll curr = 2;
    matrix answ(1), mult = base, last = base;
    vector<int> dg(3,0);
    
    //intervals.push_back({m,0,0});
    intervals.push_back({m+1,0,0});
    sort(intervals.begin(),intervals.end());

    for(auto [tempo, linha, inc]:intervals){
        answ =  binpow(last,tempo-curr)*answ;
        dg[linha]+=inc;
        for(int i=0;i<3;i++)
            for(int j=0;j<3;j++)
                mult[i][j] = ((dg[i]==0) ? base[i][j] : 0);
        last = mult;
        curr = tempo;
    }

    cout << answ[1][1] <<"\n";

    return 0;
}
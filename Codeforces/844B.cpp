#include<bits/stdc++.h>
#define N 100
#define ll long long
using namespace std;

ll binpow(ll a, ll b){
    if(b==0){
        return 1;
    }
    ll temp = binpow(a,b/2);
    temp = temp*temp;
    if(b%2){
        return temp*a;
    }
    return temp;

}

int main(){
    int n, m;
    int mat[N][N];

    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> mat[i][j];
        }
    }

    ll answ=0;
    for(int i=0;i<n;i++){
        int qtd=0;
        for(int j=0;j<m;j++){
            qtd+=mat[i][j];
        }
        answ+=binpow(2,qtd)+binpow(2,m-qtd)-2;
    }

    for(int i=0;i<m;i++){
        int qtd=0;
        for(int j=0;j<n;j++){
            qtd+=mat[j][i];
        }
        answ+=binpow(2,qtd)+binpow(2,n-qtd)-2;
    }

    cout << answ -n*m<< '\n';

    return 0;
}
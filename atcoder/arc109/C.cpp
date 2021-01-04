#include<bits/stdc++.h>
#define ll long long
#define maxn 200
using namespace std;

int n, k, cnt=0;
string s;
char memo[maxn][maxn];

char cmp(char a, char b){
    if((a=='R' && b=='S') || (a=='S' && b=='R'))
        return 'R';
    if((a=='R' && b=='P') || (a=='P' && b=='R'))
        return 'P';
    if((a=='S' && b=='P') || (a=='P' && b=='S'))
        return 'S';
    return a;
}

ll binpow(ll x, ll y){
    ll result = 1;
    while(y){
        if(y%2)
            result = (result*x)%n;
        y/=2;
        x=(x*x)%n;
    }
    return result;
}

char winner(ll l, ll k){
    if(k==0)
        return s[l];
    if(memo[l][k]!='x')
        return memo[l][k];
    char a = winner(l,k-1), b = winner((l+binpow(2,k-1))%n,k-1);
    return memo[l][k] = cmp(a,b);
}

int main(){
    cin >> n >> k >> s;
    memset(memo,'x',sizeof(memo));
    cout << winner(0,k) <<'\n';
    return 0;
}


/*    
        S
    S           S
  S    S     P     s
 P  S p  s  P  R  S  S
RP SS PR SP PR SR PS SP*/
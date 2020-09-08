#include<bits/stdc++.h>
#define fastIO() ios_base::sync_with_stdio(false); cin.tie(NULL)
#define ll long long
using namespace std;

ll bb(ll n, ll v){
    ll l=1, r=n, med=0, answ=-1;
    while(l<=r){
        med = l + (r-l)/2;
        if((n-med+1)*(n+med)/2>=v){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }    
    return answ;
}

ll solve(ll n){
    if(n==3) return 2;
    if(n%4!=3 && n%4!=0) return 0;

    ll sum=0, cnt=0, valor = n*(n+1)/4;
    ll i=bb(n,valor);
    sum = (n-(i+1)+1)*(n+i+1)/2;
    //cout << sum <<'\n'; 
    for(;i>=0;i--){
        sum+=i;
        if(sum==valor){
            cnt+=((n-i+1)*(n-i) + (i-1)*(i-2))/2;
        }
        if(sum>valor){
            cnt+=max(min(n,sum-valor+i-1)-max(sum-valor+1,i)+1,0ll);
            if(max(min(n,sum-valor+i-1)-max(sum-valor+1,i)+1,0ll)==0){
                break;
            }
        }
    }

    return cnt;
}

ll brutar(int n){
    ll soma1=0, soma2 = n*(n+1)/2, cnt=0;
    for(int m=1;m<=n-1;m++){
        soma1 += m; soma2 -= m;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                if(i<=m && m<j){
                    soma1+= j-i;
                    soma2+= i-j;
                }
                cnt+=(soma1==soma2);
                if(i<=m && m<j){
                    soma1-= j-i;
                    soma2-= i-j;
                }
            }
        }
    }

    return cnt;
}

int main(){
    int t, n;
    fastIO();
    cin >> t;
    while(t--){
        cin >> n;
        cout << solve(n) << '\n';
    }

    return 0;
}

//1+2+3+4+5+6+7+8+9+10+11+12
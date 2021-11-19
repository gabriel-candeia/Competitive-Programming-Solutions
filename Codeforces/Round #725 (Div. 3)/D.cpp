#include<bits/stdc++.h>
using namespace std;

int solve(int x){
    int answ = 0;
    for(int i=2;i*i<=x;i++)
        while(x%i==0)
            answ++, x/=i;
    answ += (x!=1);
    return answ;
}

int main(){
    int t;

    cin >> t;
    while(t--){
        int a, b, k;
        cin >> a >> b >> k;

        if(a>b) swap(a,b);

        if(k==1){
            cout << (((b%a)==0 && b!=a) ? "Yes" : "No") <<'\n';
        }
        else{
            
            int d = __gcd(a,b), mx = solve(a/d)+solve(b/d)+2*solve(d);
            cout << ((mx>=k) ? "Yes" : "No") <<'\n';
        }


    }

    return 0;
}
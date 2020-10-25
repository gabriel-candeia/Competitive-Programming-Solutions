#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, lim, cnt=0;
    cin >> n;

    lim = sqrt(n)+1;
    for(int i=2;i<=lim;i++){
        cnt += (n%i==0);
        while(n%i==0)
            n/=i;
    }
    cnt += (n!=1);
    
    cout << pow(2,cnt) - 1 - cnt <<'\n';

    return 0;
}
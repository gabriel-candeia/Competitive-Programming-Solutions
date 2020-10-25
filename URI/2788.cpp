#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

ll n, m, len, answ = ULLONG_MAX;
ll digits[20], locked[20];

void busca_completa(ll tam, ll val){
    if(tam==-1){
        if(val%m==0){
            answ = min(answ,val);
        }
    }
    else if(locked[tam])
        busca_completa(tam-1,10ll*val+digits[tam]);
    else
        for(int i=0;i<10;i++)
            busca_completa(tam-1,10ll*val+i);
}

int main(){
    cin >> n >> m;
    for(len=0;n;len++){
        digits[len] = n%10;
        locked[len] = 1;
        n/=10;
    }

    for(int i=0;i<=5;i++){
        busca_completa(4+len,0);

       for(int j=19;j>0;j--){
            digits[j] = digits[j-1];
            locked[j] = locked[j-1];
        }locked[i] = false;
    }

    cout << answ <<'\n';

    return 0;
}

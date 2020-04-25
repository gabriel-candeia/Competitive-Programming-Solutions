#include<bits/stdc++.h>
#define N int(1e5+4)
using namespace std;

int main(){
    int n, answ=INT_MAX, gs;
    int g[N];

    cin >> n;
    for(int i=1;i<=n;i++){
        int lds = ceil(n/(1.0*i));
        if(lds+i<answ){
            answ = min(answ,lds+i);
            gs = i;
        }
    }
    

    return 0;
}
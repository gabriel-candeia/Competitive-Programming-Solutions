#include<bits/stdc++.h>
#define N int(1e6)+3
using namespace std;

int main(){
    int n, m=1000;
    cin >> n;

    vector<bool> sieve; sieve.assign(n*m+2,true);
    sieve[1] = false; sieve[2] = true;
    for(int i=2;i<=n*m+1;i++){
        if(sieve[i]){
            for(int j=2*i;j<=n*m+1;j+=i){
                sieve[j] = false;
            }   
        }
    }
    for(int i=1;i<1001;i++){
        if(sieve[n*i+1]==false){
            cout << i <<'\n';
            return 0;
        }
    }

    return 0;
}

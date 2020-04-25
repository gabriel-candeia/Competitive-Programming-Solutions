#include<bits/stdc++.h>
using namespace std;

bool ehPot(int x) {  
    return (x == (x&(-x)));  
}  

int find(int x){
    int lim = sqrt(x);
    for(int i=1;i<=lim;i++){
        if(x%i==0 && ehPot(x/i + 1)){
            return i; 
        }
        if(ehPot(i+1) && x%i==0 && i>1){
            return x/i;
        }
    }
    return -1;
}

int main(){
    int n, t;

    cin >> t;
    while(t--){
        cin >> n;
        //dado n encontrar x tal que n = x*(2^k-1) n<=10^9
        cout << find(n) <<'\n';
    }

    return 0;
}




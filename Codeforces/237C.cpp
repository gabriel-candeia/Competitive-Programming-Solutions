#include<bits/stdc++.h>
using namespace std;

vector<bool> isPrime;

void sieve(int n){
    isPrime.assign(n+1,true);
    isPrime[0] = isPrime[1] = false;

    for(int i=2;i<=n;i++){
        if(isPrime[i]){
            for(int j=2*i;j<=n;j+=i){
                isPrime[j] = false;
            }
        }
    }
}

bool isOk(int a, int b, int k, int l){
    if(l>b-a+1){
        return false;
    }

    int cnt=0;
    for(int i=a;i<=a+l-1;i++){
        cnt+=isPrime[i];
    }

    if(cnt<k){ 
        return false;
    }

    for(int x=a+1;x<=b-l+1;x++){
        cnt += -isPrime[x-1] + isPrime[x+l-1];
        if(cnt<k){ 
            return false;
        }
    }

    return true;
}


int main(){
    int a, b, k;

    cin >> a >> b >> k;

    sieve(b);

    int l=1, r=b-a+1, med=1;

    while(l<r){
        med = l + (r-l)/2;
        if(isOk(a,b,k,med)){
            r = med;
        }
        else{
            l  = med+1;
        }
    }

    med = (l + (r-l)/2);
    
    if(isOk(a,b,k,med-1)){
        cout << med-1 << '\n';
    }
    else if(isOk(a,b,k,med)){
        cout << med << '\n';
    }
    else if(isOk(a,b,k,med+1)){
        cout << med+1 << '\n';
    }
    else{
        cout << -1 << '\n';
    }

    return 0;
}
#include<bits/stdc++.h>
#define maxn 30005
using namespace std;

bool ehprimo(int x){
    for(int i=2;i*i<=x;i++)
        if(x%i==0)
            return false;
    return true;
}

int main(){
    int t;
    cin >> t;

    set<int> primes;
    for(int i=2;i<maxn;i++)
        if(ehprimo(i))
            primes.insert(i);

    while(t--){
        int d, answ=1, x;
        cin >> d;

        x = *(primes.lower_bound(1+d));    
        answ*=x;
        x = *(primes.lower_bound(x+d));
        answ*=x;
        cout << answ <<'\n';


    }



    return 0;
}
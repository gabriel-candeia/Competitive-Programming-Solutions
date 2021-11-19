#include<bits/stdc++.h>
using namespace std;

bool isPrime(int n){
    for(int i=2;i*i<=n;i++)
        if(n%i==0)
            return false;
    return true;
}

int main(){
    int l, k;
    bool answ = true;
    cin >> l >> k;
    
    if(l%2){
        if(l==1){
            answ = false;
        }
        else if(l==3){
            answ = false;
        }
        else if(k>=2){
            answ = false;
        }
        else{
            answ = false;
        }
    }
    else{
        if(l==2){
            answ = (k<=3);
        }
        else{
            answ = false;
        }
    }

    if(answ){
        cout << "Yes" << "\n";
    }
    else{
        cout << "No" << "\n";
    }
    
    return 0;
}
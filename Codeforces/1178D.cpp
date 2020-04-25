#include<bits/stdc++.h>
using namespace std;

bool ehprimo(int p){
    for(int i=2;i<p;i++){
        if(p%i==0){
            return false;
        }
    }
    return true;
}


int main(){
    int n, p;

    cin >> n;

    for(p=n;ehprimo(p)==false;p++);

    cout << p << '\n';
    for(int i=0;i<n;i++){
        cout << i+1 << " " << (i+1)%n+1 << '\n';
    }

    for(int i=0;i<p-n;i++){
        cout << i+1 << " " << (n/2+i)%n+1 << '\n';
    }

    return 0;
}
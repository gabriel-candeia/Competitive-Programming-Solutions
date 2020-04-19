#include<bits/stdc++.h>
using namespace std;

int ehprimo(int n){
    for(int i=2;i<n;i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}

int main(){
    string s;
    int squares[] = {4,9,25,49};
    bool isNotPrime = false;
    int cnt=0;
    
    for(int i=0;i<4;i++){
        cout << squares[i] << '\n' << flush;
        cin >> s;
        isNotPrime = isNotPrime || (s=="yes");
    }

    for(int i=2;i<=50;i++){
        if(ehprimo(i)){
            cout << i << '\n' << flush;
            cin >> s;
            cnt += (s=="yes");
        }
    }

    isNotPrime = isNotPrime || (cnt>=2);

    cout << ((isNotPrime) ? "composite" : "prime") << '\n';
    return 0;
}
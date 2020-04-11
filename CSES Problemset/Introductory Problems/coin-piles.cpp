#include<bits/stdc++.h>
using namespace std;

int main(){
    long int t, a, b, maior, menor;
    cin >> t;
    while(t--){
        cin >> a >> b;
        maior = max(a,b);
        menor = min(a,b);
        if(((2*menor-maior)%3) || (menor==0 && maior!=0 || maior>2*menor)){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }

    return 0;
}
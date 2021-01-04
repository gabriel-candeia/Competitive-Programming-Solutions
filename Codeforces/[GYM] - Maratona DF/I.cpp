#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    string s;
    float h, imc;
    int m;

    cin >> s;
    m = (s[2]-'0')*10 + (s[3]-'0')*1;
    h = stof(s);
    
    imc = m/(h*h);
    if(imc>=18.5 && imc<=24.9){
        cout << "Sim\n";
    }
    else{
        cout << "Nao\n";
    }

    return 0;
}
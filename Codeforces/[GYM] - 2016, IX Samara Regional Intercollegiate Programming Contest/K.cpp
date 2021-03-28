#include<bits/stdc++.h>
using namespace std;

bool ehpalindromo(string s){
    int l = 0, r = s.size()-1;
    while(l < r){
        if(s[l] != s[r]){
            return false;
        }
        ++l; --r;
    }
    return true;
}

int main(){
    int n;
    string s;

    cin >> s;
    n = s.size();
    
    bool answ = 0;
    int pos = n+1;
    for(int i=0;i<n;i++){
        if(s[i]!=s[n-1-i]){
            pos = i;
            break;
        }
    }
        
    if(pos==n+1)
        pos = n/2;
    answ = ehpalindromo(s.substr(0,pos) + s.substr(pos+1));

    if(answ==false){
        pos = n-1-pos;
        answ = ehpalindromo(s.substr(0,pos) + s.substr(pos+1));
    }
    
    if(answ){
        cout << "YES\n";
        cout << pos+1  << "\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}


//Palindomo Par e tiver todas as letras iguais - Tira qualquer letra
//Palindromo Impar - Tira a letra central
//aarbbraa            ab-ba
//s[0]s[1]...s[n-2]s[n-1], s[i] = s[n-i], 
//se i>retirado s[i] = s[n-i] = s[n-(i-1)] = s[i-1]
//se i < retirado não muda nada
//abcdxxxxxxdcba
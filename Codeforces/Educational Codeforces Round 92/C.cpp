#include<bits/stdc++.h>
using namespace std;

int teste(string s, char a, char b){
    int rem = 0, n=s.size();
    char prox = a;
    for(int i=0;i<n;i++){
        if(s[i]==prox){
            prox = ((prox==a) ? b : a);
        }
        else{
            rem++;
        }
    }
    if(prox==b && b!=a){
        rem++;
    }
    return rem;
}

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        int answ = s.size();
        for(char i='0';i<='9';i++){
            for(char j='0';j<='9';j++){
                answ = min(answ,teste(s,i,j));
            }
        }
        cout << answ <<'\n';
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

bool ehvogal(char x){
    return (x=='a' || x=='e' || x=='o' || x=='i' || x=='u');
}

int main(){
    string s="";
    char x;

    while(cin >> x){
        if(ehvogal(x)){
            s+=x;
        }
    }

    int n = s.size();
    bool poss = true;
    for(int i=0;i<n/2;i++){
        poss *= (s[i]==s[n-i-1]);
    }

    cout << ((poss) ? "S" : "N") << '\n';

    return 0;
}
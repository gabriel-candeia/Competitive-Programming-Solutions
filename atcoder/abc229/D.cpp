#include<bits/stdc++.h>
using namespace std;

int n, k;
string s;

int isok(int x){
    int acm = 0;
    for(int i=0;i<x;i++){
        acm += s[i]=='.';
    }

    bool answ = acm<=k;
    for(int i=x;i<n && answ==false;i++){
        acm += (s[i]=='.')-(s[i-x]=='.');
        answ = (answ || (acm<=k));
    }
    return answ;
}

int bb(){
    int l = 0, r=n, med, answ = -1;
    while(l<=r){
        med = (l+r)/2;
        if(isok(med)){
            answ = med;
            l = med+1;
        }
        else{
            r = med-1;
        }
    }
    return answ;
}


int main(){
    cin >> s >> k;
    n = s.size();

    cout << bb() <<'\n';

    return 0;
}
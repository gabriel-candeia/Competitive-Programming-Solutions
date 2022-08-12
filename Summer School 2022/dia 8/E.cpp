#include<bits/stdc++.h>
#define ll long long
#define maxn int(1e7+5)
using namespace std;

int isPrime[maxn];
void precomp(){
    isPrime[0] = isPrime[1] = 1;
    for(ll i=2;i<maxn;i++){
        if(isPrime[i]==0){
            for(ll j=i*i;j<maxn;j+=i){
                isPrime[j] = 1;
            }
        }
    }
}

int converte(string s){
    string inteiro, decimal;
    bool flag = false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='.'){
            flag = true;
        }
        else if(flag){
            decimal.push_back(s[i]);
        }
        else{
            inteiro.push_back(s[i]);
        }
    }
    while(decimal.size()<5){
        decimal.push_back('0');
    }

    int acm = 0;
    for(auto c:inteiro)
        acm = 10*acm + (c-'0');
    for(auto c:decimal)
        acm = 10*acm + (c-'0');
    return acm;
}

int main(){
    precomp();
    int t;

    cin >> t;
    while(t--){
        int a=0, b=0;
        string sa, sb;
        cin >> sa >> sb;
        
        a = converte(sa), b = converte(sb);
        int d = __gcd(a,b);
        a/=d, b/=d;

        if((isPrime[a]==0 && isPrime[b]==0) || a==b){
            if(a==1) a = 2, b = 2;
            cout << a << " " << b <<"\n";
        }
        else{
            cout << "impossible\n";
        }
    }

    return 0;
}
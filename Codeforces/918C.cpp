#include<bits/stdc++.h>
#define N 5005
using namespace std;

int cnt[N][N];

int main(){
    int n, acm=0, qtd=0, answ=0;
    string s;

    cin >> s;
    n = s.size();
    for(int j=0;j<n;j++){
        qtd = 0; acm = 0;
        for(int i=j;i<n;i++){
            qtd += (s[i]=='?');
            acm += (s[i]=='(') - (s[i]==')');
            if(acm+qtd<0)
                break;
            if((qtd-abs(acm))%2==0 && qtd-abs(acm)>=0)
                cnt[j][i]++;
        }
    }
    for(int j=0;j<n;j++){
        qtd = 0; acm = 0;
        for(int i=j;i<n;i++){
            qtd += (s[n-i-1]=='?');
            acm += (s[n-i-1]==')') - (s[n-i-1]=='(');
            if(acm+qtd<0)
                break;
            if((qtd-abs(acm))%2==0 && qtd-abs(acm)>=0){
                cnt[n-i-1][n-j-1]++;
                answ += (cnt[n-i-1][n-j-1]==2);
            }
        }
    }
    cout << answ <<'\n';
    return 0;
}
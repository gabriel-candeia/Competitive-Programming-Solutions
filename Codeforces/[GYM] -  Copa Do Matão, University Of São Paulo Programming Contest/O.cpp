#include <bits/stdc++.h>
#define maxn int(4e6+5)
using namespace std;

vector<int> primos;
int sieve[maxn];
void precomp(){
    sieve[0] = sieve[1] = 1;
    for(int i=2;i<maxn;i++){
        if(sieve[i]==0){
            primos.push_back(i);
            for(int j=i;j<maxn;j+=i){
                sieve[j] = i;
            }
        }
    }
}

vector<int> fatoraImpar(int x){
    vector<int> answ;
    while(x>1){
        int fator = sieve[x], cnt=0;
        while(sieve[x]==fator){
            cnt = 1-cnt;
            x/=sieve[x];
        }
        if(cnt) answ.push_back(fator);
    }
    sort(answ.begin(),answ.end());
    return answ;
}

int contar(int x, int n){
    int pot = x, answ=0;
    while(pot<=n){
        answ += (n/pot);
        pot = pot*x;
    }   
    return answ;
}

vector<int> fatorarFatorial(int n){
    vector<int> answ;
    for(auto x:primos){
        int z = contar(x,n);
        if(z&1){
            answ.push_back(x);
        }
        if(z==0) break;
    }
    return answ;
}

vector<int> combina(vector<int>& a, vector<int> &b){
    vector<int> c;
    while(a.size() && b.size()){
        if(a.back()>b.back()){
            c.push_back(a.back());
            a.pop_back();
        }
        else if(b.back()>a.back()){
            c.push_back(b.back());
            b.pop_back();
        }
        else{
            b.pop_back(), a.pop_back();
        }
    }
    while(a.size()){
        c.push_back(a.back());
        a.pop_back();
    }
    while(b.size()){
        c.push_back(b.back());
        b.pop_back();
    }
    reverse(c.begin(),c.end());
    return c;
}

struct token{
    bool tipo;
    int val;
};

vector<token> tokenizer(string s){
    vector<token> answ;
    int num = 0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='^' || s[i]=='*' || s[i]=='!'){
            answ.push_back({1,s[i]});
        }
        else{
            num = 10*num + s[i]-'0';
            if(i+1==s.size() || s[i+1]>'9' || s[i+1]<'0'){
                answ.push_back({0,num});
                num = 0;
            }
        }
    }
    return answ;
}

struct noh{
    bool ehpar;
    vector<int> fatores;

    noh(char op, noh& a, noh& b){
        if(op=='*'){
            fatores = combina(a.fatores,b.fatores);
            ehpar = a.ehpar || b.ehpar;
        }
        else if(op=='^'){
            if(b.ehpar==1){
                swap(fatores,a.fatores);
            }
            ehpar = a.ehpar;
        }
    }
};

int main(){
    precomp();
    string s;
    //cin >> s;

    int mx = 0;
    for(int i=1;i<=100000;i++){
        auto x  = fatorarFatorial(i);
        mx = max(mx,(int)x.size());
    }

    cout << mx <<"\n";

    return 0;
}

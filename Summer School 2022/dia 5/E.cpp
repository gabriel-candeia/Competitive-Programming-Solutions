#include<bits/stdc++.h>
#define maxn int(1e6+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int k;
string s;
int p[maxn], valor[maxn];
vector<char> aux;

void precomp(int p){
    if(p>=aux.size())
        valor[p] = 1;
    else{
        precomp(2*p);
        precomp(2*p+1);
        if(aux[p]=='0')
            valor[p] = valor[2*p];
        else if(aux[p]=='1')
            valor[p] = valor[2*p+1];
        else
            valor[p] = valor[2*p]+valor[2*p+1];
    }
}

void update(int p){
    while(p!=0){
        if(aux[p]=='0')
            valor[p] = valor[2*p];
        else if(aux[p]=='1')
            valor[p] = valor[2*p+1];
        else
            valor[p] = valor[2*p]+valor[2*p+1];
        p/=2;
    }
}

int main(){
    fastio();
    cin >> k;
    cin >> s;
    map<int,int> preguica;

    int l = 0;
    for(int pot=k-1;pot>=0;pot--){
        vector<char> temp;
        vector<int> id;
        for(int j=(1<<pot);j>0;j--){
            temp.push_back(s[l]);
            id.push_back(l+1);
            l++;
        }
        reverse(temp.begin(),temp.end());
        reverse(id.begin(),id.end());
        for(int i=0;i<temp.size();i++){
            preguica[id[i]] = aux.size();
            aux.push_back(temp[i]);
        }
    }

    aux.push_back(' ');
    reverse(aux.begin(),aux.end());
    for(auto &p:preguica){
        p.second = aux.size() - p.second-1;
        //cout << p.first <<" " << p.second <<"\n";
    }
    precomp(1);

    int q;
    cin >> q;
    while(q--){
        int pos;
        char ch, original;

        cin >> pos >> ch;
        //cout << pos <<"  " << preguica[pos] <<"\n";
        original = aux[preguica[pos]];
        aux[preguica[pos]] = ch;
        update(preguica[pos]);

        cout << valor[1] << "\n";

    }
    

    return 0;
}
    
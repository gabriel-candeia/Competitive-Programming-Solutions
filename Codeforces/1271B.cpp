#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> answ;
    string s;

    cin >> n >> s;

    for(int i=0;i+1<n;i++){
        if(s[i]=='B'){
            answ.push_back(i+1);
            s[i] = 'W', s[i+1] = ((s[i+1]=='B') ? 'W' : 'B');
        }
    }

    int qtd = 0;
    for(int i=0;i<n;i++){
        qtd+=s[i]=='W';
    }

    bool ok = false;
    if(qtd%2==0){
        ok = true;
        for(int i=0;i<n;i+=2){
            if(s[i]=='W'){
                answ.push_back(i+1);
            }
        }
    }
    if((n-qtd)%2==0){
        ok = true;
        for(int i=qtd;i<n;i+=2){
            if(s[i]=='B'){
                answ.push_back(i+1);
            }
        }
    }

    if(ok){
        cout << answ.size() << "\n";
        for(auto x:answ)
            cout << x << " ";
        if(answ.size())
            cout<<"\n";
    }
    else{
        cout << -1 <<"\n";
    }

    return 0;
}
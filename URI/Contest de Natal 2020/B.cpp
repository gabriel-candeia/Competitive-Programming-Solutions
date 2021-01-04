#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<string,int> qtd, cnt;
    qtd["bonecos"] = 8;
    qtd["arquitetos"] = 4;
    qtd["musicos"] = 6;
    qtd["desenhistas"] = 12;

    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        int x;
        cin >> s >> s >> x;
        cnt[s]+=x;
    }

    int answ = 0;
    for(auto p:cnt){
        answ+= p.second/qtd[p.first];
    }
    cout<< answ <<'\n';

    return 0;
}
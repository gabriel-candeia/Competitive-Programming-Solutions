#include<bits/stdc++.h>
using namespace std;

int main(){
    map<string,string> ultimo;
    map<string,int> cnt;
    vector<string> impostor;
    string s, t;

    int n, m;
    cin >> n >> m;
    for(int i=0;i<n;i++){
        cin >> s >> t;
        if(ultimo.find(s)==ultimo.end()){
            ultimo[s] = "sudoeste";
            cnt[s] = 1;
        }
        if(ultimo[s]=="fim")
            continue;
        if(cnt[s]==1 && t!=ultimo[s]){
            impostor.push_back(s);
            ultimo[s] = "fim";
            cnt[s] = 0;
            continue;
        }
        cnt[s]=(cnt[s]+1)%2;
        ultimo[s] = t;
    }

    for(auto p: impostor){
        cout << p << "\n";
    }

    return 0;
}
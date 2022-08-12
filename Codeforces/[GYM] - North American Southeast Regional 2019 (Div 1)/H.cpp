#include<bits/stdc++.h>
using namespace std;

int main(){
    string t, s;
    int n;
    set<string> answ;

    cin >> s >> t;
    n = t.size();

    for(int i=0;i<=n;i++){
        for(auto c:s){
            answ.insert(t.substr(0,i)+string(1,c)+t.substr(i));
        }
    }

    for(int i=0;i<n;i++){
        for(auto c:s){
            if(c!=t[i]){
                answ.insert(t.substr(0,i)+string(1,c)+t.substr(i+1));
            }
        }
    }

    for(int i=0;i<n;i++){
        answ.insert(t.substr(0,i)+t.substr(i+1));
    }

    for(auto c:answ)
        cout << c <<"\n";
    
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    map<char,char> mp;
    char curr = 'a';

    cin >> s;
    for(auto c:s){
        if(mp.find(c)==mp.end()){
            mp[c] = curr++;
        }
        cout << mp[c] << "";
    }
    cout<<'\n';


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set<string> answ;
    string s, normal;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        normal = s;
        for(int i=0;i<s.size();i++){
            rotate(s.begin(), s.begin() + 1, s.end());
            if(s<normal) normal = s;
        }    
        answ.insert(normal);
    }

    cout << answ.size() <<"\n";

    return 0;
}
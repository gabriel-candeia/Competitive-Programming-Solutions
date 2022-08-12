#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;

    cin >> n;
    cin >> s;
    int answ = 0;
    for(int i=0;i<n;i++){
        if(i+1<s.size() && s[i]!=s[i+1]){
            answ++;
            i++;
        }
    }

    cout <<answ<<"\n";

    return 0;
}
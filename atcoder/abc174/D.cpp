#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;

    cin >> n >> s;

    int red = 0, answ=0;
    for(int i=0;i<n;i++){
        red += (s[i]=='R');
    }
    for(int i=0;i<red;i++){
        answ += (s[i]=='W');
    }
    cout << answ <<'\n';
    return 0;
}
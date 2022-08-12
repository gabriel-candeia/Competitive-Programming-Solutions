#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;

    cin >> a >> b;
    bool poss = false;
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    for(int i=0;i<min(a.size(),b.size());i++){
        poss = poss || ((a[i]-'0')+(b[i]-'0')>=10);
    }

    if(poss)
        cout << "Hard" <<"\n";
    else
        cout << "Easy" <<"\n";

    return 0;
}
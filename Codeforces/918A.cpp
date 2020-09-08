#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a=0, b=1, c;
    map<int,bool> cnt;

    while(a<=1000){
        cnt[a] = true;
        c = a+b;
        a = b;
        b = c;
    }

    cin >> n;
    for(int i=1;i<=n;i++)
        cout << ((cnt[i]) ? "O" : "o");
    cout << '\n';

    return 0;
}
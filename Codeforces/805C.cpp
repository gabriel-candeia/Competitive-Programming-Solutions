#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, answ = 0;
    cin >> n;

    if(n%2==0)
        answ = n/2-1;
    else
        answ = n/2;

    cout << answ <<"\n";

    return 0;
}

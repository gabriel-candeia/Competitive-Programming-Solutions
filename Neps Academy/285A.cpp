#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, d;

    cin >> n >> d >> a;

    cout << ((d-a)%n+n)%n << '\n';  

    return 0;
}
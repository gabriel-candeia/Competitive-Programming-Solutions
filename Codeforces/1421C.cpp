#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int n;

    cin >> s;
    n = s.size();

    cout << 3 << '\n';
    cout << "L " << 2 << '\n';
    cout << "R " << 2 << '\n';
    cout << "R " << 2*n-1 << '\n';

    return 0;
}
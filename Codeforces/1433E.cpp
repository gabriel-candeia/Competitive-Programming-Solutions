#include<bits/stdc++.h>
#define ll unsigned long long
using namespace std;

int main(){
    ll n, fat=1;
    cin >> n;
    for(int i=1;i<=n;i++)
        fat*=i;
    fat /= (n/2);
    fat /= (n/2);
    fat /= 2;
    cout << fat <<'\n';
    return 0;
}
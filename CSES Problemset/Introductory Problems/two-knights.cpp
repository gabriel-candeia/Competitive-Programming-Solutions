#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    long long int j;
    cin >> n;
    for(long long int i=1;i<=n;i++){
        j = i*i;
        cout << (j*(j-1))/2 - 4*(i-1)*(i-2)  << '\n';
    }

    return 0;
}
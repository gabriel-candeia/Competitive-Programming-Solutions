#include<bits/stdc++.h>
using namespace std;

int main(){
    long long int n, sum, a;

    cin >> n;
    sum = (n*(n+1))/2;
    for(int i=0;i<n-1;i++){
        cin >> a;
        sum-=a;
    }
    cout << sum <<'\n';
    return 0;
}
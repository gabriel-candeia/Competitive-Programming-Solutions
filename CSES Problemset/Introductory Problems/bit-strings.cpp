#include<bits/stdc++.h>
using namespace std;

const int M = int(1e9)+7;

long int modex(int a, int b,int m){
    if(b==0){
        return 1;
    }
    long int temp = modex(a,b/2,m)%m;
    if(b%2){
        return (((temp*temp)%m)*a)%m;
    }
    return (temp*temp)%m;
}

int main(){
    int n;
    cin >> n;
    cout << modex(2,n,M) << '\n';

    return 0;
}
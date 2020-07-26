#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0;
    int answ=0;
    vector<int> digitos;

    cin >> n;
    while(n){
        digitos.push_back(n%10);
        n/=10;
    }
    digitos.push_back(0);

    n = digitos.size();
    for(int i=n-1;i>=1;i--){
        answ+=min({abs(digitos[i]-digitos[i-1]),digitos[i]-digitos[i-1]+10,digitos[i-1]-digitos[i]+10});
    }
    cout << answ << '\n';

    return 0;
}
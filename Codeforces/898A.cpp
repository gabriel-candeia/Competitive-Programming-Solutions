#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;

    cin >> n;

    if(n%10<10-n%10){
        cout << n-n%10 <<'\n';
    }
    else{
        cout << n+10-n%10 <<'\n';
    }
    return 0;
}
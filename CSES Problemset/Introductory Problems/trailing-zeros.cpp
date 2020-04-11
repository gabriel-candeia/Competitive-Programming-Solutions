#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, answer=0;
    cin >> n;
    for(long int i=5;i<=n;i*=5){
        answer+= n/i;
    }
    cout << answer   << '\n';
    return 0;
}
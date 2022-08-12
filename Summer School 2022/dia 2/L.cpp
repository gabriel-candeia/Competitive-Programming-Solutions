#include<bits/stdc++.h>
#define ld double
using namespace std;

int main(){
    int n, h;

    cin >> n >> h;
    for(int i=1;i<n;i++){
        cout << fixed  << setprecision(10) << h*sqrt(i*1.0/n) <<"\n";
    }
    //A = h/2n
    return 0;
}
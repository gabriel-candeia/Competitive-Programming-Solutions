#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, h, x, answ=0;

    cin >> n >> h;
    for(int i=0;i<n;i++){
        cin >> x;
        answ += ((x<=h) ? 1 : 2);
    }

    cout << answ << "\n";

    return 0;
}
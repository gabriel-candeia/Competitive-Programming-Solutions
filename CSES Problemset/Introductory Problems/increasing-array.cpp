#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, x, lx;
    long long int answer = 0;

    cin >> n;
    cin >> lx;

    for(int i=1;i<n;i++){
        cin >> x;
        answer += max(0,lx-x);
        lx = max(lx,x);
    }
    cout << answer << '\n';

    return 0;
}
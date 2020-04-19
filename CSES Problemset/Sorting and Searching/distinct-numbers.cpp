#include<bits/stdc++.h>
#define N int(2e5+3)
using namespace std;

int main(){
    int n, x[N], answ=1;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    sort(x,x+n);

    for(int i=1;i<n;i++){
        answ+=(x[i]!=x[i-1]);
    }

    cout << answ << '\n';

    return 0;
}
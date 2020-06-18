#include<bits/stdc++.h>
using namespace std;

void paint(int ci, int cj){
    cout << ci << " " << cj << '\n';
    cout << ci-1 << " " << cj << '\n';
    cout << ci << " " << cj-1 << '\n';
}

int main(){
    int n, ci, cj;
    
    cin >> n;
    cout << 3*n+4 << '\n';

    ci = 1;
    cj = 1;
    cout << 0 <<" "<< 0 <<'\n';
    for(int i=0;i<n;i++){
        paint(ci,cj);
        ci++;
        cj++;
    }
    paint(ci,cj);

    return 0;
}   
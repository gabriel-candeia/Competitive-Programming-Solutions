#include<bits/stdc++.h>
#define N int(2e5+3)
using namespace std;

int main(){
    int n, x, p[N];

    cin >> n >> x;
    for(int i=0;i<n;i++){
        cin >> p[i];
    }

    sort(p,p+n);
    int r=n-1,l=0, answ=0;
    while(l<=r){
        answ++;
        if(p[r]+p[l]<=x){
            r--;
            l++;
        }
        else{
            r--;
        }
    }

    cout << answ << '\n';

    return 0;
}
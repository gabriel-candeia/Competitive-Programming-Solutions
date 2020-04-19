#include<bits/stdc++.h>
#define N int(2e5+3)
using namespace std;

int main(){
    int n, m, k, a[N], b[N];

    cin >> n >> m >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    for(int i=0;i<m;i++){
        cin >> b[i];
    }

    sort(a,a+n);
    sort(b,b+m);

    int l=0,r=0,answ=0;
    while(l<n && r<m){
        if(a[l]-k <= b[r] && b[r] <= a[l]+k){
            answ++;
            l++;
            r++;
        }
        else if(a[l]-k > b[r]){
            r++;
        }
        else if(a[l]+k < b[r]){
            l++;
        }
    }

    cout << answ << '\n';

    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, n, l1, r1, l2, r2,  k;

    cin >> t;
    while(t--){
        cin >> n >> k;
        cin >> l1 >> r1;
        cin >> l2 >> r2;
        ll dist=0, intersec=0, obt, answ;
        if(r2<l1){
            dist =  l1-r2;
        }
        else if(r1<l2){
            dist =  l2-r1;
        }
        if(max(l1,l2) <= min(r1,r2)){
            intersec = min(r1,r2)-max(l1,l2)+1+1;
        }
        obt = min(r2-l2+1,r1-l1+1)-intersec;
        answ = intersec*n;
        ll cnt=0, it = (k-answ)/obt;
        cnt = it*(obt+dist) + ((k-answ)%obt+dist)*((k-answ)%obt!=0);
        cout << cnt <<'\n';
    }
    return 0;
}
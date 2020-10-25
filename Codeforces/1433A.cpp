#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int x, answ=0;
        cin >> x;
        int acm=0;
        for(int i=1;i<=x%10;i++){
            int lim = ((i==x%10) ? x : 10000);
            for(int j=1, acm=i;acm<=lim;acm=acm*10+i,j++){
                answ+=j;
            }
        }
        cout << answ <<'\n';
    }

    return 0;
}
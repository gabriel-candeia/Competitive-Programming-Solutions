#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int a, b;
        cin >> a;
        if(a==-1) break;
        cin >> b;

        int answ = 0;
        b = (b-1)*2+1;
        for(int i=0;i<a;i++){
            answ = answ*2 + b%2;
            b/=2;
        }

        cout << answ <<"\n";
    }

    return 0;
}

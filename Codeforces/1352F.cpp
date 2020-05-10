#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n0, n1, n2;

    cin >> t;
    while(t--){
        cin >> n0 >> n1 >> n2;
        string s0 = string(n0+1,'0'), s2 = string(n2+1,'1'), answ;
        if(n1==0){
            answ = ((n2) ? s2 : s0);
        }
        else{
            answ = s2 + s0;
            for(int i=0;i<n1-1;i++){
                answ+= (i%2) ? '0' : '1';
            }
        }
        cout << answ << '\n';
    }

    return 0;
}
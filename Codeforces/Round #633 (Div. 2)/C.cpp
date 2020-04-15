#include<bits/stdc++.h>
using namespace std;

int main(){
    int prev, curr, diff, n, t;
    cin >> t;
    while(t--){
        int answ = 0;
        cin >> n;
        cin >> prev;
        for(int i=1;i<n;i++){
            cin >> curr;
            diff = curr-prev;
            if(diff<0){
                answ = max(answ,int(1+log2(-diff)));
            }
            else{
                prev = curr;    
            }
        }
        cout << answ << '\n';
    }
    return 0;
}
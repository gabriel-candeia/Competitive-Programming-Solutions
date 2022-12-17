#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> arr(n,0);
        int zero = 0, one = 0;
        for(auto &x:arr)
            cin >> x, zero += x==0, one += x==1;
        
        int seenZero = 0, seenOne = 0;
        int answ = min(zero,one);
        for(auto x:arr){
            seenZero += (x==0), seenOne += (x==1);
            if(seenOne != one){
                answ = min(answ,seenOne+ max(zero-seenZero-seenOne,0));
            }
        }

        cout << answ <<"\n";
    }

    return 0;
}
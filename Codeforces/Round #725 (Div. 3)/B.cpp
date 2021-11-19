#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, acm=0;
        vector<int> arr;

        cin >> n;
        arr.assign(n,0);
        for(auto &x:arr) cin >> x, acm+=x;

        int answ;
        if(acm%n==0){
            acm/=n;
            answ = 0;
            for(auto x:arr) if(x>acm) answ++;
            
        }
        else{
            answ = -1;
        }
        cout << answ <<"\n";
    }

    return 0;
}
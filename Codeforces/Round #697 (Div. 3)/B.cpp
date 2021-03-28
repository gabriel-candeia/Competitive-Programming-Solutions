#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int t;
    cin >> t;
    while(t--){
        int n;
        bool poss = false;
        cin >> n;
        while(n>=0){
            if(n%2021==0)
                poss = true;
            n-=2020;
        }
        if(poss)
            cout << "YES\n";
        else
            cout << "NO\n";
    }


    return 0;
}
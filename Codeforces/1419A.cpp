#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;

        cin >> n >> s;

        int ok=0;
        for(int i=(n+1)%2;i<n;i+=2){
            ok += ((s[i]-'0')%2 != (n+1)%2);
        }
        if(ok){
            cout << (n+1)%2+1 <<'\n';
        }
        else{
            cout << (n)%2+1 <<'\n';
        }
    }


    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << "9";
        if(n>1)
            cout << "8";
        if(n>2)
            cout << "9";
        n-=3;
        for(int i=0;i<n;i++){
            cout << (i)%10;
        }cout<<'\n';
    }
    return 0;
}
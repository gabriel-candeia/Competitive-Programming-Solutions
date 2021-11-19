#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        string s;

        cin >> n >> s;
        
        int acm = 0;
        for(int i=0;i<n;i++){
            
            acm += ((s[i]!='0') ? (s[i]+1-'0') : 0);
        }

        if(s[n-1]!='0')
            acm--;

        cout << acm  << "\n";
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, caso=0;
    cin >> t;
    while(t--){
        string s, answ;
        cin >> s;
        
        int n = s.size(), ptr = 0;
        answ = s;
        for(int i=0;i<n;i++, ptr++){
            string cmp = answ.substr(0,ptr) + string(1,s[i]) + answ.substr(ptr);
            if(cmp<answ){
                answ = cmp;
                ptr++;
            }
        }
        
        cout << "Case #" << ++caso <<": "<< answ << "\n";
    }
    
    return 0;
}
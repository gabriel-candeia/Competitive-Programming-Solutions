#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, x, n;
    string s, w, s1;

    cin >> t;
    while(t--){
        cin >> s >> x;
        n = s.size();
        w = string(n,'0');
        s1 = string(n,'0');
        
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                if(i-x>=0)
                    w[i-x] = '1';
                if(i+x<n)
                    w[i+x] = '1';
            }
        }

        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(i-x>=0)
                    w[i-x] = '0';
                if(i+x<n)
                    w[i+x] = '0';
            }
        }

        for(int i=0;i<n;i++){
            if(w[i]=='1'){
                if(i-x>=0)
                    s1[i-x] = '1';
                if(i+x<n)
                    s1[i+x] = '1';
            }
        }
    
        if(s1!=s){
            cout << -1 <<'\n';
        }
        else{
            cout << w << "\n";
        }
    }

    return 0;
}
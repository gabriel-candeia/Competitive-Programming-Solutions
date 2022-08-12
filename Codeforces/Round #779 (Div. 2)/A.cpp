#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        string s;
        cin >>  n >> s;

        int answ = 0;
        for(int i=0;i<n;i++){
            if(s[i]=='0'){
                if(i+2<n && s[i+1]=='1' && s[i+2]=='0'){
                    answ+=1;
                }
                else if(i+1<n && s[i+1]=='0'){
                    answ += 2;
                }
            }
        }

        cout << answ << "\n";
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        string s;
        int n;
        vector<bool> safe(n+1,false);
        cin >> n >> s;
        bool f1 = false, f2 = false;
        for(int i=0;i<n;i++){
            if(s[i]=='-'){
                safe[i] = true;
                safe[(i+1)%n] = true;
            }
            if(s[i]=='>')
                f1 = true;
            if(s[i]=='<')
                f2 = true;
        }

        if(!f1||!f2)
            for(int i=0;i<n;i++)
                safe[i] = true;
        
        int answ=0;
        for(int i=0;i<n;i++)
            answ += safe[i];

        cout << answ <<'\n';
    }

    return 0;
}
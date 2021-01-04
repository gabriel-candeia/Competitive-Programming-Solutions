#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    string s; 
    
    cin >> t;
    while(t--){
        cin >> s;
        vector<bool> existe(27,0), apareceu(27,0);
        int n = s.size();
        for(auto c:s)
            existe[c-'a'] = 1;
        char a='0',b='0';
        
        for(int i=0;i<n;i++){
            char pivot = s[i];
            for(int j='a';j<='z';j++){
                if(j<pivot &&!apareceu[j-'a'] && existe[j-'a']){
                    a = s[i];
                    b = j;
                    pivot = j;
                }
            }
            if(a!='0')
                break;
            apareceu[s[i]-'a'] = 1;
        }
        for(auto &c:s){
            if(c==a)
                c = b;
            else if(c==b)
                c = a;
        }
        
        cout << s <<'\n';
    }
}
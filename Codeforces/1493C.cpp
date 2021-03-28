#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, k;
        string s, answ="-1";
        cin >> n >> k >> s;  
        
        vector<int> freq(30,0);    
        for(auto c:s)
            freq[c-'a']++;
        
        answ = s;
        for(auto x:freq){
            if(x%k){
                answ = "-1";
                break;
            }
        }
        
        bool ok  = false;
        if(answ=="-1" && n%k==0){
            for(int i=s.size()-1;!ok && i>=0;i--){
                freq[s[i]-'a']--;
                int acm = 0, tam = s.size()-i-1;
                for(int j=s[i]-'a'+1;j<26;j++){
                    acm = 0;
                    freq[j]++;
                    for(auto x:freq)
                        acm += (k-x%k)%k;                    
                    if(acm<=tam && (tam-acm)%k==0){
                        string x =  string(tam-acm,'a');
                        for(int l=0;l<30;l++)
                            if(freq[l]%k)
                                x += string((k-freq[l]%k),l+'a');
                        sort(x.begin(),x.end());
                        answ = s.substr(0,i) + string(1,char(j+'a')) + x;
                        ok = true;
                        break;
                    }
                    freq[j]--;
                }
            }
        }
        cout << answ <<'\n';
    }


    return 0;
}
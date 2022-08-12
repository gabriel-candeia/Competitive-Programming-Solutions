#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        string s;
        cin >> s;
        int n = s.size();
        vector<int> freq(30,0);

        int fst = n;
        for(int i=n-1;i>=0;i--){
            if(freq[s[i]-'a']==0){
                fst = i;
            }
            freq[s[i]-'a']++;
        }

        cout << s.substr(fst) <<"\n";

    }


}
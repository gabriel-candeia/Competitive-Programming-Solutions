#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, caso = 0;
    set<char> vogais; 
    vogais.insert('A'), vogais.insert('E'), vogais.insert('I'), vogais.insert('O'), vogais.insert('U');
    cin >> t;
    while(t--){
        string s;

        cin >> s;
        
        vector<int> freq(30,0);

        for(auto c:s){
            freq[c-'A']++;
        }

        int mx = 0, mx1=0;
        for(int i='A';i<='Z';i++){
            if(vogais.find(i)!=vogais.end()){
                mx = max(mx,freq[i-'A']);
            }
            else{
                mx1 = max(mx1,freq[i-'A']);
            }
        }

        int answ = 0, answ1 = 0;
        for(int i='A';i<='Z';i++){
            if(vogais.find(i)!=vogais.end()){
                answ += freq[i-'A'];
            }
            else{
                answ1+=freq[i-'A'];
            }
            answ += freq[i-'A'];
            answ1+= freq[i-'A'];
        }
        answ -= 2*mx;
        answ1 -= 2*mx1;

        cout << "Case #" << ++caso << ": " << min(answ,answ1) <<"\n";

       
    }

    return 0;
}
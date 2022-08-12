#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    map<char,map<int,int>> freq;
    queue<pair<char,char>> q;

    cin >> n;
    int answ = 1e8;
    for(int i=1;i<=n;i++){
        string s;
        cin >> s;
        pair<char,char> card = {s[0],s[1]};
        
        if(q.size()>=9){
            auto t = q.front(); q.pop();
            freq[t.first][t.second]--;
            if(freq[t.first][t.second]==0)
                freq[t.first].erase(freq[t.first].find(t.second));
        }

        q.push(card);
        freq[card.first][card.second]++;
        if(freq[card.first].size()==3)
            answ = min(answ,i);
    }

    if(answ==1e8)
        answ = -1;

    cout << answ <<"\n";

    return 0;   
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    string s, t;
    int cnt=0, freqS[26], freqT[26];
    priority_queue<pair<int,int>> h;
    pair<int,int> u;
    vector<pair<char,int>> arr;

    for(int i=0;i<26;i++){
        freqS[i] = 0;
        freqT[i] = 0;
    }

    cin >> s >> t;
    for(auto c: s){
        if(c!='?'){
            freqS[c-'a']++;
        }
        else{
            cnt++;
        }
    }

    for(auto c: t){
        freqT[c-'a']++;
    }

    for(int i=0;i<26;i++){
        if(freqT[i]){
            h.push({-freqS[i]/freqT[i],i});
        }
    }
    
    while(cnt>0){
        u = h.top(); h.pop();

        int i = u.second;
        int needed = freqT[i] - freqS[i]%freqT[i];

        freqS[i] += min(needed,cnt);
        arr.push_back({i+'a',min(cnt,needed)});
        
        cnt -= min(needed,cnt);

        h.push({-freqS[i]/freqT[i],i});
    }

    int ptr=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='?'){
            if(arr[ptr].second==0){
                ptr++;
            }
            cout << arr[ptr].first;
            arr[ptr].second--;
        }
        else{
            cout << s[i];
        }
    }
    cout << '\n';

    return 0;
}
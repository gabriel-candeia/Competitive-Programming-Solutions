#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, answ=0,qtd;
    string s;
    vector<int> cnt(300,0);
    vector<char> center, pair;

    cin >> n >> s;
    for(auto x:s){
        cnt[x]++;
    }

    for(int i=0;i<300;i++){
        if(cnt[i]%2){
            center.push_back(char(i));
            cnt[i]--;
        }
        while(cnt[i]){
            pair.push_back(char(i));
            cnt[i]-=2;
        }
    }
    if(center.size()==0){
        cout << 1 << '\n';
        cout << string(pair.begin(),pair.end()) + string(pair.rbegin(),pair.rend()) <<'\n';
    }
    else{
        while(pair.size()%center.size()!=0){
            center.push_back(pair.back());
            center.push_back(pair.back());
            pair.pop_back();
        }
        answ = center.size();
        qtd = pair.size()/center.size();
        cout << answ << '\n';
        int j=0;
        for(int i=0;i<answ;i++){
            string temp="";
            for(int lim=j+qtd;j<lim;j++){
                temp += pair[j];
            }
            cout << temp << center[i] << string(temp.rbegin(),temp.rend()) << ' ';
        }
        cout << '\n';
    }
    return 0;
}
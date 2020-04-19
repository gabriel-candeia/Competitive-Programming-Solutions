#include<bits/stdc++.h>
using namespace std;

char change_case(char a){
    if(a>='a'){
        return a-'a'+'A';
    }
    return a-'A'+'a';
}

int main(){
    string s, alphabet;
    vector<char> d;
    int a1=0, a2=0;
    map<char,int> cnt;

    cin >> s >> alphabet;
    for(auto c:alphabet){
        cnt[c]++;
    }

    for(auto c:s){
        if(cnt[c]){
            cnt[c]--;
            a1++;
        }
        else{
            d.push_back(c);
        }
    }

    for(auto c:d){
        if(cnt[change_case(c)]){
            cnt[change_case(c)]--;
            a2++;
        }
    }

    cout << a1 << ' ' << a2 << '\n';

    return 0;
}
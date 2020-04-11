#include<bits/stdc++.h>
using namespace std;

int fat(int n){
    int acm=1;
    for(int i=1;i<=n;i++){
        acm *= i;
    }
    return acm;
}

int main(){
    int n, qtd;
    vector<int> freq(26,0);
    string s, last;

    cin >> s;
    qtd = fat(s.size());
    for(auto i:s){
        freq[i-'a']++;
    }
    for(auto i:freq){
        qtd /= fat(i);
    }

    cout << qtd <<'\n';
    sort(s.begin(),s.end());
    last = string(s.rbegin(),s.rend());
    while(s!=last){
        cout << s << '\n';
        next_permutation(s.begin(),s.end());
    }
    cout << last << '\n';

    return 0;
}
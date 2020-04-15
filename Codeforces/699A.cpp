#include<bits/stdc++.h>
using namespace std;

char comp(char b){
    if(b=='R'){
        return 'L';
    }
    return 'R';
}

int main(){
    int n, x, answer=INT_MAX, lxr = -1;
    bool poss;
    string s;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> s;
    poss = false;
    for(int i=0;i<n;i++){
        cin >> x;
        if(s[i]=='L' && lxr!=-1){
            answer = min(answer,(x-lxr)/2);
            poss = true;
        }
        else if(s[i]=='R'){
            lxr = x;
        }
    }

    cout << ((poss) ? answer : -1) << '\n';

    return 0;
}
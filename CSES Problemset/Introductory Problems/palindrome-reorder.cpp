#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<int> freq(26,0);
    int maxOdd;
    string s, a1;
    char odd = ' ';

    cin >> s;
    for(auto i:s){
        freq[i-'A']++;
    }

    maxOdd = (s.size())%2;
    for(char i='A';i<='Z';i++){
        if(freq[i-'A']%2){
            odd = i;
        }
        maxOdd -= freq[i-'A']%2;
        a1 += string(freq[i-'A']/2,i);
    }

    if(maxOdd<0){
        cout << "NO SOLUTION\n";
    }
    else{
        cout << a1 + string(1*(odd!=' '),odd) + string(a1.rbegin(),a1.rend()) << '\n';
    }
    return 0;
}
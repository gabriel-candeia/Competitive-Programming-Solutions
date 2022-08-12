//subtask 1
#include<bits/stdc++.h>
using namespace std;

bool match(char a, char b){
    if(a=='C' || a=='T') swap(a,b);
    return ((a=='A' && b=='T') || (a=='G' && b=='C'));
}

int main(){
    int n;
    string s;

    cin >> n;
    cin >> s;

    int answ = 0, best = 0;
    for(int i=0;i<n;i++){
        int temp = 0;
        for(int l=i,r=i+1;l>=0 && r<n;l--, r++){
            temp += match(s[l],s[r]);
        }
        if(temp>answ){
            best = i, answ = temp;
        }
    }

    cout << best+1 <<" " << answ <<"\n";


    return 0;
}
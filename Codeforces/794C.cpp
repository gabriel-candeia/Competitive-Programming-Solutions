#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, pos = -1;
    string s, t, answ, answ2, x;
    cin >> s >> t;
    n = s.size();
    sort(s.begin(),s.end());
    sort(t.rbegin(),t.rend());


    for(int i=0,j=0,iter=0;iter<n;iter++){
        if(s[i]>=t[j] && pos==-1){
            i = n/2+n%2-1, j = n/2-1;
            pos = iter;
        }
        if(iter%2==0){
            answ += s[i];
            i+=(pos==-1) ? 1 : -1;
        }
        else{
            answ += t[j];
            j+=(pos==-1) ? 1 : -1;
        }
    }
    if(pos!=-1){
        x = answ.substr(pos);
        reverse(x.begin(),x.end());
        answ2 = answ.substr(0,pos) + x;
        answ = answ2;
    }
    cout << answ << '\n';
    return 0;
}
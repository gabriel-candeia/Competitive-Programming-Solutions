#include<bits/stdc++.h>
using namespace std;

int repetido(const string& s){
    for(int i=1;i<s.size();i++)
        if(s[i]==s[i-1])
            return true;
    return false;
}

int modificacoes(string s, const string& t){
    int acm = 0, n = t.size();
    for(int i=0,j;i<n;i++){
        for(j=0;j<n && s[j]!=t[i];j++);
        for(;j<i;j++) swap(s[j],s[j+1]), acm++;
        for(;j>i;j--) swap(s[j],s[j-1]), acm++;
    }
    return acm;
}

int main(){
    int q, n;

    cin >> q;
    while(q--){
        cin >> n;
        string s, s1, t, t1;
        cin >> s >> t;
        s1 = s, t1 = t;
        sort(s1.begin(),s1.end()), sort(t1.begin(),t1.end());
        if(s1==t1 && (repetido(s1) || (modificacoes(s,s1)%2==modificacoes(t,s1)%2))){
            cout << "YES" <<"\n";
        }
        else{
            cout <<"NO" << "\n";
        }
    }

    return 0;
}
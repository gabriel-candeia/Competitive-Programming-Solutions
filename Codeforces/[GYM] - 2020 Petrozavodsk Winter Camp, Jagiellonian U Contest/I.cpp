#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

string subtrai(string s, string t){
    string answ;
    
    int i, j;
    for(i=s.size()-1, j=t.size()-1; i>=0 && j>=0; i--, j--){
        if(s[i]>=t[j]){
            answ.push_back(s[i]-t[j]+'0');
        }
        else{
            int k=i;
            for(k=i-1;k>=0 && s[k]=='0';k--);
            for(s[k]--, k++; k<i;k++) s[k] = '9';
            answ.push_back(s[i]-t[j]+10+'0');
        }
    }
    for(;i>=0;i--)
        answ.push_back(s[i]);
    for(int i=answ.size()-1;answ[i]=='0';i--) answ.pop_back();
    if(answ.size()==0) return "0";
    return string(answ.rbegin(),answ.rend());
}

string gerar_palindromo(string s){
    if(s.size()==1)
        return s;
    if(s.size()==2){
        if(s[0]=='0')
            return string(1,s[1]);
        if(s[0]=='0')
            return string(2,s[0]-1);
    }
    int n = s.size(), pos=0;
    for(int i=0;i<=(n-1)/2;i++)
        if(s[i]!='0') pos = i;
    if(pos==0 && s[pos]=='1')
        return string(s.size()-1,'9');
    string x = s.substr(0,pos);
    return x + string(1,s[pos]-1) + ((pos!=n/2) ? string(s.size()-2*x.size()-2,'9')+string(1,s[pos]-1) : "") + string(x.rbegin(),x.rend());
}

bool ehpalindromo(string s){
    for(int i=0;i<s.size();i++)
        if(s[i]!=s[s.size()-1-i])
            return false;
    return true;
}

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        string s, t;
        vector<string> answ;
        cin >> s;

        for(int k=0;k<25;k++){
            t = gerar_palindromo(s);
            s = subtrai(s,t);
            answ.push_back(t);
            if(s.size()==1){
                if(s!="0") answ.push_back(s);
                break;
            }
        }
    
        cout << answ.size() << '\n';
        for(auto x:answ) 
            cout << x << "\n";

    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

string s1, s2;

void combine(string &s, int l, int med, int r){
    string s1 = s.substr(l,med-l+1), s2 = s.substr(med+1,r-med);
    if(s1>s2)
        swap(s1,s2);
    for(int i=l;i<=med;i++)
        s[i] = s1[i-l];
    for(int i=med+1;i<=r;i++)
        s[i] = s2[i-med-1];
}   

void stringsort(string &s, int l, int r){
    if(r-l==0) return;
    if((r-l+1)%2==0){
        int med = (l+(r-l)/2);
        stringsort(s,l,med);
        stringsort(s,med+1,r);
        combine(s,l,med,r);
    }
}

int main(){
    
    cin >> s1 >> s2;
    
    stringsort(s1,0,s1.size()-1);
    stringsort(s2,0,s2.size()-1);
    if(s1==s2)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
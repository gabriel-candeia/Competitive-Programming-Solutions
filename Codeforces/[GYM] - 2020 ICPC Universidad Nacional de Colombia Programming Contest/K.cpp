#include<bits/stdc++.h>
using namespace std;

string parse(string &s){
    string t = "", s1="";
    for(auto c:s){
        if(c>='0' && c<='9')
            t+=c;
        else
            s1+=c;
    }
    s = s1;
    return t;
}

int cmp(string s, string t){
    if(s.size()<t.size())
        return -1;
    if(t.size()<s.size())
        return 1;
    for(int i=0;i<s.size();i++){
        if(s[i]<t[i])
            return -1;
        else if(s[i]>t[i])
            return 1;
    }
    return 0;
}

int main(){
    string s1, s2, s3, s4;

    cin >> s1 >> s3;

    s2 = parse(s1);
    s4 = parse(s3);
    if(s1==s3 && s2==s4)
        cout << "=\n";
    else if(s1<s3 || (s1==s3 && cmp(s2,s4)==-1)){
        cout << "<\n";
    }
    else{
        cout << ">\n";
    }
    return 0;
}
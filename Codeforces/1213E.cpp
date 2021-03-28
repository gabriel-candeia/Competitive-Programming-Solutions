#include<bits/stdc++.h>
using namespace std;

bool teste(string &answ, string &s, string &t){
    for(int i=0;i<answ.size()-1;i++)
        if(s[0]==answ[i] && s[1]==answ[i+1] || t[0]==answ[i] && t[1]==answ[i+1])
            return false;
    return true;
}

int main(){
    int n;
    vector<string> arr;
    string s, t, answ="";
    cin >> n >> s >> t;
    
    for(char i='a';i<='c';i++){
        for(char j='a';j<='c';j++){
            for(char k='a';k<='c';k++){
                if(i==j || i==k || j==k) continue;
                arr.push_back(string(n,i)+string(n,j)+string(n,k));
            }    
        }
    }

    for(char i='a';i<='c';i++){
        for(char j='a';j<='c';j++){
            for(char k='a';k<='c';k++){
                if(i==j || i==k || j==k) continue;
                string temp = "";
                for(int l=0;l<n;l++){
                    temp += i;
                    temp += j;
                }
                temp += string(n,k);
                arr.push_back(temp);
            }    
        }
    }

    for(auto x:arr){
        if(teste(x,s,t)){
            cout << "YES\n";
            cout << x <<'\n';
            break;
        }
    }

    return 0;
}
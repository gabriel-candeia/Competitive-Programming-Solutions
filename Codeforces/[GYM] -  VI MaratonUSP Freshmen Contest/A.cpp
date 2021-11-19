#include<bits/stdc++.h>
using namespace std;

bool teste(vector<int> wt, const vector<string>& arr){
    string nome = "kobus";
    for(auto s:arr){
        bool pref = true;
        for(int i=0;i<s.size() && i<nome.size();i++){
            if(wt[nome[i]-'a']<wt[s[i]-'a']){
                pref = false; break; 
            }
            if(wt[s[i]-'a']<wt[nome[i]-'a']){
                pref = false;
                return false;
            }
        }

        if(pref && nome.size()>s.size()) return false;
    }
    return true;
}

int main(){
    string answ = "acdefghijlmnpqrtvwxyz";
    vector<char> arr = {'k','o','b','u','s'};
    vector<string> s;

    int n;
    bool poss = false;

    cin >> n;
    s.assign(n,"");
    for(int i=0;i<n;i++){
        cin >> s[i];
    }


    sort(arr.begin(),arr.end());

    string temp = string(arr.begin(),arr.end())+answ;
    vector<int> wt(26,0);
    for(int i=0;i<temp.size();i++) wt[temp[i]-'a'] = i;
    poss |= teste(wt,s);

    for(;poss==false && next_permutation(arr.begin(),arr.end());){
        temp = string(arr.begin(),arr.end())+answ;
        vector<int> wt(26,0);
        for(int i=0;i<temp.size();i++) wt[temp[i]-'a'] = i;
        poss |= teste(wt,s);
        if(poss) break;
    }
    
    if(poss)
        cout << temp <<"\n";
    else
        cout << "sem chance" << "\n";

}
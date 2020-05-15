#include<bits/stdc++.h>
using namespace std;

bool poss = false;

pair<int,int> opBalance(string& s){
    vector<char> answ;
    for(auto p:s){
        if(answ.size() && (answ.back()=='(' && p==')')){
            answ.pop_back();
        }
        else{
            answ.push_back(p);
        }
    }

    int cnt=0;
    for(int i=0;i<answ.size();i++){
        cnt+=(answ[i]==')');
    }
    if(answ.size()==0){
        poss = true;
    }
    return {cnt,answ.size()-cnt};
}

int main(){
    int n;
    string s;
    vector<pair<pair<int,int>,string>> arr;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        arr.push_back({opBalance(s),s});
    }
    
    sort(arr.begin(),arr.end());
    string temp = "";
    for(auto p:arr){
        temp+=p.second;
    }
    poss = false;
    opBalance(temp);
    if(poss){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }
    return 0;
}

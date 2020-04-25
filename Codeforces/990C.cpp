#include<bits/stdc++.h>
#define ll long long 
using namespace std;

bool isValid(string s, ll& balance){
    vector<char> st;
    ll cnt=0;

    for(auto i:s){
        if(st.size()==0 || i=='('){
            st.push_back(i);
        }
        else if(st.size()>0 && st.back()=='(' && i==')'){
            st.pop_back();
        }
        else{
            st.push_back(i);
        }
    }

    for(int i=0;i<st.size();i++){
        if(cnt>0 && st[i]==')' || cnt<0 && st[i]=='('){
            return false;
        }
        cnt+= +1*(st[i]=='(') - 1*(st[i]==')');
    }

    balance = cnt;
    return true;
}


int main(){
    string s;
    map<int,ll> cnt;
    ll n, temp;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> s;
        if(isValid(s,temp)){
            cnt[temp]++;
        }
    }

    ll answ=0;
    for(auto p:cnt){
        if(p.first>=0){
            answ += p.second*cnt[-p.first];
        }
    }
    cout << answ <<'\n';
    return 0;
}

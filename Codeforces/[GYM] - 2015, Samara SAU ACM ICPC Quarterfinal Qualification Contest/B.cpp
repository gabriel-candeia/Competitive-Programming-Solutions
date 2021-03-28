#include<bits/stdc++.h>
using namespace std;

bool check(string &s){
    int cnt=0;
    for(auto x:s){
        cnt+=(x=='1');
    }
    return (cnt>=8 && cnt<=15);
}

int main(){
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<string> arr;
    map<string,int> mp;
    int cmp=0;
    string answ, s;
    node *root = new node();


    arr.assign(n,"");
    for(int i = 0; i < n; i++){
        cin >> s;
        if(check(s))
            mp[s]++;
    }
    answ = string(8,'1')+string(m-8,'0');

    for(auto p:mp){
        if(p.second>cmp){
            answ = p.first;
            cmp=p.second;
        }
    }

    cout<< answ <<'\n';
    return 0;
}

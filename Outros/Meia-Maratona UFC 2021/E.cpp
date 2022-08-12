#include<bits/stdc++.h>
#define maxn int(1e5+5)
#define ll long long
using namespace std;

int n;
string s, s1;
vector<pair<int,int>> queries;
vector<int> arr;

bool ok(ll k){
    for(int i=0;i<k;i++)
        s1[arr[i]] = '#';
    int last[30];
    for(int i=0;i<30;i++) last[i] = -1;

    multiset<int> ruim;
    bool ok = true;
    for(int i=0, j=0;ok && i<n && j<queries.size();i++){
        for(;queries[j].first==i;j++){
            if(queries[j].second==-1){
                ruim.insert(queries[j].first);
            }
            else{
                ruim.erase(ruim.find(queries[j].second));
            }
        }
            
        if(s1[i]!='#'){
            if(ruim.size())
                ok = ok && (last[s1[i]-'a'] < *(ruim.begin()));
            last[s1[i]-'a'] = i;
        }
    }
    for(int i=0;i<k;i++)
        s1[arr[i]] = s[arr[i]];
    return ok;
}

ll bb(){
    int l = 0, r = n, med, answ = -1;
    while(l<=r){
        med = (l+r)/2;
        if(ok(med)){
            answ = med;
            r = med-1;
        }
        else{
            l = med+1;
        }
    }
    return answ;
}

int main(){
    
    int q;

    cin >> s;
    cin >> q;
    s1 = s;
    n = s.size();
    while(q--){
        int a, b;
        cin >> a >> b;  
        queries.push_back({a-1,-1});
        queries.push_back({b,a-1});
    }

    arr.assign(n,0);
    for(auto &x:arr){
        cin >> x;
        x--;
    }

    sort(queries.begin(),queries.end());
    
    
    //cout << ok(2) <<"\n";
    cout << bb() <<"\n";


    return 0;
}
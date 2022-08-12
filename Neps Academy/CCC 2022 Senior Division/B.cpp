#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int a, b, n, cnt = 0;
    map<string,int> mp;
    set<pair<int,int>> proibido, obrigado;

    cin >> a;
    for(int i=0;i<a;i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(mp.find(s1)==mp.end())
            mp[s1] = ++cnt;
        if(mp.find(s2)==mp.end())
            mp[s2] = ++cnt;
        int x = mp[s1], y = mp[s2];
        if(y<x) swap(x,y);
        obrigado.insert({x,y});
        obrigado.insert({y,x});
    }

    cin >> b;
    for(int i=0;i<b;i++){
        string s1, s2;
        cin >> s1 >> s2;
        if(mp.find(s1)==mp.end())
            mp[s1] = ++cnt;
        if(mp.find(s2)==mp.end())
            mp[s2] = ++cnt;
        int x = mp[s1], y = mp[s2];
        if(y<x) swap(x,y);
        obrigado.insert({x,y});
        obrigado.insert({y,x});
    }

    int answ = 0;
    cin >> n;
    for(int i=0;i<n;i++){
        vector<string> s(3);
        cin >> s[0] >> s[1] >> s[2];
        vector<int> arr = {mp[s[0]],mp[s[1]],mp[s[2]]};

        for(int i=0;i<3;i++){
            for(int j=i+1;j<3;j++){
                if(obrigado.find({arr[i],arr[j]})!=obrigado.end()){
                    obrigado.erase(obrigado.find({arr[i],arr[j]}));
                    obrigado.erase(obrigado.find({arr[j],arr[i]}));
                }
                if(proibido.find({arr[i],arr[j]})!=proibido.end()){
                    answ++;
                }
            }
        }
    }

    answ += obrigado.size()/2;
    
    cout << answ << "\n";

    return 0;
}
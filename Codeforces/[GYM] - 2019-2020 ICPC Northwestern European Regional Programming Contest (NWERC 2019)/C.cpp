#include <bits/stdc++.h>
#define fastio(); ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int n, a, b, p;
    vector<pair<int,int>> arr;
    vector<int> x, qtd;
    map<int,int> mp;

    cin >> n;
    qtd.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a >> b;
        arr.push_back({a,b});
    }
    sort(arr.begin(),arr.end());

    cin >> p;
    x.assign(p+1,0);
    for(int i=0;i<p;i++){
        cin >> x[i];
        mp[x[i]] = 0;
        for(int j=0;j<n && x[i]>=arr[j].first;j++)
            qtd[j]+=(x[i]<=arr[j].second);
    }

    bool poss = true;
    vector<int> novos, encontrar;
    for(int i=0;i<n;i++){
        if(qtd[i]>=2) continue;
        if(i+1<n && qtd[i+1]<2 && arr[i].second == arr[i+1].first && mp.find(arr[i+1].first)==mp.end()){
            novos.push_back(arr[i].second);
            mp[arr[i].second]=0;
            qtd[i]++;
            qtd[i+1]++;
        }
        for(int j=arr[i].first+1;j<arr[i].second && qtd[i]<2;j++){
            if(mp.find(j)==mp.end()){
                mp[j] = 0;
                novos.push_back(j);
                qtd[i]++;
            }
        }
    }

    
    for(int i=0;i<n && poss;i++)
        if(qtd[i]!=2)
            poss = false;

    if(!poss){
        cout << "impossible\n";
    }
    else{
        cout << novos.size() << '\n';
        for(auto x:novos){
            cout << x << " ";
        }cout<<'\n';
    }

    return 0;
}
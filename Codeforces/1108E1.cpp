#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m, l, r;
    vector<int> a;
    vector<pair<int,int>> pares;

    cin >> n >> m;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    for(int i=0;i<m;i++){
        cin >> l >> r;
        pares.push_back({l-1,r-1});
    }

    int answ=0, index = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            for(int k=pares[j].first;(pares[j].first<=i && i<=pares[j].second) && k<=pares[j].second;k++)
                a[k]--;
        }
        int temp = *max_element(a.begin(),a.end())-a[i];
        if(temp>answ){
            answ = temp;
            index = i;
        }
        for(int j=0;j<m;j++){
            for(int k=pares[j].first;(pares[j].first<=i && i<=pares[j].second) && k<=pares[j].second;k++)
                a[k]++;
        }
    }

    cout << answ << '\n';
    vector<int> vet;
    for(int j=0;j<m;j++)
        if(pares[j].first<=index && index<=pares[j].second)
            vet.push_back(j+1);

    cout << vet.size() << '\n';
    for(auto x:vet)
        cout << x << ' ';
    cout << '\n';
    return 0;
}

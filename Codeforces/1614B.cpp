#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<pair<int,int>> arr;

        cin >> n;
        arr.assign(n,{0,0});
        for(int i=0;i<n;i++)
            cin >> arr[i].first, arr[i].second = i+1;

        deque<int> preguica;
        preguica.push_back(0);
        sort(arr.rbegin(),arr.rend());
        ll val = 0, distl=1, distr=1;
        for(int i=0;i<n;i++){
            if(i&1){
                preguica.push_back(arr[i].second);
                val += distl*arr[i].first;
                distl++;
            }
            else{
                preguica.push_front(arr[i].second);
                val += distr*arr[i].first;
                distr++;
            }
        }

        int cnt = 0;
        cout << 2*val <<"\n";
        vector<int> answ(n+1,0);
        while(preguica.size()){
            int u = preguica.front(); preguica.pop_front();
            answ[u] = ++cnt;
        }

        for(int i=0;i<=n;i++){
            cout << answ[i] << " ";
        }
        cout<<"\n";
    }

    return 0;
}
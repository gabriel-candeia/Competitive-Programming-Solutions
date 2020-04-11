#include<bits/stdc++.h>
#define N 100 + 3
using namespace std;

int main(){
    int n, m, q, t, l, h;
    long long int lb, ub;
    vector<pair<int,pair<int,int>>> arr;

    cin >> q;
    while(q--){
        cin >> n >> m;
        
        arr.clear();
        for(int i=0;i<n;i++){
            cin >> t >> lb >> ub;
            arr.push_back(make_pair(t,make_pair(lb,ub)));
        }
        sort(arr.begin(),arr.end());
        lb = m; ub = m; t = 0;
        bool poss = true;
        for(auto client:arr){
            //cout << client.first << ": " << l << " " << h <<'\n';
            l = client.second.first;
            h = client.second.second;

            ub = min({INT_MAX, h, ((ub + client.first-t > INT_MAX) ? INT_MAX : (int) ub + client.first-t)});  
            lb = max({INT_MIN, l,  ((lb - (client.first-t) < INT_MIN) ? INT_MIN : (int) lb - (client.first-t))});

            if(h<lb || ub<l){
                poss = false;
                break;
            }

            t = client.first;
        }

        cout << ((poss) ? "YES" : "NO") << '\n';
    }

    return 0;
}
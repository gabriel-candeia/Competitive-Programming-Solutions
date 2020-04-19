#include<bits/stdc++.h>
using namespace std;

int main(){
    int q, n, a;

    cin >> q;
    while(q--){
        cin >> n;

        map<int,int> cnt;
        vector<int> ord;

        for(int i=0;i<n;i++){
            cin >> a;
            cnt[a]++;
        }

        for(auto p:cnt){
            ord.push_back(p.second);
        }

        int lim = INT_MAX, answ=0;
        sort(ord.begin(),ord.end());
        for(int i=ord.size()-1;i>=0 && lim>0;i--){
            if(ord[i]>=lim){
                answ += lim-1;
                lim--;
            }
            else{
                answ += ord[i];
                lim = ord[i];
            }
        }

        cout << answ << '\n';
    }

    return 0;
}
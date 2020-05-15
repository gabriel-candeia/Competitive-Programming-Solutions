#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;

        set<pair<int,int>> segments;
        int siz, l, r, med;
        vector<int> a;

        a.assign(n,0);
        segments.insert({-n,0});

        for(int i=1;i<=n;i++){
            auto it = segments.begin();
            segments.erase(it);
            siz = -(*it).first;
            l = (*it).second;
            r = l+siz-1;
            if(siz%2){
                a[(l+r)/2] = i;
                med = (l+r)/2;
            }
            else{
                med = (l+r-1)/2;
                a[(l+r-1)/2] = i;
            }
            segments.insert({l-med,l});
            segments.insert({med-r,med+1});
        }

        for(int i=0;i<n;i++){
            cout << a[i] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
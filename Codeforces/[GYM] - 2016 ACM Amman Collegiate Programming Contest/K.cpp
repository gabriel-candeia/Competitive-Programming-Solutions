#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false); cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int t;
    cin >> t;
    while(t--){
        int n, m, x, y;
        cin >> n >> m;
        set<pair<int,int>> s;
        vector<int> arr(n,0);
        for(int i=0;i<m;i++){
            cin >> x >> y;
            s.insert({x,y});
        }

        for(int i=0;i<n;i++)
            arr[i] = i+1;

        for(int i=0;i<n;i++)
            for(int j=i;j>0 && s.find({arr[j-1],arr[j]})!=s.end();j--)
                swap(arr[j-1],arr[j]);

        for(int i=0;i<n;i++)
            cout << arr[i] << " ";
        cout<<'\n';

    }

    return 0;
}
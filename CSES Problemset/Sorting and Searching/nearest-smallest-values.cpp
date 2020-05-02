#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    set<pair<int,int>> s;
    vector<int> last, arr;

    cin >> n;
    last.assign(n,-1);
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=n-1;i>=0;i--){
        auto it = s.lower_bound({arr[i]+1,0});

        //cout << arr[i] << ": ";*
        while(it!=s.end()){    
            //cout << (*it).first << ' ';
            last[(*it).second] = i;
            s.erase(it++);
        }
        //cout << '\n';
        
        s.insert({arr[i],i});
    }

    for(int i=0;i<n;i++){
        cout << last[i]+1 << ' ';
    }
    cout << '\n';

    return 0;
}
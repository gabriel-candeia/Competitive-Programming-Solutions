#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, last=-1;
    vector<int> arr, answ;
    set<pair<int,int>> s[3];

    cin >> n;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        s[arr[i]%3].insert({arr[i],i});
    }

    for(int i=0;i<n;i++){
        auto next = s[i%3].upper_bound({last+1,n});
        if(next!=s[i%3].begin()){
            next--;
            last = (*next).first;
            answ.push_back((*next).second);
            s[i%3].erase(next);
        }
        else{
            break;
        }
    }

    if(answ.size()==n){
        cout << "Possible\n";
        for(auto p:answ){
            cout << p+1 << ' ';
        }
        cout << '\n';
    }
    else{
        cout << "Impossible\n";
    }

    return 0;
}
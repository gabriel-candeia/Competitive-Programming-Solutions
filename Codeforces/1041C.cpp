#include<bits/stdc++.h>
#define N int(2e5+3)
using namespace std;

int main(){
    int n, m, d, cnt=0;
    int answ[N];
    vector<int> arr;
    set<pair<int,int>> s;

    cin >> n >> m >> d;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        answ[i] = -1;
        s.insert({arr[i],i});   
    }

    while(s.size()){
        auto curr = s.begin();
        int i = (*curr).second;
        answ[i] = ++cnt;
        
        while(true){
            auto  next = s.lower_bound({arr[i]+d+1,0});
            if(next==s.end()){
                break;
               
            }
            answ[(*next).second] = answ[i];
            i = (*next).second;
            s.erase(next);
        }

        s.erase(curr);
    }

    cout << cnt << '\n';
    for(int i=0;i<n;i++){
        cout << answ[i] << ' ';
    }
    cout << '\n';

    return 0;
}
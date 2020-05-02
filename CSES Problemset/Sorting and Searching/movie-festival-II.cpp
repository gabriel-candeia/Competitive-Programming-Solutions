#include<bits/stdc++.h>
using namespace std;

int using_set(vector<pair<int,int>>& arr, int n, int k){
    multiset<int> s;
    int cnt = 0;

    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        auto rem = s.upper_bound(arr[i].second);
        if(rem!=s.begin()){
            rem--;
            s.erase(rem);
        }
        if(s.size()<k){
            s.insert(arr[i].first);
            cnt++;
        }
    }

    return cnt;
}

int using_deque(vector<pair<int,int>>& arr, int n, int k){
    deque<int> d;
    int cnt = 0;

    sort(arr.begin(),arr.end());
    for(int i=0;i<n;i++){
        if(d.size() && arr[i].second >= d[0]){
            d.pop_front();
        }
        if(d.size()<k){
            d.push_back(arr[i].first);
            cnt++;
        }
    }

    return cnt;
}

int main(){
    int k, n, a, b;
    vector<pair<int,int>> arr;
    deque<int> s;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a >> b;
        arr.push_back({b,a});
    }

    cout << using_deque(arr,n,k) << '\n';
    return 0;
}

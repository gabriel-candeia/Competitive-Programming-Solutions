#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, x;
    vector<int> arr;
    multiset<int> s;

    cin >> n >> k;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    for(int i=0;i<k;i++){
        s.insert(arr[i]);
    }

    auto median = s.begin();
    for(int i=1;2*i<k;i++){
        median++;
    }
    cout << (*median) << ' ';

    int l = 0, r = k, balance=0;
    while(r<n){
        auto rem = s.find(arr[l]);
        s.insert(arr[r]);
        
        if(rem==median){
            if(arr[r]<(*median) && median!=s.begin()){
                median--;
            }
            else{
                median++;
            }
        }
        else{
            balance += (arr[l]<=(*median)) ? 1 : -1;
            balance += (arr[r]<(*median)) ? -1 : 1;

            if(balance>=2){
                median++;
                balance = 0;
            }
            else if(balance<=-2){
                median--;
                balance = 0;
            }
        }
        cout << (*median) << ' ';
        s.erase(rem);
        r++; l++;
    }
    cout << '\n';

    return 0;
}
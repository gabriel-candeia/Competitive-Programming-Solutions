#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<pair<int,int>> arr;
    

    cin >> n;
    arr.assign(n,{0,0});
    for(int i=0;i<n;i++)
        cin >> arr[i].first >> arr[i].second;
    
    bool poss = true;
    for(int i=1;i<n;i++){
        if(arr[i].first-arr[i-1].first != arr[i].second-arr[i-1].second )
            poss = false;
    }

    if(poss){
        cout << "idades corretas" << "\n";
    }
    else{
        cout << "mentiu a idade" << "\n";   
    }
    

    return 0;
}
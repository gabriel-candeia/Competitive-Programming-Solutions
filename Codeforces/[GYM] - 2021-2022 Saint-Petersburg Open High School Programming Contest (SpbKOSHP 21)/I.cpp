#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a, b;
    
    cin >> n >> a >> b;
    vector<int> arr1(n,0), arr2(n,0);
    vector<pair<int,int>> diff;
    string answ = string(n,'0');

    for(auto &x:arr1)
        cin >> x;
    for(auto &x:arr2)
        cin >> x;
    
    for(int i=0;i<n;i++){
        diff.push_back({arr1[i]-arr2[i],i});
    }
    

    sort(diff.begin(),diff.end());
    int acm = 0;
    

    for(int i=0;i<b;i++){
        int id = diff[i].second;
        acm += arr2[id];
        answ[id] = 'P';
    }
    

    for(int i=n-1;n-i<=a;i--){
        int id = diff[i].second;
        acm += arr1[id];
        answ[id] = 'T';
    }

    for(int i=0;i<n;i++){
        if(answ[i]=='0'){
            if(arr1[i]>arr2[i]){
                answ[i] = 'T';
                acm += arr1[i];
            }
            else{
                answ[i] = 'P';
                acm += arr2[i];
            }
        }
    }

    cout << acm <<"\n";
    for(auto c:answ)
        cout << c << " ";
    cout<<"\n";

    return 0;
}
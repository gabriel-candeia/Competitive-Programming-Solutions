#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n;
    cin >> n;
    int soma = 0, mn;
    vector<int> arr;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    sort(arr.begin(),arr.end());
    mn = arr[0];
    for(int i=0;i<n;i++){
        soma += arr[i];
    }
    bool answ = true;
    if(n%2==1){
        answ = (soma%2==1);
    }
    else{
        if(soma%2==0 && mn%2==0){
            answ = false;
        }
        else if(soma%2==1 && mn%2==1){
            answ = true;
        }
        else if(soma%2==1 && mn%2==0){
            answ = true;
        }
        else{
            answ = true;
        }
    }

    cout << (answ ? "lowie" : "imitater") <<"\n";

    return 0;
}
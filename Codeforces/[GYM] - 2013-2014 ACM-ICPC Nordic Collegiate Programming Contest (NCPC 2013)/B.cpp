#include<bits/stdc++.h>
using namespace std;

int n;
double t;
vector<int> arr;

int teste(int hi){
    int lo = t*hi;
    int answ = 0;
    for(auto x:arr){
        if(x<lo){
            return 501;
        }
        if(x>hi){
            int cortes = x/hi, resto = x%hi;
            if(resto + cortes*(hi-lo) >= lo){
                answ += cortes;
            }
            else{
                answ = 501;
            }
        }
    }
    return answ;
}

int main(){ 
    cin >> t >> n;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    int answ = 500;
    for(int i=1;i<=1e6;i++){
        answ = min(answ,teste(i));
    }

    cout << answ << "\n";

    return 0;   
}
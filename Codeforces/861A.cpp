#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k;

    cin >> n >> k;
    if(k==0){
        cout << n <<'\n';
    }
    else{
       ll zeros=0;
       while(zeros<k){
           if(n%10==0){
               n/=10;
               zeros++;
           }
           else if(n%10==5){
               n*=2;
           }
           else{
               n*=5;
           }
       }
       cout << n;
       for(int i=0;i<max(k,zeros);i++)
            cout << 0;
        cout <<'\n';
    }   
    return 0;   
}
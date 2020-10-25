#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll n, k, x;
    priority_queue<ll> pq;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> x;
        pq.push(x);
    }

    int div=0, raiz;
    while(pq.size()<k){
        x = pq.top(); 
        raiz = sqrt(x);
        div = max(min(raiz,(int) (k-pq.size()+1)),2);
        pq.pop();
        int rem  = x%div, qtd = x/div, rec = rem/div, imp = rem%div;
        //cout << x << ":\n";
        for(int i=0;i<div;i++){
            if(i<imp){
                pq.push(1+rec+qtd);
          //      cout << 1+rec+qtd << "\n";
            }
            else{
                pq.push(rec+qtd);
            //    cout << rec+qtd << "\n";
            }
        }
        //cout<<'\n';
    }

    ll answ = 0;
    while(pq.size()){
        //cout << x <<'\n';
        x = pq.top(); pq.pop();
        answ += x*x;
    }

    cout << answ <<'\n';
    return 0;
}
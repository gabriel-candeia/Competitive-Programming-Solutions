//subtasks 1 and 2
#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n;


int main(){
    cin >> n;

    if(n==3){
        cout << 3 <<"\n";
    }
    else if(n%2==0){
        cout << n+1 << "\n";
        cout << 1 <<"\n";
    }
    else{
        vector<int> answ;
        answ.push_back(1);
        answ.push_back(2);
        int acm = 3, i;
        for(i=5;i<=2*n;i+=2){
            acm = acm^i;
            answ.push_back(i);
            if(acm==i-1 && i>n) break;
        }
        answ.pop_back();
        cout << i << "\n";
        for(auto x:answ)
            cout << x <<" ";
        cout<<"\n";
    }

    return 0;
}
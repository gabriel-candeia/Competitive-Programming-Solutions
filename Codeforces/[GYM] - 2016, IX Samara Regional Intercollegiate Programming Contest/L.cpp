#include<bits/stdc++.h>
using namespace std;

bool teste(vector<int> &a, vector<int> &b){
    int acm=0, n = a.size();

    for(int i=a.size()-1, j=b.size()-1;i>=0 && j>=0;i--, j--){
        for(;j>=0 && b[j]>a[i];j--);
        acm += (j>=0);
    }
    return (acm>=n/2+1);
}

int main(){
    int n;
    vector<int> a, b;

    cin >> n;
    a.assign(n,0), b.assign(n,0);

    for(auto &x:a)
        cin >> x;

    for(auto &x:b)
        cin >> x;

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());

    pair<bool,bool> answ = {teste(a,b),teste(b,a)};

    if(answ==pair<bool, bool>{false,false}){
        cout << "None\n";
    }
    else if(answ==pair<bool, bool>{1,1}){
        cout << "Both\n";
    }
    else if(answ==pair<bool, bool>{1,0}){
        cout << "First\n";
    }
    else{
        cout << "Second\n";
    }

    return 0;
}
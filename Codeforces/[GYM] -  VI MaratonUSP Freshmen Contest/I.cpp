#include<bits/stdc++.h>
using namespace std;

int f(int x){
    if(x==12)
        return 2;
    return 3+(10-x);
}

int main(){
    int n;

    cin >> n;

    int a = n/15;
    n = n%15;
    vector<int> answ;
    if((n<=10 || n==12) && n!=0) answ.push_back(f(n));
    else if(n!=0) answ.push_back(f(10)), answ.push_back(f(n-10));

    cout << answ.size() + a << "\n";
    for(int i=0;i<a;i++)
        cout << 1 << " ";
    for(auto x:answ)
        cout << x << " ";
    cout<<'\n';

    return 0;
}
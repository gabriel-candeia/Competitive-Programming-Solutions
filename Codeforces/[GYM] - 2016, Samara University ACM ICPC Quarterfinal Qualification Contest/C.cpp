#include<bits/stdc++.h>
#define ll long long
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int main(){
    fastio();
    int n;
    vector<int> answ;

    cin >> n; answ.assign(n,-1);
    for(ll i=0;i<n;i++)
        answ[(i*i)%n] = i;

    for(int i=0;i<n;i++)
        cout << answ[i] << " ";
    cout<<"\n";

    return 0;
}
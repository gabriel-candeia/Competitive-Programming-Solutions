#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> a, b;

    cin >> n;
    a.assign(n,0); b.assign(n,0);

    for(int i=0;i<n;i++){
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    int top = 0;
    for(int i=1;i<n;i+=2)
        b[i] = a[top++];
    for(int i=0;i<n;i+=2)
        b[i] = a[top++];
    int answ = 0;
    for(int i=1;i<n-1;i++)
        answ += ((b[i]<b[i-1])&&(b[i]<b[i+1]));

    cout << answ <<'\n';
    for(int i=0;i<n;i++)
        cout << b[i] << " ";
    cout <<'\n';
    return 0;
}
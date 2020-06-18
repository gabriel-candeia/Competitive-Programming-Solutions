#include<bits/stdc++.h>
using namespace std;
int gcd(int a, int b){
    if(b==0){
        return a;
    }
    return gcd(b,a%b);
}


int main(){
    int n, k;
    vector<int> a;

    cin >> n >> k;
    a.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> a[i];
        a[i]%=k;
    }

    int g = a[0];
    for(int i=0;i<n;i++){
        g = gcd(g,a[i]);
    }

    vector<int> answ, visited(k,0);
    int p=g;
    for(int i=0;i<k;i++){
        if(!visited[p]){
            answ.push_back(p);
        }
        visited[p]=1;
        p=(p+g)%k;
    }
    cout << answ.size() << '\n';
    sort(answ.begin(),answ.end());
    for(auto p:answ){
        cout << p << ' ';
    }
    cout << '\n';

    return 0;
}
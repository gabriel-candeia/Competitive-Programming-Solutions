#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, a;
    map<int,int> l, r, cnt;
    int answ = 0;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> a;
        l[a] = i;;
    }

    for(int i=0;i<n;i++){
        cin >> a;
        r[a] = i;;
    }

    for(int i=1;i<=n;i++){
        cnt[(r[i]-l[i]+n)%n]++;
        answ = max(answ,cnt[(r[i]-l[i]+n)%n]);
    }

    cout << answ << '\n';

    return 0;
}
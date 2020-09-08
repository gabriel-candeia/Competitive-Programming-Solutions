#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k;

    cin >> n >> k;
    vector<int> q(n+1,0), s(n+1,0), p(n+1,0), p1(n+1,0);
    for(int i=1;i<=n;i++){
        cin >> q[i];
    }
    for(int i=1;i<=n;i++){
        cin >> s[i];
    }

    int cnt1=0, cnt2=0;

    for(int i=1;i<=n;i++) p[i] = i;
    for(cnt1;p!=s;cnt1++){
        for(int j=1;j<=n;j++){
            p1[j] = p[q[j]];
        }
        for(int j=1;j<=n;j++){
            p[j] = p1[j];
        }
        if(cnt1>k) break;
    }

    for(int i=1;i<=n;i++) p[i] = i;
    for(cnt2;p!=s;cnt2++){
        for(int j=1;j<=n;j++){
            p1[q[j]] = p[j];
        }
        for(int j=1;j<=n;j++){
            p[j] = p1[j];
        }
        if(cnt2>k) break;
    }
    
    /*for(int i=1;i<=n;i++) cout << p[i] << ' '; cout << '\n';

    cout << cnt1 << " " << cnt2 <<'\n';*/
    if(cnt1>k && cnt2>k || k==0){
        cout << "NO\n";
    }
    else if(k==cnt1 || k==cnt2 || (cnt1<=k && (k-cnt1)%2==0 && (cnt2>k || (cnt1+cnt2)>2)) || (cnt2<=k && (k-cnt2)%2==0 && (cnt1>k || (cnt1+cnt2)>2))){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }

    return 0;
}
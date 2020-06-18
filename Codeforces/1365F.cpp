#include<bits/stdc++.h>
#define N 1000
using namespace std;

int main(){
    int t, n, a[N], b[N], temp;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        map<pair<int,int>,int> cnt;
        bool poss = true;

        cin >> n;
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        for(int i=0;i<n;i++){
            cin >> b[i];
        }

        if(n%2 && a[n/2]!=b[n/2]){
            poss = false;
        }
        else{
            for(int i=0;i<n/2;i++){
                if(a[i]>a[n-i-1]){
                    temp = a[i];
                    a[i] = a[n-i-1];
                    a[n-i-1] = temp;
                }
                cnt[{a[i],a[n-i-1]}]++;
            }
            for(int i=0;i<n/2;i++){
                if(b[i]>b[n-i-1]){
                    temp = b[i];
                    b[i] = b[n-i-1];
                    b[n-i-1] = temp;
                }
                cnt[{b[i],b[n-i-1]}]--;
            }
            for(auto p:cnt){
                if(p.second){
                    poss = false;
                    break;
                }
            }
        }
        if(poss){
            cout << "yes\n";
        }
        else{
            cout << "no\n";
        }
    }

    return 0;
}
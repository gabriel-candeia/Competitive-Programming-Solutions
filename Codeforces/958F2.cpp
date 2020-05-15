#include<bits/stdc++.h>
using namespace std;

const int INF = 1e9;

int main(){
    int n, m, ok=0, rem=0;
    vector<int> k, cnt, arr;
    int l=0, r=0, answ=1e9;

    cin >> n >> m;

    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }

    k.assign(m+1,0);
    cnt.assign(m+1,0);
    for(int i=1;i<=m;i++){
        cin >> k[i];
        if(k[i]==0){
            ok++;
        }
    }

    
    while(l<n){
        if(ok!=m && r==n){
            break;
        }
        if(ok==m){
            answ = min(answ,rem);
            cnt[arr[l]]--;
            if(cnt[arr[l]]<k[arr[l]]){
                ok--;
            }
            else{
                rem--;
            }
            l++;
        }
        else{
            cnt[arr[r]]++;
            if(cnt[arr[r]]==k[arr[r]]){
                ok++;
            }
            if(cnt[arr[r]]>k[arr[r]]){
                rem++;
            }
            r++;
        }
    }

    if(answ==INF){
        cout << -1 << '\n';
    }
    else{
        cout << answ << '\n';
    }

    return 0;
}

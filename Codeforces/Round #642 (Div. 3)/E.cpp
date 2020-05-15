#include<bits/stdc++.h>
using namespace std;

int const INF = 1e7;

int main(){
    int t;
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    
    while(t--){
        int n, k, cnt=0;
        char aux;
        vector<int> arr, before, after;

        cin >> n >> k;
        for(int i=0;i<n;i++){
            cin >> aux;
            arr.push_back(aux-'0');
            cnt+=(arr[i]==1);
        }

        before.assign(n,INF);
        for(int i=0;i+k<n;i++){
            before[i+k] = before[i] + arr[i];
        }

        after.assign(n,INF);
        for(int i=0;i+k<n;i++){
            if(arr[n-1-i]==1){
                after[n-1-i-k] = 1;
            }
            else{
                after[n-1-i-k] = after[n-1-i]+1;
            }
        }

        int answ = 1e9;
        for(int i=0;i<k;i++){
            int cost = cnt, grupo=0, pos = i;
            if(arr[pos]==0){
                pos=i+k*after[i];
            }
            if(pos>n){
                answ = min(answ,cost);
            }
            while(pos<n){
                grupo++;
                cost--;
                if(after[pos]!=1 && after[pos]<INF){
                    if(after[pos]<grupo){
                        cost+=(after[pos]-1);
                    }
                    else{
                        cost+=grupo;
                        grupo = 0;
                    }
                }
               
                answ = min(answ,cost);
                pos += k*after[pos];
            }
        }
        cout << answ << '\n';
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, k, temp;
    vector<int> arr, cnt;

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    while(t--){
        cin >> n >> k;
        arr.assign(n,0);
        cnt.assign(2*k+2,0);
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        for(int i=0;i<n/2;i++){
            if(arr[i] > arr[n-1-i]){
                temp = arr[i];
                arr[i] = arr[n-1-i];
                arr[n-1-i] = temp;
            }

            cnt[2] += 2;
            cnt[arr[i]+1]--;
            cnt[arr[n-1-i]+k+1]++;
        }

        
        for(int i=2;i<=2*k;i++){
            cnt[i]+=cnt[i-1];
        }

        for(int i=0;i<n/2;i++){
            cnt[arr[n-1-i]+arr[i]]--;
        }

        int answ=n;
        for(int i=2;i<=2*k;i++){
            //cout << cnt[i] << ' ';
            answ = min(answ,cnt[i]);
        }
        //cout << endl;
        cout << answ << '\n';

    }

    return 0;
}

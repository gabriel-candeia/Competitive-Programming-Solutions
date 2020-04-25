#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, k, t;
    

    cin >> t;
    while(t--){
        cin >> n >> k;
        int answer, cnt;
        vector<int> picos(n,0), arr(n,0);

        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        for(int i=1;i<n;i++){
            picos[i] += picos[i-1];
            if(i<n-1 && arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                picos[i+1]++;
            }
        }
        

        cnt = picos[k-1], answer=0;
        for(int i=1;i+k-1<n;i++){
            if(picos[i+k-1]-picos[i+1] > cnt){
                cnt = picos[i+k-1]-picos[i+1];
                answer = i;
            }
        }
        
        /*
        for(int i=0;i<n;i++){
            cout << picos[i] <<' ';
        }
        cout << '\n';*/
        
        cout << cnt+1 << ' ' << answer+1 << '\n';
    }

    return 0;
}

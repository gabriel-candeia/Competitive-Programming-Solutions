#include<bits/stdc++.h>
#define maxn int(1e5+5)
using namespace std;

int main(){
    int n, m, block=400;
    vector<int> arr, answ;
    vector<array<int,4>> queries;

    cin >> n >> m;
    arr.assign(n,0);
    for(auto &x:arr)
        cin >> x;

    for(int i=0,l,r;i<m;i++){
        cin >> l >> r;
        queries.push_back({(l-1)/block,r-1,l-1,i});
    }

    sort(queries.begin(),queries.end());
    answ.assign(m,0);
    vector<int> freq(n+1,0);
    int l=0, r=-1, cnt = 0;
    for(auto q:queries){
        while(q[2]<l){
            l--;
            if(arr[l]<=n){ 
                cnt -= freq[arr[l]]==arr[l];
                freq[arr[l]]++;   
                cnt += freq[arr[l]]==arr[l];
            }
        }
        while(r<q[1]){
            r++;
            if(arr[r]<=n){ 
                cnt -= freq[arr[r]]==arr[r];
                freq[arr[r]]++;
                cnt += freq[arr[r]]==arr[r];
            }
        }
        while(l<q[2]){
            if(arr[l]<=n){ 
                cnt -= freq[arr[l]]==arr[l];
                freq[arr[l]]--;   
                cnt += freq[arr[l]]==arr[l];
            }
            l++;
        }
        while(r>q[1]){
            if(arr[r]<=n){ 
                cnt -= freq[arr[r]]==arr[r];
                freq[arr[r]]--;
                cnt += freq[arr[r]]==arr[r];
            }
            r--;
        }
        answ[q[3]] = cnt;
    }

    for(int i=0;i<queries.size();i++){
        cout << answ[i] << "\n";
    }

    return 0;
}
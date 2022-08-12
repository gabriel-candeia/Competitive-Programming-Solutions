#include<bits/stdc++.h>
#define maxn int(2e5+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

int freq[maxn], onstack[maxn];

int main(){
    fastio();
    int n, k;   
    vector<int> arr, st;

    cin >> n >> k;
    arr.assign(n,0);
    for(auto &x:arr){
        cin >> x;
        freq[x]++;
    }

    for(int i=0;i<n;i++){
        if(!onstack[arr[i]]){
            while(st.size()!=0  && st.back() > arr[i] && freq[st.back()]>0){
                onstack[st.back()] = false;
                st.pop_back();
            }
            st.push_back(arr[i]);
            onstack[arr[i]] = 1;
        }
        freq[arr[i]]--;
    }
    
    for(auto v:st){
        cout << v << " ";
    }cout<<"\n";

    return 0;
}
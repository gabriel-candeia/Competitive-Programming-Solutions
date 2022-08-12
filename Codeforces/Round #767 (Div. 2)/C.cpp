#include<bits/stdc++.h>
#define maxn int(2e5+5)
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<int> arr, freq, mex, seen;
        cin >> n;
        arr.assign(n,0), freq.assign(n+2,0), seen.assign(n+2,0), mex.assign(n,0);
        for(auto &x:arr)
            cin >> x;

        int ptr = 0;
        for(int i=n-1;i>=0;i--){
            freq[arr[i]]++;
            while(freq[ptr]!=0){
                ptr++;
            }
            mex[i] = ptr;
        }

        vector<int> answ;
        int i = 0, iter = 1, qtd;
        while(i<n){
            answ.push_back(mex[i]);
            qtd = mex[i];
            while(i<n && qtd){
                if(arr[i]<answ.back() && seen[arr[i]]!=iter){
                    seen[arr[i]] = iter;
                    qtd--;
                }
                i++;
            }
            iter++;
            if(answ.back()==0) i++;
        }

        cout << answ.size() << "\n";
        for(auto x:answ){
            cout << x << " ";
        }cout <<"\n";
    }

    return 0;
}
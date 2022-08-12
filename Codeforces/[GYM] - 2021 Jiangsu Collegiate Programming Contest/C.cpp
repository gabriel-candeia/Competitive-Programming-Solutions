#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n = 0;
        vector<int> freq(10,0);
        for(auto &x:freq) cin >> x, n+=x;
        vector<int> answ;

        if(n==1 && freq[0]==1){
            answ.push_back(0);
        }
        else{
            int last = 0;
            for(int i=0;i<n;i++){
                for(int j=0;j<10;j++){
                    if(freq[j] && j!=last){
                        freq[j]--;
                        int mx = 0, rem = 0;
                        for(int k=0;k<10;k++){
                            rem += freq[k];
                            mx = max(mx,freq[k]);
                        }
                        if(mx<=rem-mx+1){
                            answ.push_back(j);
                            last = j;
                            break;
                        }
                        freq[j]++;
                    }
                }
            }
        }

        if(answ.size()==n){
            for(auto x:answ)
                cout << x;
            cout <<"\n";
        }
        else{
            cout << -1 <<"\n";
        }

    }

    return 0;
}
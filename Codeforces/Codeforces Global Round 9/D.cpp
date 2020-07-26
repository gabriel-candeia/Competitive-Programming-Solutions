#include<bits/stdc++.h>
using namespace std;

int get_mex(vector<int>& a, int n){
    vector<int> cnt(1001,0);
    for(auto x:a){
        cnt[x]++;
    }
    int answ;
    for(answ=0;cnt[answ];answ++){

    }
    return answ;
}

int main(){
    int t, n;
    vector<int> a;

    cin >> t;
    while(t--){
        cin >> n;

        a.assign(n,0);
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        

        vector<int> answ;
        int mx;
        bool poss=false;
        for(int i=0;i<2*n;i++){
            mx = (get_mex(a,n));
            if(mx!=n){
                a[mx%n] = mx;
                answ.push_back(mx%n+1);
                poss = true;
            }
            else{
                for(int i=0;i<n;i++){
                    if(a[i]!=i){
                        a[i] = mx;
                        answ.push_back(i+1);
                        break;
                    }
                }
            }
            for(int i=1;i<n;i++){
                if(a[i-1]>a[i]){
                    poss = false;
                }
            }
            if(poss==true){
                break;
            }
        }

        cout << answ.size() << '\n';
        for(int i=0;i<answ.size();i++){
            cout << answ[i] << ' ';
        }
        cout << '\n';

        /*for(auto x:a){
            cout << x << " ";
        }
        cout << '\n';*/

    }

    return 0;
}
#include<bits/stdc++.h>
#define maxn int(1e6+5)
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

bool existe[maxn];

int main(){
    int n;

    cin >> n;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        existe[x] = 1;
    }

    int answ = 0;
    
    for(int i=maxn-1;i>0;i--){
        if(existe[i]==0){
            int cnt = 1;
            vector<int> ok;
            for(int j=i;j<maxn;j+=i,cnt++){
                if(existe[j])
                    ok.push_back(cnt);
            }
            for(int j=0;j<ok.size();j++){
                if(__gcd(ok[0],ok[j])==1){
                    existe[i] = 1;
                    break;
                }
            }
        }
        answ += existe[i];
    }
    
    cout << answ-n <<"\n";

    return 0;
}
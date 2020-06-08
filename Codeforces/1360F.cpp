#include<bits/stdc++.h>
using namespace std;

int cntDifferences(string s, string t){
    int cnt=0;
    for(int i=0;i<s.size();i++){
        cnt += (s[i]!=t[i]);
    }
    return cnt;
}


int main(){
    int t, n, m, diff;
    string answ;
    char temp;
    bool poss;

    cin >> t;
    while(t--){
        cin >> n >> m;
        vector<string> arr(n,"");

        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        poss = false;

        for(int i=0;i<m;i++){
            temp = arr[0][i];
            for(int j='a';j<='z';j++){

                arr[0][i] = j;
                diff = 0;

                for(int k=1;k<n;k++){
                    diff = max(diff,cntDifferences(arr[0],arr[k]));
                }
                
                if(diff<=1){
                    poss = true;
                    answ = arr[0];
                    break;
                }
            }
            if(poss){
                break;
            }
            arr[0][i] = temp;
        }
        if(poss){
            cout << answ <<'\n';
        }
        else{
            cout << -1 << '\n';
        }

    }

    return 0;
}
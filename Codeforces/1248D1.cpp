#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    string s;

    cin >> n >> s;

    int beauty = 0;
    pair<int,int> answ = {0,0};

    vector<int> pref(n,0), up(n,0), from(n,0);
    for(int l=0;l<n;l++){
        for(int r=l+1;r<n;r++){
            swap(s[l],s[r]);

            pref[0] = ((s[0]=='(') ? 1 : -1);
            for(int i=1;i<n;i++)
                pref[i] = ((s[i]=='(') ? 1 : -1) + pref[i-1];

            up[0] = pref[0];
            for(int i=1;i<n;i++)
                up[i] = min(pref[i],up[i-1]);

            from[n-1] = pref[n-1];
            for(int i=n-2;i>=0;i--)
                from[i] = min(pref[i],from[i+1]);

            int temp = (pref[n-1]==0 && up[n-1]>=0);
            for(int i=0;i<n-1;i++){
                if((from[i+1]-up[i])>=0 && (up[i]+(pref[n-1]-pref[i]))>=0 && pref[n-1]==0){
                    temp++;
                }
            }

            if(temp>beauty){
                beauty = temp;
                answ = {l,r};
            }

            swap(s[l],s[r]);
        }
    }

    cout << beauty << "\n";
    cout << answ.first+1 << " " << answ.second+1 <<"\n";

    return 0;
}
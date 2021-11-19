#include<bits/stdc++.h>
#define maxn 26
using namespace std;

int cnt1[maxn], cnt2[maxn][maxn], cnt3[maxn][maxn][maxn];

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        string s;
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        memset(cnt3,0,sizeof(cnt3));
        cin >> n >> s;
        for(auto c:s) cnt1[c-'a']++;
        for(int i=0;i+1<n;i++) cnt2[s[i]-'a'][s[i+1]-'a']++;
        for(int i=0;i+2<n;i++) cnt3[s[i]-'a'][s[i+1]-'a'][s[i+2]-'a']++;

        bool ok = false;
        string answ = "";
        for(int i=0;i<maxn && !ok;i++)
            if(cnt1[i]==0)
                answ = string(1,i+'a'), ok = true;
        
        for(int i=0;i<maxn && !ok;i++)
            for(int j=0;j<maxn && !ok;j++)
                if(cnt2[i][j]==0)
                    answ = string(1,i+'a')+string(1,j+'a'), ok = true;
        for(int i=0;i<maxn && !ok;i++)
            for(int j=0;j<maxn && !ok;j++)
                for(int k=0;k<maxn && !ok;k++)
                    if(cnt3[i][j][k]==0)
                        answ = string(1,i+'a')+string(1,j+'a')+string(1,k+'a'), ok = true;

        cout << answ <<"\n";
    }

    return 0;
}
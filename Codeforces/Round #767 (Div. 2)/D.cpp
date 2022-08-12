#include<bits/stdc++.h>
#define maxn int(30)
using namespace std;

int f1[maxn][maxn], f2[maxn][maxn][maxn];

int main(){
    int t;

    cin >> t;
    while(t--){
        int n;
        vector<string> arr;
        cin >> n;
        
        memset(f1,0,sizeof(f1));
        memset(f2,0,sizeof(f2));

        bool ok = false;
        for(int i=0;i<n;i++){
            string s;
            cin >> s;
            arr.push_back(s);
            if(s.size()==1 || (s.size()==2 && s[0]==s[1]) || (s.size()==3 && s[0]==s[2])){
                ok = true;
            }
        }
        
        if(ok==false){
            for(auto s:arr){
                if(s.size()==2){
                    f1[s[0]-'a'][s[1]-'a']++;
                }
                else if(s.size()==3){
                    f2[s[0]-'a'][s[1]-'a'][s[2]-'a']++;
                }
            }

            for(auto s:arr){
                if(s.size()==2){
                    f1[s[0]-'a'][s[1]-'a']--;
                }
                else if(s.size()==3){
                    f2[s[0]-'a'][s[1]-'a'][s[2]-'a']--;
                }
                if(s.size()==2){
                    for(int i='a';i<='z';i++)
                        if(f2[i-'a'][s[1]-'a'][s[0]-'a']!=0)
                            ok = true;
                }
                if(f1[s[1]-'a'][s[0]-'a']!=0)
                    ok = true;
                if(s.size()==3 && f2[s[2]-'a'][s[1]-'a'][s[0]-'a']!=0)
                    ok = true;
                if(ok) break;
            }
        }

        cout << ((ok) ? "YES" : "NO") <<"\n";
    }

    return 0;
}
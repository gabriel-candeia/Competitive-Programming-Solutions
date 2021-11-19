#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        string s;

        cin >> s;
        ll acm = 0;
        vector<int> last(2,s.size());
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0' || s[i]=='1'){
                acm += last[1-((s[i]-'0')==i%2)]-i+1;
                last[((s[i]-'0')==i%2)] = i;
                acm--;
            }
            else{
                acm += max(last[0],last[1])-i;
            }
        }
        cout << acm <<"\n";
    }

    return 0;
}
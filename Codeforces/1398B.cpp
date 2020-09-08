#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        vector<int> points;
        int cnt=0;
        s+='0';
        for(int i=0;i<s.size();i++){
            if(s[i]=='0' && cnt){
                points.push_back(cnt);
                cnt = 0;
            }
            else if(s[i]=='1'){
                cnt++;
            }
        }
        sort(points.rbegin(),points.rend());
        int answ=0;
        for(int i=0;i<points.size();i+=2){
            answ += points[i];
        }
        cout << answ <<'\n';
    }

    return 0;
}
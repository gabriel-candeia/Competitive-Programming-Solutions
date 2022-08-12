#include<bits/stdc++.h>
using namespace std;

vector<int> pos[30];

int main(){
    int n, k;
    string s;
    vector<int> best, start;

    cin >> n >> k >> s;

    best.assign(n,0), start.assign(n,0);
    best[0] = 1;
    for(int i=0;i<n;i++){
        if(i==n-1 || s[i]!=s[i+1]){
            pos[s[i]-'a'].push_back(i);
        }
        if(i!=0){
            start[i] = ((s[i]!=s[i-1]) ? i : start[i-1]); 
            best[i] = ((s[i]!=s[i-1]) ? 1 : best[i-1]+1);
        }
    }

    
    int ransw = 0;
    for(int i=0;i<30;i++){
        int slack = k, answ = ((pos[i].size()) ? best[pos[i][0]] : 0);  
        ransw = max(min(n,answ+slack),ransw);
        for(int l=0,r=0;r+1<pos[i].size();){
            //cout << l << " " << r <<" "<<answ <<" ";
            if(start[pos[i][r+1]]-pos[i][r]-1<=slack){
                slack -= start[pos[i][r+1]]-pos[i][r]-1;
                answ += start[pos[i][r+1]]-pos[i][r]-1;
                r++;
                if(r<n) answ += best[pos[i][r]];
            }
            else{
                answ-=best[pos[i][l]];
                answ -= start[pos[i][l+1]]-pos[i][l]-1;
                slack += start[pos[i][l+1]]-pos[i][l]-1;
                l++;
            }
            if(r<l) r = l;
            //cout << l << " " << r <<" " << answ <<"\n";
            ransw = max(min(n,answ+slack),ransw);
        }
    }

    cout << ransw <<"\n";
    
    return 0;
}
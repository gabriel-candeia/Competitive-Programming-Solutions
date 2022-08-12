#include<bits/stdc++.h>
#define fastio() ios_base::sync_with_stdio(false), cin.tie(NULL)
using namespace std;

struct block{
    int size = 0, center = 0;
};

bool operator<(const block& a, const block& o){
    return a.center < o.center;
}

int main(){
    fastio();
    string s;
    cin >> s;
    int n = s.size();

    int answ = 0;

    set<block> blocks[2];
    for(int i=1;i<n-1;i++){
        if(s[i]!='B' || s[i-1]!='A' || s[i+1]!='C') continue;
        int left = 1, right = 1;
        for(;i-left>=0 && s[i-left]=='A';left++);
        for(;i+right<n && s[i+right]=='C';right++);
        left--, right--;
        blocks[(i+1)%2].insert({min(left,right),i+1});
    }   

    while(blocks[0].size()+blocks[1].size()){
        int qtd = 0;
        for(auto p:blocks[0]){   
            qtd++;
            if(p.size>1)
                blocks[1].insert({p.size-1,p.center-qtd});
            qtd++;
            answ++;
        }
        blocks[0].clear();

        if(blocks[1].size()){
            answ++;
            block removed = *blocks[1].begin();
            for(auto p:blocks[1]){
                if(p.size==1){
                    removed = p;
                    break;
                }
            }

            set<block> aux;
            for(auto p:blocks[1]){
                if(p.center==removed.center)
                    continue;
                if(p.center>removed.center)
                    blocks[0].insert({p.size,p.center-1});
                else
                    aux.insert(p);
            }   
            blocks[1].clear();
            blocks[1] = aux;
        }
    }
    
    cout << answ <<"\n";

    return 0;   
}
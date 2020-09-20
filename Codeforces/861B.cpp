#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int n, m;
    vector<int> k, f;

    cin >> n >> m;
    k.assign(m,0);
    f.assign(m,0);
    for(int i=0;i<m;i++)
        cin >> k[i] >> f[i];

    int answ = -1;
    bool poss=true;
    for(int i=1;i<=int(1e6)+1;i++){
        poss = true;
        for(int j=0;j<m;j++){
            if(k[j]/i+(k[j]%i!=0)!=f[j])
                poss = false;
        }
        if(poss){
            if(answ==-1){
                answ = i;
            }
            else{
                answ = -1;
                break;
            }
            
        }
    }

    if(answ!=-1)
        answ = n/answ + (n%answ!=0);
    for(int i=0;i<m;i++)
        if(k[i]==n)
            answ = f[i];
    
    cout << answ << '\n';

    return 0;
}
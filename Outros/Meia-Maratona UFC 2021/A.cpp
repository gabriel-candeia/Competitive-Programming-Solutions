#include<bits/stdc++.h>
using namespace std;

bool ehPar(int n){
    return !((1-(((1-((~n)&1)) ^ 1) == ((1-((~n)&1)) + 1))) & 1);
}

int main(){
    int n;
    vector<vector<int>> jogadas(9,vector<int>());

    cin >> n;
    
    for(int i=0;i<n;i++){
        int a, b, t;
        cin >> t >> a >> b;
        jogadas[a].push_back(t);
    }


    vector<int> score(2,0);
    for(auto &arr:jogadas)
        sort(arr.begin(),arr.end());
    
    for(int i=1;i<=8;i++){
        score[i>4]+= 100*((int)jogadas[i].size());
        for(int j=1;j<jogadas[i].size();j++)
            if(jogadas[i][j]-jogadas[i][j-1]<=10)
                score[i>4] += 50;
    }

    cout << score[0] << " " << score[1] <<"\n";

    return 0;
}
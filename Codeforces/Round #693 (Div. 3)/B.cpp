#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, x;
        vector<int> qtd(2,0);
        cin >> n;
        for(int i=0;i<n;i++){
            cin >> x;
            qtd[x%2]++;
        }

        bool poss = false;
        for(int i=0;i<=qtd[0];i++)
            for(int j=0;j<=qtd[1];j++)
                if(2*i+j==2*(qtd[0]-i)+qtd[1]-j)
                    poss = true;

        if(!poss)
            cout << "NO\n";
        else
            cout << "YES\n";
    }
    return 0;
}
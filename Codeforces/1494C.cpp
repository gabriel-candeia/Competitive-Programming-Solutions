#include<bits/stdc++.h>
using namespace std;

int main(){ 
    int t;
    cin >> t;
    while(t--){
        int n, m;
        vector<vector<int>> boxes(2), pos(2), suff(2);
        vector<int> answ(2,0);

        cin >> n >> m;
        for(int i=0, x;i<n;i++){
            cin >> x;
            boxes[(x>0)].push_back(abs(x));
        }

        for(int i=0, x;i<m;i++){
            cin >> x;
            pos[(x>0)].push_back(abs(x));
        }

        boxes[0] = vector<int>(boxes[0].rbegin(),boxes[0].rend());
        pos[0] = vector<int>(pos[0].rbegin(),pos[0].rend());

        for(int k=0;k<2;k++){
            suff[k].assign(pos[k].size()+1,0);
            if(boxes[k].size()==0) continue;
            for(int i = pos[k].size()-1, j=boxes[k].size()-1;i>=0;i--){
                while(j>0 && boxes[k][j]>pos[k][i]) j--;
                suff[k][i] = suff[k][i+1] + (boxes[k][j]==pos[k][i]);
            }
        }
        
        for(int k=0;k<2;k++){
            answ[k] = suff[k][0];
            if(boxes[k].size()==0) continue;
            for(int i = 0, j=0; i<pos[k].size(); i++){
                while(j<boxes[k].size() && boxes[k][j]<pos[k][i]) j++;
                if(j){
                    int x = (lower_bound(pos[k].begin(),pos[k].end(),pos[k][i]-j+1) - pos[k].begin());
                    answ[k] = max(answ[k],suff[k][i+1] + (i-x+1));
                }
            }
        }
        cout << answ[0]+answ[1] << '\n';

    }

    return 0;
}
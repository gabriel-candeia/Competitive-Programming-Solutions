#include<bits/stdc++.h>
using namespace std;

vector<pair<int,int>> p;
bool colinear(int i,int j,int k){
    return ((p[i].first*p[j].second + p[i].second*p[k].first + p[j].first*p[k].second - p[j].second*p[k].first - p[i].second*p[j].first - p[k].second*p[i].first)==0);
}

int main(){
    int n, x, y;

    cin >> n;
    for(int i=0;i<n;i++){
        cin >> x >> y;
        p.push_back({x,y});
    }

    bool flag = false;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=j+1;k<n;k++)
                flag = flag || colinear(i,j,k);
    
    cout << ((flag) ? "Yes" : "No") <<'\n';

    return 0;
}
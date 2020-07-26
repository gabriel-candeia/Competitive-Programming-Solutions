#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> color, zeros;

    cin >> n;
    color.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> color[i];
        if(color[i]==0){
            zeros.push_back(i);
        }
    }

    int last=-1, next=0;
    for(int i=0;i<n;i++){
        if(color[i]==0){
            next++; last++;
        }
        if(last==-1){
            color[i] = zeros[next]-i;
        }
        else if(next==zeros.size()){
            color[i] = i-zeros[last];
        }
        else{
            color[i] = min(i-zeros[last],zeros[next]-i);
        }
        color[i] = min(color[i],9);
    }  

    for(int i=0;i<n;i++){
        cout << color[i];
        if(i!=n-1){
            cout << ' ';
        }
    }cout <<'\n';

    return 0;
}
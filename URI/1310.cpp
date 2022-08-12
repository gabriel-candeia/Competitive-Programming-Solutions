#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> arr(100,0);
    
    while(cin >> n){
        int custo;
        cin >> custo;
        for(int i=0;i<n;i++) cin >> arr[i], arr[i]-=custo;
        
        int answ = 0, best = 0;
        for(int i=0;i<n;i++){
            best = max({arr[i],arr[i]+best,0});
            answ = max(answ,best);
        }
        
        cout << answ <<"\n";
    }
        
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n, x;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> even, odd;
        for(int i=0;i<2*n;i++){
            cin >> x;
            if(x%2==0){
                even.push_back(i+1);
            }
            else{
                odd.push_back(i+1);
            }
        }

        if(odd.size()%2){
            odd.pop_back();
            even.pop_back();
        }
        else if(even.size()){
            even.pop_back();
            even.pop_back();
        }
        else{
            odd.pop_back();
            odd.pop_back();
        }

        for(int i=0;i<odd.size();i+=2){
            cout << odd[i] << " " << odd[i+1] << '\n';
        }
        for(int i=0;i<even.size();i+=2){
            cout << even[i] << " " << even[i+1] << '\n';
        }
    }

    return 0;
}
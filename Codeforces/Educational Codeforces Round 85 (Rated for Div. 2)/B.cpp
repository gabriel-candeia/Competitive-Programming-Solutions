#include<bits/stdc++.h>
#define N int(1e5)+3
using namespace std;

int main(){
    int t, n, a, x;
    

    cin >> t;
    while(t--){
        vector<int> neg, pos;
        int l = 0, r = 0, answ=0, sum = 0;
        cin >> n >> x;
        for(int i=0;i<n;i++){
            cin >> a;
            if(a-x>0){
                pos.push_back(a-x);
            }
            else if(a-x<0){
                neg.push_back(a-x);
            }
            else{
                answ++;
            }
        }
        sort(pos.begin(),pos.end());
        sort(neg.rbegin(),neg.rend());
        while(l<neg.size()){
            if(sum+neg[l]>=0){
                sum+=neg[l++];
                answ++;
            }
            else if(r<pos.size()){
                sum+=pos[r++];
            }
            else{
                break;
            }
        }

        cout << answ + pos.size()<< '\n';
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;

    cin >> t;
    while(t--){
        cin >> n;
        vector<int> a(n,0), b(n,0);
        int cnt=0;

        for(int i=0;i<n;i++){
            cin >> a[i];
        }
        for(int i=0;i<n;i++){
            cin >> b[i];
            cnt+=(b[i]==0);
        }

        bool ordered = true;
        for(int i=1;i<n;i++){
            if(a[i]<a[i-1]){
                ordered = false;
            }
        }

        if(ordered || (cnt>0 && cnt<n)){
            cout << "Yes\n";
        }
        else{
            cout << "No\n";
        }

    }

    return 0;
}
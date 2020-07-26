#include<bits/stdc++.h>
using namespace std;

void operation(string& a, int l, int r){
    for(int i=l;i<=r;i++){
        a[i] = ((a[i]=='0') ? '1' : '0');
    }

    char temp;
    for(int i=l;i<=(r+l)/2;i++){
        temp = a[r-i];
        a[r-i] = a[i];
        a[i] = temp;
    }
}

int main(){
    int t, n;
    string a, b;

    cin >> t;
    while(t--){
        cin >> n >> a >> b;
        vector<int> answ;
        for(int i=n-1;i>=0;i--){
            if(a[i]!=b[i]){
                if(a[0]==b[i]){
                    operation(a,0,0);
                    answ.push_back(0);
                }
                answ.push_back(i);
                operation(a,0,i);
            }
        }
        cout << answ.size() << ' ';
        for(auto x:answ){
            cout << x+1 << " ";
        }cout << '\n';
    }
    return 0;
}
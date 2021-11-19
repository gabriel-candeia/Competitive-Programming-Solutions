#include<bits/stdc++.h>
using namespace std;

int main(){
    string a, b;

    cin >> a >> b;

    int i=0,j=0;
    for(;i<a.size() && j<b.size();i++){
        if(a[i]==b[j]){
            j++;
        }
    }

    if(j==b.size()){
        cout << "Yes\n";
    }
    else{
        cout << "No\n";
    }

    return 0;
}
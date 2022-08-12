#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    char curr = 'a';
    cin >> n;
    for(int i=0;i<n;i++){
        if(i%2==0)
            curr = (curr=='a') ? 'b' : 'a';
        cout << curr;
    }
    cout <<"\n";

    return 0;
}
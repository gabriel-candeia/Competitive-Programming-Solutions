#include<bits/stdc++.h>
#define N 1000
using namespace std;

int main(){
    int k;
    int n=-1, m=-1;

    cin >> k;
    for(int i=5;i<k;i++){
        if(k%i==0 && k/i>=5){
            n = i;
            m = k/i;
            break;
        }
    }

    if(n==-1){
        cout << -1 << '\n';
    }
    else{
        char vowels[] = {'a','e','i','o','u'};

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                cout << vowels[(j+i)%5];
            }
        }cout <<'\n';
    }
    return 0;
}
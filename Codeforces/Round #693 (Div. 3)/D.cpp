#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    int t;

    cin >> t;
    while(t--){
        int n, x;
        vector<ll> arr,qtd(2,0);

        cin >> n;
        arr.assign(n,0);
        for(int i=0;i<n;i++)
            cin >> arr[i];

        sort(arr.rbegin(),arr.rend());

        for(int i=0;i<n;i++)
            if(i%2==arr[i]%2)
                qtd[i%2]+=arr[i];

        if(qtd[0]>qtd[1])
            cout << "Alice\n";
        else if(qtd[0]<qtd[1])
            cout << "Bob\n";
        else
            cout << "Tie\n";
    }
    return 0;
}
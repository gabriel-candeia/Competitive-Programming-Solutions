#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    vector<int> a;

    cin >> n;
    a.assign(n+1,-1);

    int pivot = 1, x, y;
    for(int i=2;i<=n;i++){
        cout << "? " << pivot << " " << i << endl;
        cin >> x;
        cout << "? " << i << " " << pivot << endl;
        cin >> y;
        if(x<y){
            a[i] = y;
        }
        else{
            a[pivot]  = x;
            pivot = i;
        }
    }
    a[pivot] = n;

    cout << "! ";
    for(int i=1;i<=n;i++)
        cout << a[i] << " ";
    cout << endl;
    return 0;
}
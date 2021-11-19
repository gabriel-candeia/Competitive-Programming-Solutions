#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> arr, resp;

void solve(vector<int>& arr, int l, int r){
    if(l>r) return;

    int med = (l + r)/2;
    for(int i=l;i<=r;i++){
        cout << "? " << med << " " << arr[i] << endl;
        char c;
        cin >> c;
        resp[i] = ((c=='=') ? 2 : ((c=='<') ? 3 : 1));
    }

    int pivot = l;
    for(int i=l;i<=r;i++){
        if(resp[i]==1){
            swap(resp[i],resp[pivot]), swap(arr[i],arr[pivot++]);
        }
    }

    for(int i=l;i<=r;i++){
        if(resp[i]==2){
            swap(resp[i],resp[pivot]);
            swap(arr[i],arr[pivot]);
            break;
        }
    }

    solve(arr,l,med-1);
    solve(arr,med+1,r);
}

int main(){
    cin >> n;

    resp.assign(n+1,0);
    for(int i=0;i<=n;i++)
        arr.push_back(i);

    solve(arr,1,n);

    cout << "! ";
    for(int i=1;i<=n;i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
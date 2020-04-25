#include<bits/stdc++.h>
using namespace std;

int main(){
    multiset<int> s;
    vector<int> arr;
    int n, x, i=-1, j=-1;

    cin >> n >> x;
    arr.assign(n,0);
    for(int i=0;i<n;i++){
        cin >> arr[i];
        s.insert(arr[i]);
    }
    
    for(auto a:arr){
        if((a==x-a && s.count(a)>=2)||(a!=x-a && s.count(x-a)>=1)){
            for(i=0;i<n && arr[i]!=a;i++);

            for(j=n-1;j>=0 && arr[j]!=(x-a);j--);
            
            break;
        }
    }

    if(i!=-1){
        cout << i+1 << " " << j+1 << '\n';
    }
    else{
        cout << "IMPOSSIBLE\n";
    }
}
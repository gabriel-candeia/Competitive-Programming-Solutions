#include<bits/stdc++.h>
#define ll long long
using namespace std;

int transforma(int a, int b, int m){
    a = a%m;
    if(b>a)
        return b-a;
    else 
        return m+b-a;
}

int main(){
    int n, m;
    vector<int> arr;
    vector<vector<int>> st;
    queue<int> temp;

    cin >> n >> m;
    arr.assign(n,0);
    st.assign(m,vector<int>());

    for(int i=0;i<n;i++)
        cin >> arr[i], st[arr[i]%m].push_back(i);

    ll answ = 0;
    for(int k=0;k<=2*m;k++){
        int i = k%m, prox = (i+1)%m;
        while(st[i].size() > n/m)
            temp.push(st[i].back()), st[i].pop_back();
        while(st[i].size() < n/m && temp.size())
            st[i].push_back(temp.front()), answ+=transforma(arr[temp.front()],i,m), arr[temp.front()] += transforma(arr[temp.front()],i,m), temp.pop();
    }
    
    

    cout << answ << "\n";
    for(auto x:arr)
        cout << x << " ";
    cout<<"\n";

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    cin >> n >> m;

    set<string> st;
    vector<int> arr;

    for(int i=0;i<m;i++){
        string s;
        cin >> s;
        st.insert(s);
    }

    for(auto s:st){
        arr.push_back(s.size());
    }

    sort(arr.begin(),arr.end());

    int answ = 0;
    for(int i=0;i<arr.size() && n>=arr[i]+(i!=0);i++){
        n-=arr[i]+(i!=0);
        answ++;
    }

    cout << answ <<"\n";

    return 0;
}
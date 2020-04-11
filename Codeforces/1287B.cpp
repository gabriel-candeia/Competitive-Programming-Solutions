#include<bits/stdc++.h>
using namespace std;

string constructString(string a, string b, int k){
    string c = "";
    for(int i=0;i<k;i++){
        if(a[i]==b[i]){
            c+=a[i];
        }
        else{
            c+=(a[i]!='S' && b[i]!='S') ? 'S' : (a[i]!='E' && b[i]!='E') ? 'E' : 'T';
        }
    }
    return c;
}

int main(){
    vector<string> arr;
    unordered_set<string> cnt;
    string s;
    int n, k, answ=0;

    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> s;
        arr.push_back(s);
        cnt.insert(arr[i]);
    }

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            answ += (cnt.find(constructString(arr[i],arr[j],k))!=cnt.end());
        }   
    }
    cout << answ/3 << '\n';
    return 0;
}
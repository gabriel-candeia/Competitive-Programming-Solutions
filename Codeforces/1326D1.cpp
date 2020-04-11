#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int l, int r){
    while(l<r){
        if(s[l++]!=s[r--]){
            return false;
        }
    }
    return true;
}

pair<int,int> maximumPreffixSuffixPalindrome(string s, int n){
    int l=0, r =0;
    for(int i=n-1;i>=0;i--){
        if(isPalindrome(s,0,i)){
            if(i > r) r = i;
            break;
        }
    }

    for(int i=0;i<=n-1;i++){
        if(isPalindrome(s,i,n-1)){
            if(n-1-i > r-l){ 
                l = i;
                r = n-1;
            }
            break;
        }
    }
    return make_pair(l,r);
}

int main(){
    int t, i, n;
    pair<int,int> p1, p2;
    string s;

    cin >> t;
    while(t--){
        cin >> s;
        n = s.size();
        p1 = maximumPreffixSuffixPalindrome(s,s.size());
        if(isPalindrome(s,0,n-1)){
            cout << s << '\n';
            continue;
        }
        //splice string
        for(i=0;i<n/2 && s[i]==s[n-1-i];i++);


        if(i){
            p2 = maximumPreffixSuffixPalindrome(s.substr(i,n-2*i),n-2*i);
        }
        else{
            p2 = make_pair(0,0);
        }

        if(p1.second-p1.first > p2.second-p2.first+2*i){
            cout << s.substr(p1.first,p1.second-p1.first+1) << '\n';
        }
        else{
            cout << s.substr(0,i) + s.substr(p2.first+i,p2.second-p2.first+1) + s.substr(n-i,i) << '\n';
        }
    }

    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    int t, n;
    string s;

    cin >> t;
    while(t--){
        cin >> n >> s;
        int answ=0;
        int start = 0, last = n-1;
        while(start<n && s[start]==s[last]){
            last=start;
            start++;
        }
        start = start%n;
        
        if(s[start]==s[last]){
            cout << n/3+(n%3!=0) << '\n';
        }
        else{
            int i = start;
            do{
                int grupo=0, j = i;
                while(s[i]==s[(i+grupo)%n])
                    grupo++;
                i = (i+grupo)%n;
                answ+=grupo/3;
            }while(i!=start);
            cout << answ << '\n';
        }
    }

    return 0;
}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

pair<vector<ll>,vector<ll>> precomp(string s){
    int n = s.size();
    vector<ll> pref(n,0), last(n,0);

    pref[0] = last[0] = s[0]-'0';
    for(int i=2;i<n;i+=2){
        if(s[i-1]=='+'){
            last[i] = s[i]-'0';
            pref[i] = pref[i-2] + last[i];
        }
        else{
            last[i] = last[i-2]*(s[i]-'0');
            pref[i] = pref[i-2] - last[i-2] + last[i];
        }
    }

    return {pref,last};
}

int main(){
    string s;
    int n;

    cin >> s;
    n = s.size();

    vector<ll> prefValue, prefLast, suffValue, suffLast;

    tie(prefValue,prefLast) = precomp(s);

    reverse(s.begin(),s.end());
    tie(suffValue,suffLast) = precomp(s);
    reverse(suffLast.begin(),suffLast.end());
    reverse(suffValue.begin(),suffValue.end());
    reverse(s.begin(),s.end());

    ll answ = prefValue[n-1];
    for(int i=0;i<n;i+=2){
        ll value = s[i]-'0', last = s[i]-'0';
        for(int j=i+2;j<n;j+=2){
            if(s[j-1]=='+'){
                last = s[j]-'0';
                value += last;
            }
            else{
                value -= last;
                last *= s[j]-'0';
                value += last;
                
            }

            ll tempVal = ((i!=0) ? prefValue[i-2] : value), tempLast = ((i!=0) ? prefLast[i-2] : value);
            if(i-1>=0){
                if(s[i-1]=='+'){
                    tempLast = value;
                    tempVal += tempLast;
                }
                else{
                    tempVal -= tempLast;
                    tempLast *= value;
                    tempVal += tempLast;
                }
            }
            if(j+1<n){
                if(s[j+1]=='+'){
                    tempVal += suffLast[j+2];
                }
                else{
                    tempVal = tempVal-tempLast + tempLast*suffLast[j+2] + suffValue[j+2]-suffLast[j+2];
                }
            }
            //cout << i << " " << j << " " << value << " " << tempVal <<"\n";
            answ = max(answ,tempVal);
        }
    }

    cout << answ <<"\n";

    return 0;
}
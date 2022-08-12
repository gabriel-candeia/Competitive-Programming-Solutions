#include<bits/stdc++.h>
#define ll long long
using namespace std;

vector<int> z_function(string s){
    int n = s.size();
    vector<int> z(n,0);
    for(int i=1,l=0,r=0;i<n;i++){
        if(i<=r){
            z[i] = min(z[i-l],r-i+1);
        }
        while(i+z[i]<n && s[i+z[i]]==s[z[i]]){
            z[i]++;
        }
        if(i+z[i]-1>r){
            l = i;
            r = i+z[i]-1;
        }
    }
    return z;
}

int main(){
  string s;
  int n;

  cin >> s;
  n = s.size();

  auto arr = z_function(s);

  
  ll answ = 0;
  for(int i=1;i<n;i++){
      if(n%i!=0) continue;
      bool ok = true;
      for(int j=i;ok&&j<n;j+=i){
          ok = ok&&(arr[j]>=i);
      }
      if(ok)
        answ += (n/i)*i;
  }

  cout << answ+1 <<"\n";
  return 0;
}
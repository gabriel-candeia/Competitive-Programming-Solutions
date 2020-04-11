#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    if(n==1){
        printf("1\n");
    }
    else if(n<=3){
        printf("NO SOLUTION\n");
    }
    else{
        for(int i=2;i<=n;i+=2){
            printf("%d ",i);
        }
        for(int i=1;i<=n;i+=2){
            printf("%d ",i);
        }
        printf("\n");

    }   
    return 0;
}
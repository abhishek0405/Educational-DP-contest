#include <iostream>
#include<algorithm>
#include<climits>
#include<string>
typedef long long ll;
using namespace std;
// /https://atcoder.jp/contests/dp/tasks/dp_b
int main() {
    ll t,n,i,j,k,x;
    cin>>n>>k;
    ll arr[n];
    ll dp[n];
    k=min(n-1,k);
    for(i=0;i<n;i++){
        cin>>arr[i];
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for(i=1;i<k;i++){
        j=i-1;
        while(j>=0){
            dp[i] = min(dp[j]+abs(arr[j]-arr[i]),dp[i]);
            j--;
        }
    }
    for(i=k;i<n;i++){

        for(j=i-k;j<i;j++){
            if(j>=0){
                dp[i] = min(dp[j]+abs(arr[j]-arr[i]),dp[i]);
            }
        }
     }
    cout<<dp[n-1];
    
}

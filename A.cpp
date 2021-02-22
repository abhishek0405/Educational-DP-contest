#include <iostream>
#include<algorithm>
#include<climits>
#include<string>
typedef long long ll;
using namespace std;
// /https://atcoder.jp/contests/dp/tasks/dp_a
int main() {
    ll t,n,i,j,k,x;
    cin>>n;
    ll arr[n];
    ll dp[n];
    for(i=0;i<n;i++){
        cin>>arr[i];
        dp[i] = 0;
    }
    dp[0] = 0;
    dp[1] = abs(arr[1]-arr[0]);
    for(i=2;i<n;i++){
        dp[i] = min((dp[i-1]+abs(arr[i]-arr[i-1])),dp[i-2]+abs(arr[i]-arr[i-2]));
     }
    cout<<dp[n-1];
    
}

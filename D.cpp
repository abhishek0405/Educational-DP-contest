#include <iostream>
#include<algorithm>
#include<climits>
#include<string>
typedef long long ll;
ll weight[100001];
ll value[101];
ll dp[101][100001];

using namespace std;
// /https://atcoder.jp/contests/dp/tasks/dp_d

ll solve(ll n,ll w){
    if(n<0){
        return dp[n][w] = 0;
    }
    if(w<=0){
        return dp[n][w] = 0;
    }
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    ll ans=-1;
    if(weight[n]<=w){
        //can take it
        ans = value[n] + solve(n-1,w-weight[n]);
    }
    ans = max(ans,solve(n-1,w));
    return dp[n][w] = ans;
}
int main() {
    ll t,n,i,j,k,x,a,b,c,w;
    cin>>n>>w;
    for(i=0;i<n;i++){
        for(j=0;j<=w;j++){
            dp[i][j] = -1;
        }
    }
    for(i=0;i<n;i++){
        cin>>weight[i]>>value[i];
    }

    cout<<solve(n-1,w);
}

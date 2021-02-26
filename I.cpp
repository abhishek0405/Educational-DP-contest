#include <iostream>
#include<algorithm>
#include<climits>
#include<string>
#include<iomanip>
typedef long long ll;

// /https://atcoder.jp/contests/dp/tasks/dp_i
//state is on tossing first i coins the probability of getting>=j heads.
double dp[3000][3000];
double prob[3000];
#define prDouble(x) cout << fixed <<setprecision(10)<<x
using namespace std;
double solve(ll i,ll j){
    //i is number of coins taken and j is minimum coins needed acc to condi(ie we need>=j heads)
    //prob of getting atleast 0 heads in any case =1.(as TT,HT,TH,HH)
    if(j==0){
        return dp[i][j]=1;
    }
    if(i==0){
        return dp[i][j]=0;
    }
    if(dp[i][j]>-0.9){
        return dp[i][j];
    }
    return dp[i][j] = prob[i]*solve(i-1,j-1)+(1-prob[i])*solve(i-1,j);


}
int main() {
    ll t,n,i,j,k,x;
    cin>>n;
    memset(dp,-1.0,sizeof dp);
    for(i=1;i<=n;i++){
        cin>>prob[i];
    }
    double ans=solve(n,double((n+1)/2));
    prDouble(ans);

    
       
    
}

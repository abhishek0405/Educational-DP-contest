#include <iostream>
#include<algorithm>
#include<climits>
#include<string>
typedef long long ll;
using namespace std;
#define MOD 1000000007
ll dp[1001][1001];
int main() {
    ll t,n,i,j,k,x,h,w;
        cin>>h>>w;
        char arr[h+1][w+1];

        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                cin>>arr[i][j];
            }
        }
        
        memset(dp,0,sizeof dp);
        dp[1][1] = 1;
        for(i=1;i<=h;i++){
            for(j=1;j<=w;j++){
                if(arr[i][j]=='#'){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j]=(dp[i][j]+dp[i-1][j]+dp[i][j-1])%MOD;
                }
            }
        }

        cout<<dp[h][w];


}

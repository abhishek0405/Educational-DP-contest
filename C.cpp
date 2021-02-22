#include <iostream>
#include<algorithm>
#include<climits>
#include<string>
typedef long long ll;
using namespace std;
// /https://atcoder.jp/contests/dp/tasks/dp_c
int main() {
    ll t,n,i,j,k,x,a,b,c;
    cin>>n;
    ll arr[n+1][3];
    for(i=0;i<n;i++){
        cin>>arr[i][0]>>arr[i][1]>>arr[i][2];
        
    }

    ll dp1[n+1];//max happiness such that ends with activity A
    ll dp2[n+1];//max happiness such that ends with activity B
    ll dp3[n+1];//max happiness such that ends with activity C

    dp1[0] = arr[0][0];
    dp2[0] = arr[0][1];
    dp3[0] = arr[0][2];

    for(i=1;i<n;i++){
        dp1[i] = max(dp2[i-1],dp3[i-1]) + arr[i][0];
        dp2[i] = max(dp1[i-1],dp3[i-1]) + arr[i][1];
        dp3[i] = max(dp2[i-1],dp1[i-1]) + arr[i][2];
    }
    cout<<max(max(dp1[n-1],dp2[n-1]),dp3[n-1]);
     
    
}

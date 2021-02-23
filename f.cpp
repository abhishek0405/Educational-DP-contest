#include <iostream>
#include<algorithm>
#include<climits>
#include<string>
#include<stack>
typedef long long ll;
using namespace std;
string s,t;
ll dp[3001][3001];
//dp i,j refers to max subseq len such that s till i taken and t till j.
ll solve(ll i,ll j){
    if(i==0||j==0){
        return dp[i][j] = 0;
    }
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    if(s[i-1]==t[j-1]){
        return dp[i][j]=1+solve(i-1,j-1);
    }
    return dp[i][j] = max(solve(i,j-1),solve(i-1,j));
}


int main() {
    ll n,i,j,k,x;
    
    cin>>s>>t;
    memset(dp,-1,sizeof dp);
    ll ans = solve(s.length(),t.length());
    i = s.length();
    j=t.length();
    stack<char>st;
    //very important to come from end to get optimal answer
    while(ans>0){
        if(s[i-1]==t[j-1]){
            st.push(s[i-1]);
            ans--;
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    while(!st.empty()){
        cout<<st.top();
        st.pop();
    }





}

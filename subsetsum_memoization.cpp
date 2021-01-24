#include <bits/stdc++.h>
using namespace std;

const int maximum=101;

int subsetsum(int wt[],int w,int n,int dp[][maximum]){
    
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    
    if(w==0){
        return 1;
    }
    
    if(n==0){
        return 0;
    }
    
    else if(wt[n-1]>w){
        dp[n][w] = subsetsum(wt,w,n-1,dp);
    }
    
    else if(wt[n-1]<=w){
        dp[n][w] = subsetsum(wt,w-wt[n-1],n-1,dp) || subsetsum(wt,w,n-1,dp);
    }
    
   return dp[n][w];
}


int main() {
	
	int n,w;
	cin>>n>>w;
	
	int wt[n];
	for(int i=0;i<n;i++){
	    cin>>wt[i];
	}
    int dp[n+1][maximum];
    memset(dp,-1,sizeof(dp));
    
    
	subsetsum(wt,w,n,dp) == 1 ? cout<<"YES" : cout<<"NO";
	
	
    
	
	return 0;
}

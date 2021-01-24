// ->maximum value  in the knapsack
// ->to find maximum weight in th knapsack ...change val[n-1] by wt[n-1]

#include<bits/stdc++.h>
using namespace std;
#define end "\n"


int knapsack(int wt[],int val[],int w,int n,int dp[][1001]){
    
    if(dp[n][w]!=-1){
        return dp[n][w];
    }
    
    if(n==0 || w==0){
        dp[n][w]=0;
    }
    
    if(wt[n-1]>w){
       dp[n][w] = knapsack(wt,val,w,n-1,dp); 
    }
    else if(wt[n-1<=w]){
        dp[n][w] = max(val[n-1]+knapsack(wt,val,w-wt[n-1],n-1,dp),
                    knapsack(wt,val,w,n-1,dp));
    }
    
    return dp[n][w];
}


int main(){
    int n,w;
    cin>>n>>w;
    
    int wt[n];
    for(int i=0;i<n;i++){
        cin>>wt[i];
    }
    int val[n];
	for(int i=0;i<n;i++){
        cin>>val[i];
    }
    
    
    int dp[101][1001]; 
    memset(dp, -1, sizeof(dp));

    
    cout<<knapsack(wt,val,w,n,dp);
    
    
	return 0;
}

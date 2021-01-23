// ->maximum value  in the knapsack
// ->to find maximum weight in th knapsack ...change val[n-1] by wt[n-1]


#include<bits/stdc++.h>
using namespace std;
#define end "\n"

int knapsack(int wt[],int val[],int w,int n){
    
    int dp[n+1][w+1];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            
            //recursive code 
            if (i == 0 || j == 0) 
                dp[i][j] = 0; 
            
            else if(wt[i-1]>j){
                dp[i][j]=dp[i-1][j];
            }
            else if(wt[i-1] <= j){
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
        }
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
    cout<<knapsack(wt,val,w,n);
    
    
	return 0;
}

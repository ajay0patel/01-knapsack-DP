//count of subset sum with given sum
//only change of ----> || into + beacause we want sum

#include <bits/stdc++.h>
using namespace std;

int subsetsum(int wt[],int w,int n){
    int dp[n+1][w+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=w;j++){
        dp[0][j]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            
            if(wt[i-1]>j){
                dp[i][j] =dp[i-1][j]; 
             }
    
            else if(wt[i-1]<=j){
                dp[i][j] = dp[i-1][j-wt[i-1]] + dp[i-1][j] ;
                
                }
        }
        
    }    
    return dp[n][w];
}


int main() {
	
	int n,w;//w -->given sum
	cin>>n>>w;
	
	int wt[n];
	for(int i=0;i<n;i++){
	    cin>>wt[i];
	}
    
	cout<<subsetsum(wt,w,n); 
	
	return 0;
	
}

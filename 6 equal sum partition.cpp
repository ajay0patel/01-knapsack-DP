//equal sum partition problem 
//wt[] ==> given arr[]


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
                dp[i][j] = dp[i-1][j-wt[i-1]] || dp[i-1][j] ;
                
                }
        }
        
    }

    //printing dp array
    /*for(int i=0;i<=n;i++){
        for(int j=0;j<=w;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<"\n";
    }*/
    
    return dp[n][w];
}


int main() {
	
	int n;
	cin>>n;
	
	int wt[n];
	for(int i=0;i<n;i++){
	    cin>>wt[i];
	}
	
	//find out sum of wt[] array 
	//if sum%2==0 then we may get two array with same sum
    //but , if we have odd sum -->we can not divide wt[] in to two array of equal sum.. 	
	
	int sum=0;
	for(int i=0;i<n;i++){
	    sum+=wt[i];
	}
	
	if(sum%2!=0){
	    cout<<"NO";
	}
	else{
	    int w=sum/2;
	    subsetsum(wt,w,n) == 1 ? cout<<"YES" : cout<<"NO";    
	}
	
	return 0;
}

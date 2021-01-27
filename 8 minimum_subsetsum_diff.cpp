//minimum subset sum difference problem using subset problem
//think about s1 and s2 -->both subsets which will provide minimum sum..
//s1 and s2 belongs to [0,sum(arr)]
//filter this range

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
    
    //last line of dp table has our filter range
	//store in to vector
    vector<int>filter;
	//store index of w
	for(int j=0;j<=w/2;j++){
	    if(dp[n][j]==1){
	    filter.push_back(j);
	    }
	}
	
    /*for(int j=0;j<filter.size();j++){
	    cout<<filter[j]<<" ";
	}*/
	//s2-s1==minimum
	//s1+s2=sum(arr)=w
	//w-s1-s1==minimum ->w-2s1--->minimum
	
	int mn=INT_MAX;
	for(int s1=0;s1<filter.size();s1++){
	   mn=min(mn,w-(2*filter[s1]));
	}
	
    
    return mn;
}


int main() {
	
	int n;
	cin>>n;
	
	int wt[n];
	for(int i=0;i<n;i++){
	    cin>>wt[i];
	}
    int range=0;
    for(int i=0;i<n;i++){
	    range+=wt[i];
	}
    
    
	cout<<subsetsum(wt,range,n);//table created
	//minimum subsetsum difference
	
	return 0;
}

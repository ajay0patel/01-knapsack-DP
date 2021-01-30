//return YES if present or NO if not 

#include <bits/stdc++.h>
using namespace std;
int subsetsum(int wt[],int w,int n){
    
    if(w==0){
        return 1;
    }
    if(n==0){
        return 0;
    }
    
    else if(wt[n-1]>w){
        return subsetsum(wt,w,n-1);
    }
    
    else if(wt[n-1]<=w){
        return subsetsum(wt,w-wt[n-1],n-1) || subsetsum(wt,w,n-1);
    }   
}


int main() {
	
	int n,w;
	cin>>n>>w;
	
	int wt[n];
	for(int i=0;i<n;i++){
	    cin>>wt[i];
	}
    
	subsetsum(wt,w,n) == 1 ? cout<<"YES" : cout<<"NO";
	
	return 0;
}

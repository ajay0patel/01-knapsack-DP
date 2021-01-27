class Solution {
public:
    int subsetsum(vector<int> wt,int w,int n){
    int dp[n+1][w+1];
    
    for(int i=0;i<=n;i++){
        dp[i][0]=1;
    }
    for(int j=1;j<=w;j++){
        dp[0][j]=0;
    }
    
    for(int i=1;i<=n;i++){
        for(int j=1;j<=w;j++){
            
            if(wt[i-1]==0)
                    dp[i][j] = dp[i-1][j];    //for handling 0 
            else if(wt[i-1]>j){
                dp[i][j] =dp[i-1][j]; 
             }
    
            else if(wt[i-1]<=j){
                dp[i][j] = dp[i-1][j-wt[i-1]] + dp[i-1][j] ;
                
                }
        }
        
    }    
    return dp[n][w];
}

    
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int cnt = 0,sum = 0;
        int n = nums.size();
        for(int i=0;i<nums.size();i++)
        {
            sum = sum+nums[i];
            if(nums[i]==0)
                cnt = cnt+1;
        }
        if(S > sum)
            return 0;
        if((S+sum)%2!=0)
            return 0;
        int s = (S+sum)/2;
        
        return pow(2,cnt)*subsetsum(nums,s,n); 
    }
};

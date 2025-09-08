void solve(vector<int>& nums, int index, int& mini,int cnt){
        if(index >= nums.size()-1){
            mini = min(mini,cnt);
            return;
        }
        if(cnt>=mini) return; //pruning - early stoping

        for(int i=1; i<=nums[index];i++){
            solve(nums,index+i,mini,cnt+1);  //--- 1

            // backtrack step is implicit here because cnt is passed by value
            //for backtrack style -- 1st pass cnt by reference     //--- 2
            
            // cnt++;
            // solve();
            // cnt++;

        }
}          // OR // -- all 3 codes are same

int solve(vector<int>& nums, int index){   //--- 3
    if(index >= nums.size()-1) return 0;

    int mini = INT_MAX;
    for(int i=1; i<=nums[index]; i++){
        int jumps = solve(nums, index + i);
        if(jumps != INT_MAX)
            mini = min(mini, 1 + jumps); //1+ yha kiya h qki agar uper call me hi karte to int overflow ho skta tha
    }

    return mini;
}

//Recursive
int derangements(int n){
    if(n==1) return 0; //no derange possible
    if(n==2) return 1;

    int ans = (n-1) * ( derangements(n-1) + derangements(n-2) );

    return ans;
}

//Memo and tab can be written easily for this
//space opt is possible here
def knap(W, n, val, wt):
    dp = [1000000 for _ in range(W+1)]
    dp[0] = 0
    for i in range(W+1):
        for j in range(n):
            if(wt[j] <= i):
                dp[i] = min(dp[i],dp[i-wt[j]]+val[j])
    return dp[W]

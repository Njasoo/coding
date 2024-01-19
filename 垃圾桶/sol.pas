a:=1
begin
    for i := 1 to n
    begin
        for i:=1 to n
            dp[i][j]=dp[i-1][j];
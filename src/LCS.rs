fn LCS<T: Eq + Clone>(s: &Vec<T>, t: &Vec<T>) -> (usize, Vec<T>) {
    let (slen, tlen) = (s.len(), t.len());
    let mut dp = vec![vec![0; tlen+1]; slen+1];
    for i in 1..slen+1 {
        for j in 1..tlen+1 {
            if s[i-1] == t[j-1] {
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = dp[i-1][j].max(dp[i][j-1]);
            }
        }
    }
    let (mut i, mut j) = (slen, tlen);
    let mut len = dp[slen][tlen];
    let mut ret = Vec::with_capacity(len);
    while len > 0 {
        if s[i-1] == t[j-1] {
            ret.push(s[i-1].clone());
            i -= 1;
            j -= 1;
            len -= 1;
        } else if dp[i][j] == dp[i-1][j] {
            i -= 1;
        } else {
            j -= 1;
        }
    }
    ret.reverse();
    return (dp[slen][tlen], ret);
}

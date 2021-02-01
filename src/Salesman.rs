struct Salesman {
    dp: Vec<Vec<isize>>,
    n: usize,
    d: Vec<Vec<usize>>
}

impl Salesman {
    fn init(length: usize, cost: Vec<Vec<usize>>) -> Salesman {
        let table = vec![vec![-1; length]; 1<<length];
        return Salesman{dp: table, n: length, d: cost};
    }
    fn distance(&mut self, s: usize, v: usize) -> usize{
        if self.dp[s][v] != -1 {return self.dp[s][v] as usize;}
        if s == (1<<(self.n))-1 && v==0 {return 0;}
        let mut res = std::i32::MAX as usize;
        for u in 0..self.n {
            if s>>u & 1 == 0 {
                res = res.min(self.distance(s | (1<<u), u) + self.d[v][u]);
            }
        }
        self.dp[s][v] = res as isize;
        return res;
    }
}

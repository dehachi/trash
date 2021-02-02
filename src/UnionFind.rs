struct UnionFind {
    par: Vec<isize>,
    n: usize
}
 
impl UnionFind {
    fn init(length: usize) -> UnionFind {
        return UnionFind{par: vec![-1; length], n: length};
    }
    fn root(&mut self, x: usize) -> usize{
        if self.par[x] < 0 {
            return x;
        } else {
            self.par[x] = self.root(self.par[x] as usize) as isize;
            return self.par[x] as usize
        }
    }
    fn same(&mut self, x: usize, y: usize) -> bool {
        return self.root(x) == self.root(y);
    }
    fn merge(&mut self, x: usize, y: usize) -> bool{
        let mut rx = self.root(x);
        let mut ry = self.root(y);
        if rx == ry {return false;};
        if self.par[rx] > self.par[ry] {
            std::mem::swap(&mut rx, &mut ry);
        }
        self.par[rx] += self.par[ry];
        self.par[ry] = rx as isize;
        return true;
    }
    fn size(&mut self, x: usize) -> usize {
        let p = self.root(x);
        return -self.par[p] as usize;
    }
    fn status(&mut self) -> Vec<usize> {
        let mut sta = Vec::new();
        for i in 0..self.n {
            sta.push(self.root(i));
        }
        return sta;
    }
    fn islands(&mut self, begin: usize, end: usize) -> usize {
        let sta = self.status();
        let set = sta.iter().cloned().collect::<std::collections::HashSet<usize>>();
        return set.len();
    }
}

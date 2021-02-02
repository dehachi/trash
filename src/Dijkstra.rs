struct Dijkstra {
    graph: Vec<Vec<(usize, usize)>>,
    n: usize,
    dist: Vec<usize>,
    prev: Vec<isize>
}

impl Dijkstra {
    fn init(length: usize, g: Vec<Vec<(usize, usize)>>) -> Dijkstra {
        let d = vec![std::u32::MAX as usize; length];
        let p = vec![-1; length];
        return Dijkstra{graph: g, n: length, dist: d, prev: p}
    }
    fn clean(&mut self) {
        self.dist = vec![std::u32::MAX as usize; ];
    }
    fn calc(&mut self, s:usize) {
        self.dist[s] = 0;
        let mut heap = std::collections::BinaryHeap::new();
        heap.push((0, s));
        while !heap.is_empty() {
            let (d, pos) = heap.pop().unwrap();
            if d > self.dist[pos] {continue;}
            for (to, cost) in self.graph[pos].iter() {
                let next = self.dist[pos] + cost;
                if next < self.dist[*to] {
                    self.dist[*to] = next;
                    self.prev[*to] = pos as isize;
                    heap.push((next, *to));
                }
            }
        }
    }
    fn distance(&mut self, v: usize) -> usize{
        return self.dist[v];
    }
    fn path(&mut self, v: usize) -> Vec<usize> {
        let mut p = vec![];
        let mut i = v as isize;
        while i != -1 {
            p.push(i as usize);
            i = self.prev[i as usize] as isize;
        }
        p.reverse();
        return p;
    }
}

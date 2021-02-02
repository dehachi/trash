struct Dijkstra {
    graph: Vec<Vec<(usize, usize)>>,
    n: usize,
    dist: Vec<usize>
}

impl Dijkstra {
    fn init(length: usize, g: Vec<Vec<(usize, usize)>>) -> Dijkstra {
        let d = vec![std::u32::MAX as usize; length+5];
        return Dijkstra{graph: g, n: length, dist: d}
    }
    fn calc(&mut self, s:usize) {
        self.dist[s] = 0;
        let mut heap = std::collections::BinaryHeap::new();
        heap.push((0, s));
        while !heap.is_empty() {
            let (d, pos) = heap.pop().unwrap();
            if d > self.dist[pos] {continue;}
            for (to, cost) in self.graph[pos].iter() {
                let next = &self.dist[pos] + cost;
                if next < self.dist[*to] {
                    self.dist[*to] = next;
                    heap.push((next, *to));
                }
            }
        }
    }
    fn distance(&mut self, v: usize) -> usize{
        return self.dist[v];
    }
}

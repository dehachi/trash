mod Dijkstra {
    fn distance(n: usize, graph: &Vec<Vec<(usize, isize)>>, s: usize, mode: u8) -> Vec<isize> {
        let mut dist = vec![std::usize::MAX as isize; n];
        let mut prev = vec![-1; n];
        dist[s] = 0;
        let mut heap = std::collections::BinaryHeap::new();
        heap.push((0, s));
        while !heap.is_empty() {
            let (d, pos) = heap.pop().unwrap();
            if d > dist[pos] {continue;}
            for (to, cost) in graph[pos].iter() {
                let next = dist[pos] + cost;
                if next < dist[*to] {
                    dist[*to] = next;
                    prev[*to] = pos as isize;
                    heap.push((-next, *to));
                }
            }
        }
        if mode == 0 {
            return dist;
        } else {
            return prev;
        }
    }
    fn path(v: usize, prev: Vec<isize>) -> Vec<usize> {
        let mut p = vec![];
        let mut i = v as isize;
        while i != -1 {
            p.push(i as usize);
            i = prev[i as usize] as isize;
        }
        p.reverse();
        return p;
    }
}

fn rle<T:Eq + Copy>(v: Vec<T>) -> Vec<(T, usize)>{
    let mut ret: Vec<(T, usize)> = vec![];
    let (n, mut l) = (v.len(), 0);
    while l < n {
        let mut r = l + 1;
        while r < n && v[l] == v[r] {r += 1}
        let p = v[l];
        ret.push((p, r-l));
        l = r;
    }
    return ret;
}
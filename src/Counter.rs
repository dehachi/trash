fn Counter<T: Eq + Hash>(v: Vec<T>) -> HashMap<T, usize> {
    let mut hm = HashMap::new();
    for i in v {
        let cnt = hm.entry(i).or_insert(0);
        *cnt += 1;
    }
    return hm;
}

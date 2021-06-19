fn Counter<T: Eq + std::hash::Hash>(v: Vec<T>) -> std::collections::HashMap<T, usize> {
    let mut hm = std::collections::HashMap::new();
    for i in v {
        let cnt = hm.entry(i).or_insert(0);
        *cnt += 1;
    }
    return hm;
}

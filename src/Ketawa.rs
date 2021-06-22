fn Ketawa(mut n: &usize) -> usize {
    let mut ret = 0;
    let mut n = n.clone();
    while n > 0 {
        ret += n % 10;
        n /= 10;
    }
    return ret;
}

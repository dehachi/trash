fn main() {
    input! {
        s:String
    }
    let r = rle(s.chars().collect::<Vec<char>>());
    println!("{:?}", r.len()-1);
}
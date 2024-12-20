use std::io;

fn main() {
    let mut a = Vec::new();
    let mut b = Vec::new();

    for _ in 0..1000{
        let mut input=String::new();
        io::stdin().read_line(&mut input).unwrap();
        let nums: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        a.push(nums[0]);
        b.push(nums[1]);
    }
    let mut similarityscore = 0;
    for &leftnum in &a {
        let mut count = 0;
        for &rightnum in &b{
            if leftnum == rightnum {
                count += 1;
            }
        }
        similarityscore += leftnum * count;
    }

    println!("Similarity Score: {}", similarityscore);
}

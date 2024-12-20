use std::io;

fn main(){
    let mut a = Vec::new();
    let mut b = Vec::new();

    for _ in 0..1000{
        let mut input=String::new();
        io::stdin().read_line(&mut input).unwrap();
        let nums: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
        a.push(nums[0]);
        b.push(nums[1]);
    }
    a.sort();
    b.sort();
    let mut distance:i32=0;
    for i in 0..1000{
        if a[i]>b[i]{
            distance+=a[i]-b[i];
        }
        else{
            distance+=b[i]-a[i];
        }
    }
    println!("{}",distance);
}
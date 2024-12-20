use std::io;

fn main(){
    let mut count=0;
    for _ in 0..1000{
        let mut a = Vec::new();
    
        for _ in 0..1000{
            let mut input=String::new();
            io::stdin().read_line(&mut input).unwrap();
            let nums: Vec<i32> = input.trim().split_whitespace().map(|x| x.parse().unwrap()).collect();
            a.push(nums[0]);
            a.push(nums[1]);
        }
        let mut flag:i32=0;
        let mut isvalid=true;
        for j in 1..2000{
            let diff:i32=a[j]-a[j-1];
            if diff>0 && diff<4 && flag!=-1{
                flag=1;
            }
            else if diff<0 && diff >-4 && flag!=1{
                flag=-1;
            }
            else{
                isvalid=false;
                break;
            }
        }
        if isvalid{
            count+=1;
        }
    }
    println!("{}",count);
}
    

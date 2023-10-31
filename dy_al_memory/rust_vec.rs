use std::io;

fn main() {
      
        let (a, b) = get_matrix_size();
        println!("첫 번째 행렬을 입력하세요: ");
        let mx1 = get_matrix(a, b);
        println!("두 번째 행렬을 입력하세요: ");
        let mx2 = get_matrix(a, b);
        let mx_sum = add_matrices(&mx1, &mx2);
        println!("결과 행렬:");     
        print_matrix(&mx_sum);

}

fn get_matrix_size() -> (usize, usize){
    let mut input = String::new();

    println!("행렬의 행과 열의 크기를 입력하세요:");
    io::stdin().read_line(&mut input).expect("입력 오류");

    let sizes: Vec<usize> = input.split_whitespace().map(|s| s.parse().expect("올바른 숫자를 입력하세요")).collect();

    if sizes.len() != 2{
        panic!("행, 열 크기를 두 개 입력하세요");
    }

    (sizes[0], sizes[1])
}

fn get_matrix(a:usize, _b:usize) -> Vec<Vec<i32>>{
    let mut matrix = Vec::new();

    for _ in 0..a{
        for _ in 0.._b{
        let mut a_input = String::new();
        io::stdin().read_line(&mut a_input).expect("입력 오류");

    let row: Vec<i32> = a_input.split_whitespace().map(|s| s.parse().expect("올바른 숫자를 입력하세요")).collect();
        
    matrix.push(row);
        }
        }
    matrix
}

fn add_matrices(mx1 : &Vec<Vec<i32>>, mx2: &Vec<Vec<i32>>) -> Vec<Vec<i32>> {
    let mut add_mx = Vec::new();

    for (r1, r2) in mx1.iter().zip(mx2.iter()){
        let mut add_row = Vec::new();
        for (e1, e2) in r1.iter().zip(r2.iter()){
            add_row.push(e1 + e2);
        }
        add_mx.push(add_row);
    }
    add_mx
}

fn print_matrix(mx: &Vec<Vec<i32>>) {
    for a in mx.iter(){
        for el in a.iter(){
            print!("{}", el);
        }
        println!();
    }
}
        
    

use std::collections::BTreeMap;
use std::io;

struct Student{
    name : String,
    midterm : u32,
    finalterm : u32,
}

impl Student{
    fn new(name: String, midterm: u32, finalterm: u32) -> Self {
        Student {name, midterm, finalterm}
    }
}

fn main() {
    let mut num_students = String::new();
    println!("학생 수를 입력하세요 : ");
    io::stdin().read_line(&mut num_students).expect("입력을 실패했습니다.");
    let num_students: u32 = num_students.trim().parse().expect("입력이 올바르지 않습니다");
    
    let mut student_tree = BTreeMap::new();

    for i in 0..num_students{
        let mut name = String::new();
        let mut midterm = String::new();
        let mut finalterm = String::new();
    
        println!("{}번째 학생의 이름을 입력해주세요: ", i+1);
        io::stdin().read_line(&mut name).expect("입력을 실패했습니다.");

        println!("{} 학생의 중간고사 성적을 입력해주세요: ", name);
        io::stdin().read_line(&mut midterm).expect("입력을 실패했습니다.");
        let midterm: u32 = midterm.trim().parse().expect("입력이 올바르지 않습니다.");

        println!("{} 학생의 기말고사 성적을 입력해주세요: ", name);
        io::stdin().read_line(&mut finalterm).expect("입력을 실패했습니다.");
        let finalterm: u32 = finalterm.trim().parse().expect("입력이 올바르지 않습니다.");

        let student = Student::new(name.trim().to_string(),midterm,finalterm);
        student_tree.insert(i,student);
    }

    println!("\nStudent information:");
    for (key, value) in student_tree.iter() {
                println!("{}번째 학생 이름: {}, 중간고사 성적: {}, 기말고사 성적: {}", key + 1, value.name, value.midterm, value.finalterm);
            }

    let mut search_name = String::new();
    println!("Enter the name of the student to search: ");
    io::stdin().read_line(&mut search_name).expect("Failed to read line");
    let search_name = search_name.trim();
        
    match student_tree.iter().find(|(_, student)| student.name == search_name) { 
        Some((_key, value)) => {
                println!("탐색 결과 - 이름: {}, 중간고사 성적: {}, 기말고사 성적: {}",value.name, value.midterm, value.finalterm);
        }
        None => {
                println!("탐색 결과 - 해당 학생을 찾지 못하였습니다.");
        }
    }
}


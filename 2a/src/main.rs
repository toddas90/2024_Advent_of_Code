use core::num;
use std::{
    fs::File,
    io::{BufRead, BufReader},
};

fn main() {
    let file = File::open("input.txt").expect("file wasn't found.");
    let reader = BufReader::new(file);

    let numbers: Vec<Vec<i32>> = reader
        .lines()
        .map(|line| {
            line.unwrap()
                .split(' ')
                .map(|num| num.parse::<i32>().unwrap())
                .collect::<Vec<_>>()
        })
        .collect();

    let mut incorrect: Vec<Vec<i32>> = Vec::new();

    let mut safe_reports = 0;

    for chunk in numbers.clone() {
        if check_sorted(&chunk) && check_distance(&chunk) {
            safe_reports += 1;
        } else {
            incorrect.push(chunk);
        }
    }

    // Handle incorrect chunks
    for chunk in incorrect.clone() {
        for i in 0..chunk.len() {
            let mut temp = chunk.clone();
            temp.remove(i);
            if check_sorted(&temp) && check_distance(&temp) {
                safe_reports += 1;
                break;
            }
        }
    }

    println!("Total Safe Reports: {}", safe_reports);
}

fn check_sorted(input: &[i32]) -> bool {
    input.is_sorted_by(|a, b| a < b) || input.is_sorted_by(|a, b| a > b)
}

fn check_distance(input: &[i32]) -> bool {
    for i in 1..input.len() {
        if i32::abs(input[i - 1] - (input[i])) > 3 {
            return false;
        }
    }
    true
}

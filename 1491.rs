use std::collections::{binary_heap, HashSet};
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};


impl Solution {
    pub fn average(salary: Vec<i32>) -> f64 {
        let mut avg_salary: f64 = 0f64;
        let mut min_salary: i32 = i32::max_value();
        let mut max_salary: i32 = i32::min_value();
        for i in 0..salary.len() {
            avg_salary += salary[i] as f64;
            if salary[i] < min_salary {
                min_salary = salary[i];
            }
            if salary[i] > max_salary {
                max_salary = salary[i];
            }
        }
        (avg_salary - min_salary as f64 - max_salary as f64) / (salary.len() - 2) as f64
    }
}


struct Solution;


pub fn main() {

}
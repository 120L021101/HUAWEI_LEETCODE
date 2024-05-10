use std::collections::{binary_heap, HashSet};
use std::process::id;
use std::sync::TryLockError;
use std::thread::current;
use std::{default, string, vec};
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};


impl Solution {
    pub fn count_tested_devices(battery_percentages: Vec<i32>) -> i32 {
        let mut count = 0i32;
        for i in 0..battery_percentages.len() {
            if battery_percentages[i] <= count {
                continue;
            }
            count += 1;
        }
        count
    }
}


struct Solution;


pub fn main() {

}
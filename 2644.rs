use std::collections::{binary_heap, HashSet};
use std::process::id;
use std::sync::TryLockError;
use std::thread::current;
use std::{default, string, vec};
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};

impl Solution {
    pub fn max_div_score(nums: Vec<i32>, divisors: Vec<i32>) -> i32 {
        let mut max_idx: usize = 0;
        let mut max_score: i32 = -1;
        for j in 0..divisors.len() {
            let mut score = 0;
            for i in 0..nums.len() {
                if nums[i] % divisors[j] == 0 {
                    score += 1;
                }
            }
            if score > max_score || (score == max_score && divisors[j] < divisors[max_idx]) {
                max_idx = j;
                max_score = score;
            }
        }
        divisors[max_idx]
    }
}
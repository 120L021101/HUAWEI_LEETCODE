use std::collections::binary_heap;
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut idxMap: HashMap<i32, usize> = HashMap::new();
        for idx in 0..nums.len() {
            let find_val: i32 = target - nums[idx];
            if idxMap.contains_key(&find_val) {
                return vec![*idxMap.get(&find_val).unwrap() as i32, idx as i32];
            }
            idxMap.insert(nums[idx], idx);

        }
        unreachable!();
    }
}
struct Solution;


pub fn main() {

}
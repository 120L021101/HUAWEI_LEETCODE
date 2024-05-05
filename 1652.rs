use std::collections::{binary_heap, HashSet};
use std::process::id;
use std::sync::TryLockError;
use std::thread::current;
use std::{default, string, vec};
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};

impl Solution {
    pub fn decrypt(code: Vec<i32>, k: i32) -> Vec<i32> {
        if k == 0 {
            return vec![0; code.len()];
        }
        let mut retVec: Vec<i32> = vec![0; code.len()];
        let mut left: usize = 0;
        let mut right: usize = 0;
        let mut window_sum: i32 = 0;
        if k > 0 {
            left = 1;
        }
        if k < 0 {
            left = (code.len() as i32 + k) as usize;
        }
        right = left;
        for i in 0..k.abs() {
            window_sum += code[right];
            right = (right + 1) % code.len();
        }
        for i in 0..code.len() {
            retVec[i] = window_sum;
            window_sum -= code[left];
            left = (left + 1) % code.len();
            window_sum += code[right];
            right = (right + 1) % code.len();
        }
        
        retVec
    }
}
struct Solution;


pub fn main() {

}
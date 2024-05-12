use std::collections::{binary_heap, HashSet};
use std::process::id;
use std::sync::TryLockError;
use std::thread::current;
use std::{default, string, vec};
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};


impl Solution {
    fn dfs(n: i32, mem: &mut HashMap<i32, usize>) -> usize {
        if mem.contains_key(&n) {
            return mem.get(&n).unwrap().clone()
        }
        match (n) {
            (0i32) => return 0,
            (1i32) => return 1,
            (_) => (),
        }
        let op1: usize = Solution::dfs(n / 3, mem) + 1 + n as usize % 3;
        let op2: usize = Solution::dfs(n / 2, mem) + 1 + n as usize % 2;
        let mut minOp = op1;
        if op2 < op1 {
            minOp = op2;
        }
        mem.insert(n.clone(), minOp.clone());
        minOp
    }
    pub fn min_days(n: i32) -> i32 {
        let mut mem: HashMap<i32, usize> = HashMap::new();
        Solution::dfs(n, &mut mem) as i32
    }
}


struct Solution;


pub fn main() {

}
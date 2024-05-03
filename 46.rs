use std::collections::{binary_heap, HashSet};
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};


impl Solution {
    pub fn dfs(ans:&mut Vec<Vec<i32>>, visited:&mut Vec<bool>, cur:&mut Vec<i32>, nums:&mut Vec<i32>) -> () {
        if cur.len() == nums.len() {
            ans.push(cur.clone());
            return ()
        }
        for i in 0..visited.len() {
            if !visited[i] {
                visited[i] = true;
                cur.push(nums[i]);
                Solution::dfs(ans, visited, cur, nums);
                visited[i] = false;
                cur.pop();
            }
        }
    }
    pub fn permute(nums: Vec<i32>) -> Vec<Vec<i32>> {
        let mut ans: Vec<Vec<i32>> = vec![];
        let mut visited: Vec<bool> = vec![false; nums.len()];
        let mut cur: Vec<i32> = vec![];
        Solution::dfs(&mut ans, &mut visited, &mut cur, &mut nums.clone());
        ans
    }
}


struct Solution;


pub fn main() {

}
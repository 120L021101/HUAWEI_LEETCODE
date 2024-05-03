use std::collections::{binary_heap, HashSet};
use std::thread::current;
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};

impl Solution {
    pub fn dfs(numMap:&mut HashMap<i32, i32>, nums:& Vec<i32>, cur:&mut Vec<i32>,
               idx: usize, ans:&mut Vec<Vec<i32>>) -> ()
    {
        if idx == nums.len() {
            ans.push(cur.clone());
            return     
        };
        for key in numMap.clone().keys() {
            if 0 == *numMap.get(key).unwrap() {
                continue;
            }
            numMap.insert(*key, *numMap.get(key).unwrap() - 1);
            cur.push(*key);
            Solution::dfs(numMap, nums, cur, idx + 1, ans);
            cur.pop();
            numMap.insert(*key, *numMap.get(key).unwrap() + 1);
        }
    }

    pub fn permute_unique(nums: Vec<i32>) -> Vec<Vec<i32>>
    {
        let mut numMap: HashMap<i32, i32> = HashMap::new();
        for i in 0..nums.len() {
            if !numMap.contains_key(&nums[i]) {
                numMap.insert(nums[i], 0);
            }
            numMap.insert(nums[i], numMap.get(&nums[i]).unwrap() + 1);
        }
        let mut ans: Vec<Vec<i32>> = vec![];
        Solution::dfs(&mut numMap, &nums, &mut vec![], 0, &mut ans);
        ans
    }
}


struct Solution;


pub fn main() {

}
use std::{collections::HashMap, hash::Hash};


impl Solution {
    pub fn min_cost(nums: Vec<i32>, x: i32) -> i64 {
        if nums.len() == 1 {
            return nums[0] as i64
        }
        let mut dp: Vec<Vec<i64>> = vec![];
        
        let mut oneRow: Vec<i64> = vec![];
        for i in 0..nums.len() {
            oneRow.push(0);
        }
        for i in 0..nums.len() {
            dp.push(oneRow.clone());    
        }
        for i in 0..nums.len() {
            dp[0][i] = nums[i] as i64;
        }
        let mut loop_idx: usize = 1;
        loop {
            for i in 0..nums.len() {
                let t_i: usize = (nums.len() + i - loop_idx) % nums.len();
                dp[loop_idx][i] = dp[0][t_i]
            }
            loop_idx += 1;
            if loop_idx == nums.len() {
                break;
            }
        }
        let mut min_values: Vec<i64> = dp[0].clone();
        let mut accCost: i64 = 0;
        let mut minCost: i64 = 0;
        for i in 0..nums.len() {
            minCost += nums[i] as i64;
        }
        loop_idx = 1;
        loop {
            accCost += x as i64;
            let mut curCost = 0;
            for i in 0..nums.len() {
                if dp[loop_idx][i] < min_values[i] {
                    min_values[i] = dp[loop_idx][i];
                }
                curCost += min_values[i];
            }

            if curCost + accCost < minCost {
                minCost = curCost + accCost;
            }
            loop_idx += 1;
            if loop_idx == nums.len() {
                break;
            }
        }
        minCost
    }
}




use std::collections::{binary_heap, HashSet};
use std::process::id;
use std::sync::TryLockError;
use std::thread::current;
use std::{default, string, vec};
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};

impl Solution {

    fn binarySearch(job:& Vec<Vec<i32>>, e: i32, searchTime: i32) -> i32 {

        let mut start = 0i32;
        let mut end = e;

        while start < end {

            let middle = (start + end) / 2;
            if job[middle as usize][1] == searchTime {
                break;
            }
            
            if job[middle as usize][1] < searchTime {
                start = middle + 1;
            }
            else {
                end = middle - 1;
            }
        }

        let mut ret_idx = start;
        if job[ret_idx as usize][1] == searchTime {
            while ret_idx < e && job[ret_idx as usize][1] == searchTime {
                ret_idx += 1;
            }
            return ret_idx - 1
        }
        if (job[ret_idx as usize][1] > searchTime) {
            while ret_idx >= 0 && job[ret_idx as usize][1] > searchTime {
                ret_idx -= 1;
            }
            return ret_idx
        }
        while ret_idx < e && job[ret_idx as usize][1] <= searchTime {
            ret_idx += 1;
        }
        
        if ret_idx == e || job[ret_idx as usize][1] > searchTime {
            ret_idx -= 1;
        }
        ret_idx
    }

    pub fn job_scheduling(start_time: Vec<i32>, end_time: Vec<i32>, profit: Vec<i32>) -> i32 {
        let mut job: Vec<Vec<i32>> = vec![];
        let mut dp: Vec<i32> = vec![0; start_time.len()];
        
        for i in 0..start_time.len() {
            job.push(vec![start_time[i], end_time[i], profit[i]]);
        }
        job.sort_by(|a, b| a[1].partial_cmp(&b[1]).unwrap());
        dp[0] = job[0][2];

        for i in 1..job.len() {
            let (start, end, pro) = (job[i][0], job[i][1], job[i][2]);
            dp[i] = dp[i - 1]; // 不选这个工作
            let lastDoableJobIdx = Solution::binarySearch(&job, i as i32, start);
            let mut lastProfit = pro;
            if lastDoableJobIdx != -1 {
                lastProfit = dp[lastDoableJobIdx as usize] + pro;
            }
            if lastProfit > dp[i] {
                dp[i] = lastProfit;
            }
        }

        dp[dp.len() - 1]
    }
}

struct Solution;


pub fn main() {

}
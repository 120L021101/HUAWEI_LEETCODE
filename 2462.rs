use std::collections::binary_heap;
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};

#[derive(PartialEq, Eq, Clone, Copy, Debug)]
struct Item {
    cost: i32,
    idx: usize,
}

impl Ord for Item {
    fn cmp(&self, other: &Self) -> Ordering {
        self.cost.cmp(&other.cost).reverse()
    }
}
impl PartialOrd for Item {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}


impl Solution {
    pub fn total_cost(costs: Vec<i32>, k: i32, candidates: i32) -> i64 {
        let mut t_cost: i64 = 0;

        let mut l_idx: usize = 0;
        let mut r_idx: usize = costs.len() - 1;
        let mut cnt: i32 = 0;
        
        let mut heap: BinaryHeap<Item> = BinaryHeap::new();

        loop {
            if cnt == candidates {
                break;
            }
            if l_idx == r_idx {
                heap.push(Item{
                    cost: costs[l_idx],
                    idx: l_idx,
                });
                l_idx += 1;
            }
            if l_idx > r_idx {
                break;
            }
            heap.push(Item{
                cost: costs[l_idx],
                idx: l_idx,
            });
            heap.push(Item{
                cost: costs[r_idx],
                idx: r_idx
            });

            l_idx += 1;
            r_idx -= 1;

            cnt += 1;
        }

        cnt = 0;
        loop {
            if cnt == k {
                break;
            }
            cnt += 1;

            let top_item = heap.pop().unwrap();
            t_cost += top_item.cost as i64;

            if l_idx > r_idx {
                continue;
            }
            if top_item.idx < l_idx {
                heap.push(Item{
                    cost: costs[l_idx],
                    idx: l_idx
                });
                l_idx += 1;
            }
            else {
                heap.push(Item{
                    cost: costs[r_idx],
                    idx: r_idx
                });
                r_idx -= 1;
            }
        }

        t_cost
    }
}


struct Solution;


pub fn main() {

}
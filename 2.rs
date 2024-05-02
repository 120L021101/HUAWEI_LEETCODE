use std::collections::binary_heap;
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};

#[derive(PartialEq, Eq, Clone, Debug)]
pub struct ListNode {
  pub val: i32,
  pub next: Option<Box<ListNode>>
}

impl ListNode {
  #[inline]
  fn new(val: i32) -> Self {
    ListNode {
      next: None,
      val
    }
  }
}
impl Solution {
    pub fn add_two_numbers(l1: Option<Box<ListNode>>, l2: Option<Box<ListNode>>) -> Option<Box<ListNode>> {
        let mut l1_node: &Option<Box<ListNode>> = &l1;
        let mut l2_node: &Option<Box<ListNode>> = &l2;
        
        let mut retNode = Some(Box::new(ListNode::new(-1)));
        let mut pointer = &mut retNode;
        let mut C = 0;

        while !l1_node.is_none() || !l2_node.is_none() || C != 0 {
            let mut val = 0;

            if !l1_node.is_none() {
                val += l1_node.as_ref().unwrap().val;
                l1_node = &l1_node.as_ref().unwrap().next;
            }
            if !l2_node.is_none() {
                val += l2_node.as_ref().unwrap().val;
                l2_node = &l2_node.as_ref().unwrap().next;
            }
            val += C;
            C = val / 10;
            val %= 10;
            pointer.as_mut().unwrap().next = Some(Box::new(ListNode::new(val)));
            pointer = &mut pointer.as_mut().unwrap().next;
        }

        return retNode.unwrap().next;
    }
}


struct Solution;


pub fn main() {

}
use std::collections::{binary_heap, HashSet};
use std::process::id;
use std::thread::current;
use std::{string, vec};
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};

impl Solution {

    fn getWord2idx(word_list:& Vec<String>) -> HashMap<String, usize> {
        let mut word2idx: HashMap<String, usize> = HashMap::new();
        for i in 0..word_list.len() {
            word2idx.insert(word_list[i].clone(), i);
        }
        word2idx
    }

    fn getKeys(word:& String) -> Vec<String> {
        let mut keyList: Vec<String> = vec![];

        for i in 0..word.len() {
            let mut transWord = String::from("");
            transWord += word.get(0..i).unwrap();
            transWord += "*";
            transWord += word.get(i+1..).unwrap();
            keyList.push(transWord);
        }
        keyList
    }

    fn getEdgeMap(word2idx:& HashMap<String, usize>, word_list:& Vec<String>) -> HashMap<usize, Vec<usize>> {
        let mut edgeMap: HashMap<usize, Vec<usize>> = HashMap::new();
        let mut linkedNodeMap: HashMap<String, Vec<usize>> = HashMap::new();

        for word in word_list.iter() {
            let keyList = Solution::getKeys(word);
            for key in keyList.iter() {
                if !linkedNodeMap.contains_key(key) {
                    linkedNodeMap.insert(key.clone(), vec![]);
                }
                linkedNodeMap.get_mut(key).unwrap().push(*word2idx.get(word).unwrap());
            }
        }        
        let mut edgeMap: HashMap<usize, Vec<usize>> = HashMap::new();
        for (key, value) in linkedNodeMap.iter() {
            for i in 0..value.len() {
                if !edgeMap.contains_key(&value[i]) {
                    edgeMap.insert(value[i], vec![]);
                }
                let mut insertList = edgeMap.get_mut(&value[i]).unwrap();
                for j in 0..value.len() {
                    if i == j {
                        continue;
                    }
                    insertList.push(value[j]);
                }
            }
        }
        edgeMap
    }

    fn getLaddersViaDfs(lastNodeRecord:& Vec<Option<HashSet<usize>>>, idx2word:& HashMap<usize, String>, node: usize, begin: usize, end: usize, ans:&mut Vec<Vec<String>>, cur:&mut Vec<usize>) {
        cur.push(node);
        if node == begin {
            let mut wordPath:Vec<String> = vec![];
            for idx in cur.iter() {
                wordPath.push(idx2word.get(idx).unwrap().clone());
            }
            wordPath.reverse();
            ans.push(wordPath);
            cur.pop();
            return;
        }

        for lastIdx in lastNodeRecord[node].as_ref().unwrap().iter() {
            Solution::getLaddersViaDfs(lastNodeRecord, idx2word, *lastIdx, begin, end, ans, cur);
        }

        cur.pop();
    }


    fn getLaddersViaBFS(word2idx:& HashMap<String, usize>, edgeMap:& HashMap<usize, Vec<usize>>, begin: usize, end: usize, ) -> Vec<Vec<String>>{
        let mut ans: Vec<Vec<String>> = vec![];
        let mut lastNodeRecord: Vec<Option<HashSet<usize>>> = vec![None; word2idx.len()];
        let mut levelOrder: Vec<usize> = vec![begin];

        lastNodeRecord[begin] = Some(HashSet::new());

        while !levelOrder.is_empty() {
            let mut nextLevel: Vec<usize> = vec![];
            let mut visited: HashSet<usize> = HashSet::new();
            for node in levelOrder.iter() {
                if !edgeMap.contains_key(node) {
                    continue;
                }
                for linkedNode in edgeMap.get(node).unwrap().iter() {
                    if !lastNodeRecord[*linkedNode].is_none() && !visited.contains(linkedNode) {
                        continue;
                    }
                    if !visited.contains(linkedNode) {
                        nextLevel.push(*linkedNode);
                        visited.insert(*linkedNode);
                    }
                    if lastNodeRecord[*linkedNode].is_none() {
                        lastNodeRecord[*linkedNode] = Some(HashSet::new());
                    }
                    lastNodeRecord[*linkedNode].as_mut().unwrap().insert(*node);
                }
            }

            levelOrder = nextLevel;
        }
        if lastNodeRecord[end].as_ref().is_none() {
            return vec![]
        }

        let mut idx2Word: HashMap<usize, String> = HashMap::new();
        for (key, value) in word2idx.iter() {
            idx2Word.insert(*value, key.clone());
        }

        Solution::getLaddersViaDfs(&lastNodeRecord, &idx2Word, end, begin, end, &mut ans, &mut vec![]);

        ans
    }

    pub fn find_ladders(begin_word: String, end_word: String, word_list: Vec<String>) -> Vec<Vec<String>> {
        let mut word_list = word_list.clone();
        if !word_list.contains(&begin_word) {
            word_list.push(begin_word.clone());
        }
        let word2idx = Solution::getWord2idx(&word_list);
        if !word2idx.contains_key(&end_word) {
            return vec![];
        }
        let edgeMap = Solution::getEdgeMap(&word2idx, &word_list);

        Solution::getLaddersViaBFS(&word2idx, &edgeMap, *word2idx.get(&begin_word).unwrap(), *word2idx.get(&end_word).unwrap())
    }
}


struct Solution;


pub fn main() {

}
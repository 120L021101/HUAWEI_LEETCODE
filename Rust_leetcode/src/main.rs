use std::{collections::HashMap, hash::Hash};


impl Solution {
    pub fn minimum_distance(n: i32, edges: Vec<Vec<i32>>, s: i32, marked: Vec<i32>) -> i32 {
        let mut edge_map: HashMap<i32, Vec<Vec<i32>>> = HashMap::new();
        for edge in edges {
            if !edge_map.contains_key(&edge[0]) {
                edge_map.insert(edge[0], Vec::new());
            }
            edge_map.get_mut(&edge[0]).unwrap().push(vec![edge[1], edge[2]]);
        }
        let mut distances = vec![];
        let mut visited = vec![];
        for i in 0..n {
            distances.push(-1);
            visited.push(0);
        }
        distances[s as usize] = 0;
        visited[s as usize] = 1;

        loop {
            let mut min_distance = -1;
            let mut add_node = -1;
            for i in 0..n {
                if visited[i as usize] == 0 {
                    continue;
                }
                if !edge_map.contains_key(&i) {
                    continue;
                }
                for e in edge_map.get_mut(&i).unwrap() {
                    if visited[e[0] as usize] == 1 {
                        continue;
                    }
                    if min_distance == -1 || distances[i as usize] + e[1] < min_distance {
                        min_distance = distances[i as usize] + e[1];
                        add_node = e[0];
                    }
                }
            }
            if min_distance == -1 {
                break;
            }
            distances[add_node as usize] = min_distance;
            visited[add_node as usize] = 1;
        }
        let mut min_distance = -1;
        for marked_idx in marked {
            if -1 == distances[marked_idx as usize] {
                continue;
            }
            if min_distance == -1 || distances[marked_idx as usize] < min_distance {
                min_distance = distances[marked_idx as usize];
            }
        }
        min_distance
    }
}






struct Solution;


pub fn main() {

}
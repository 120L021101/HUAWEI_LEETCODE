use std::collections::{binary_heap, HashSet};
use std::process::id;
use std::sync::TryLockError;
use std::thread::current;
use std::{default, string, vec};
use std::{collections::HashMap, hash::Hash, collections::BinaryHeap};
use std::cmp::{Ord, Ordering};

#[derive(PartialEq, Eq)]
enum Status {
    JustStop,
    Failed,
    Reached,
}
#[derive(PartialEq, Eq, Clone, Copy, Hash)]
enum Direction {
    Down,
    Left,
    Right,
    Up,
    Undecided,
}
// dlru

impl Solution {

    fn dfs(visited:&mut HashMap<Vec<i32>, HashSet<Direction>>, maze:& Vec<Vec<i32>>, pos:& Vec<i32>, hole:& Vec<i32>, direction:& Direction, curPath: &mut Vec<Vec<i32>>) -> Status {
        if !visited.contains_key(pos) {
            visited.insert(pos.clone(), HashSet::new());
        }
        let (x, y) = (pos[0], pos[1]);
        if x == -1 || y == -1 || x == maze.len() as i32 || y == maze[0usize].len() as i32 {
            return Status::JustStop
        }
        if maze[x as usize][y as usize] == 1 {
            return Status::JustStop
        }
        if visited.get(pos).as_ref().unwrap().contains(direction) {
            return Status::Failed
        }
        visited.get_mut(pos).as_mut().unwrap().insert(direction.clone());
        let mut nextX = x;
        let mut nextY = y;
        match direction {
            Direction::Left  => { nextX = nextX;     nextY = nextY - 1; },
            Direction::Right => { nextX = nextX;     nextY = nextY + 1; },
            Direction::Up    => { nextX = nextX - 1; nextY = nextY;     },
            Direction::Down  => { nextX = nextX + 1; nextY = nextY;     },
            Direction::Undecided => { nextX = -1; nextY = -1; },
        }
        let tryResult = Solution::dfs(visited, maze, &vec![nextX, nextY], hole, &direction, curPath);
        match tryResult {
            Status::Reached | Status::Failed => { return tryResult },
            Status::JustStop => {},
        }
        if x == hole[0] && y == hole[1] {
            return Status::Reached
        }
        let mut nextTry: Vec<Vec<i32>>;
        let mut nextDirection: Vec<Direction>;
        match direction {
            Direction::Down | Direction::Up =>    {
                nextTry = vec![vec![x, y - 1], vec![x, y + 1]];
                nextDirection = vec![Direction::Left, Direction::Right];
            },
            Direction::Left | Direction::Right => {
                nextTry = vec![vec![x - 1, y], vec![x + 1, y]];
                nextDirection = vec![Direction::Up, Direction::Down];
            },
            Direction::Undecided => { 
                nextTry = vec![vec![x, y - 1], vec![x, y + 1], vec![x - 1, y], vec![x + 1, y]];
                nextDirection = vec![Direction::Left, Direction::Right, Direction::Up, Direction::Down];
            },
        }
        for i in 0..nextTry.len() {
            let (n_try, n_direction) = (nextTry[i].clone(), nextDirection[i].clone());
            let tryResult = Solution::dfs(visited, maze, &n_try, hole, &n_direction, curPath);
            match tryResult {
                Status::Reached => { return Status::Reached },
                Status::JustStop => {
                    if x == hole[0] && y == hole[1] {
                        return Status::Reached
                }},
                Status::Failed => {},
            }
        }

        Status::Failed
    }

    pub fn has_path(maze: Vec<Vec<i32>>, start: Vec<i32>, destination: Vec<i32>) -> bool {
        Status::Reached == Solution::dfs(&mut HashMap::new(), &maze, &start, &destination, &Direction::Undecided, &mut vec![])
    }
}
struct Solution;


pub fn main() {

}
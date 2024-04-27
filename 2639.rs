impl Solution {

    pub fn find_column_width(grid: Vec<Vec<i32>>) -> Vec<i32> {
        let mut ans: Vec<i32> = vec![];
        
        let (m, n) = (grid.len(), grid[0].len());

        for col in 0..n {
            let mut max_len = 0;
            for row in 0..m {
                let len = format!("{}", grid[row][col]).len();
                if len > max_len {
                    max_len = len;
                } 
            }
            ans.push(max_len as i32);
        }
        ans
    }
}

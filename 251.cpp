class Vector2D {

private:
    vector<vector<int>> data;
    vector<vector<int>>::iterator all_end;
    vector<vector<int>>::iterator all_itr;
    int cur_idx = 0;

private:
    inline void skip() {
        while(all_itr != all_end && all_itr->empty())
            all_itr ++;
    }
public:
    Vector2D(vector<vector<int>>& vec) {
        data = vec;
        all_itr = data.begin();
        all_end = data.end();
        skip();
    }
    
    int next() {
        int val = (*all_itr)[cur_idx ++];
        if (cur_idx != all_itr->size()) 
            return val;
        
        all_itr ++;
        skip();
        cur_idx = 0;

        return val;
    }
    
    bool hasNext() {
        return all_itr != all_end;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
class MedianFinder {
private:
    priority_queue<int, vector<int>, less<int>> queueMin;
    priority_queue<int, vector<int>, greater<int>> queueMax;


public:
    MedianFinder() {

    }
    
    void addNum(int num) {
        if (queueMin.empty()) {
            queueMin.push(num);
            return ;
        }
        int mid_num = queueMin.top(); // 并不一定是中位数，但细细想来是等价的
        if (num <= mid_num) {
            queueMin.push(num);
            if (queueMin.size() == queueMax.size() + 2) {
                queueMax.push(queueMin.top());
                queueMin.pop();
            }
        } else {
            queueMax.push(num);
            if (queueMin.size() == queueMax.size() - 1) {
                queueMin.push(queueMax.top());
                queueMax.pop();
            }
        }
    }
    
    double findMedian() {
        bool odd_num = queueMin.size() > queueMax.size();
        if (odd_num) {
            return queueMin.top();
        }
        return (queueMin.top() + (float)queueMax.top()) / 2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
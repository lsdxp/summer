class MedianFinder {
private:
    int count = 0;
    priority_queue<int, vector<int>, less<int> > maxheap;
    priority_queue<int, vector<int>, greater<int> > minheap;
public:

    // Adds a number into the data structure.
    void addNum(int num) {
        count++;
        if(count%2==0)
        {
            maxheap.push(num);
            int value = maxheap.top();
            minheap.push(value);
            maxheap.pop();
            
        }
        else
        {
            minheap.push(num);
            int value = minheap.top();
            maxheap.push(value);
            minheap.pop();
            
        }
        
    }

    // Returns the median of current data stream
    double findMedian() {
        if(count%2==0)
            return double(maxheap.top()+minheap.top())/2;
        else
            return maxheap.top();
        
    }
};

// Your MedianFinder object will be instantiated and called as such:
// MedianFinder mf;
// mf.addNum(1);
// mf.findMedian();

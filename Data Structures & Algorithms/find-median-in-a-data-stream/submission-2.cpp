class MedianFinder {
public:
    MedianFinder() {
        
    }
    priority_queue<int,vector<int>,greater<int>> min;
    priority_queue<int> max;
    int size=0;
    void addNum(int num) {
        if(max.empty())
        {
            max.push(num);
            size++;
            return;
        }
        if(num>max.top())
        {
            
            min.push(num);
            cout<<max.size();
            if(min.size()>max.size())
            {
                max.push(min.top());
                min.pop();
            }
        }
        else
        {
            if(min.size()==max.size())
            {
                max.push(num);
                size++;
                return;
            }
            min.push(max.top());
            max.pop();
            max.push(num);
        }
        size++;
    }
    
    double findMedian() {
        if(size%2==0)
        {
            return (double)(min.top()+max.top())/2;
        }
        else
        {
            return max.top();
        }
    }
};

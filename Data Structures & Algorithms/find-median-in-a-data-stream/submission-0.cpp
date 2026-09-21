class MedianFinder {
public:

    priority_queue<int> left; 

    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
    }

    void addNum(int num) {

        // Step 1: Put number into left
        left.push(num);

        // Step 2: Make sure every element in left
        // is <= every element in right
        if (!right.empty() && left.top() > right.top()) {
            right.push(left.top());
            left.pop();
        }

        // Step 3: Balance the sizes
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }

    double findMedian() {

        // Odd number of elements
        if (left.size() > right.size()) {
            return left.top();
        }

        // Even number of elements
        return (left.top() + right.top()) / 2.0;
    }
};
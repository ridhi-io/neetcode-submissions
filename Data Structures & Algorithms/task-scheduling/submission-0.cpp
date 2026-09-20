class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {

        vector<int> freq(26, 0);

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        priority_queue<int> maxHeap;

        for(int f : freq) {
            if(f > 0)
                maxHeap.push(f);
        }

        int time = 0;

        while(!maxHeap.empty()) {

            vector<int> remaining;

            for(int i = 0; i <= n; i++) {

                if(!maxHeap.empty()) {
                    int f = maxHeap.top();
                    maxHeap.pop();

                    f--;

                    if(f > 0)
                        remaining.push_back(f);
                }

                time++;

                if(maxHeap.empty() && remaining.empty())
                    break;
            }

            for(int f : remaining) {
                maxHeap.push(f);
            }
        }

        return time;
    }
};
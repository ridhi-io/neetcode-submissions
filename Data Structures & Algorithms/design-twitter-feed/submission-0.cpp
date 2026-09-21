class Twitter {
public:

    int time = 0;

    // user -> people they follow
    unordered_map<int, unordered_set<int>> following;

    // user -> {tweetId, time}
    unordered_map<int, vector<pair<int, int>>> tweets;

    Twitter() {
    }

    void postTweet(int userId, int tweetId) {
        tweets[userId].push_back({tweetId, time});
        time++;
    }

    vector<int> getNewsFeed(int userId) {

        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>
        > pq;

        // User's own tweets
        following[userId].insert(userId);

        // Add latest tweet from every followed user
        for(int followee : following[userId]) {

            if(tweets[followee].empty())
                continue;

            int index = tweets[followee].size() - 1;

            auto [tweetId, tweetTime] = tweets[followee][index];

            pq.push({tweetTime, followee, index});
        }

        vector<int> result;

        while(!pq.empty() && result.size() < 10) {

            auto [tweetTime, user, index] = pq.top();
            pq.pop();

            result.push_back(tweets[user][index].first);

            // Get previous tweet from same user
            if(index > 0) {

                index--;

                auto [tweetId, newTime] = tweets[user][index];

                pq.push({newTime, user, index});
            }
        }

        return result;
    }

    void follow(int followerId, int followeeId) {
        following[followerId].insert(followeeId);
    }

    void unfollow(int followerId, int followeeId) {
        if(followerId != followeeId) {
            following[followerId].erase(followeeId);
        }
    }
};
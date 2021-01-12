// Represents a tweet

class Tweet {

private:
    
    // Tweet Id
    int tweetId;
    
    // User Id
    int userId;
    
    // Timestamp for the tweet
    int timestamp;
    
public:
    
    Tweet(const int& tweetId, const int& userId, const int& timestamp) : tweetId(tweetId), userId(userId), timestamp(timestamp) {}
    
    int getTweetId() const {
        return tweetId;
    }
    
    int getUserId() const {
        return userId;
    }
    
    int getTimeStamp() const {
        return timestamp;
    }
    
};

// Represents ALL of the tweets in a user's feed

class Feed {
 
private:
    
    // Stores all the tweets in the user's feed 
    unordered_set<Tweet*> feed;
    
public:
    
    // Adding a tweet to the feed (invoked when a followee of the user or the user itself creates a tweet)
    void addTweet(Tweet* tweet) {
        feed.insert(tweet);
    }
    
    // Adding a list of tweets to the feed (invokes when the user follows someone)
    void addTweet(vector<Tweet*>& tweets) {
        for(size_t i = 0; i < tweets.size(); ++i) {
            feed.insert(tweets[i]);
        }
    }
    
    // Deletes a bunch of tweets (invokes when the user unfollows someone)
    void deleteTweet(vector<Tweet*>& tweets) {
        for(size_t i = 0; i < tweets.size(); ++i) {
            feed.erase(tweets[i]);
        }
    }
    
private:
    
    // Custom comparator for the priority queue that we use to retrieve the recent tweets
    class Compare {
    
    public:
        bool operator() (Tweet* T1, Tweet* T2) {
            return T1->getTimeStamp() > T2->getTimeStamp();
        }
    };
    
public: 
    
    // Returns the 10 most recent tweets in the feed
    
    vector<int> getRecent() {
        priority_queue<Tweet*, vector<Tweet*>, Compare> pq;
        for(auto& i : feed) {
            if(pq.size() < 10) {
                pq.push(i);
            } else if( i->getTimeStamp() > pq.top()->getTimeStamp()) {
                pq.pop();
                pq.push(i);
            }
        }
        
        vector<int> recent;
        while(!pq.empty()) {
            recent.push_back(pq.top()->getTweetId());
            pq.pop();
        }
        reverse(recent.begin(), recent.end());
        return recent;
    }
    
};

// Represents a user

class User {

private:
    
    // User Id
    int userId;
    
    // Umap of followers
    unordered_map<int, User*> followers;
    
    // Umap of followees
    unordered_map<int, User*> followees;
    
    // Encapsulates user feed
    Feed feed;
    
    // List of the user's tweets
    vector<Tweet*> myTweets;
    
public:
    
    User(const int& userId) : userId(userId) {}
    
    ~User() {
        for(size_t i = 0; i < myTweets.size(); ++i) {
            delete myTweets[i];
        }
    }
    
    // Returns user Id
    int getId() const {
        return userId;
    }
    
    // Checks if the user follows a user with id -> followeeId
    bool doesFollow(const int& followeeId) {
        return followees.find(followeeId) != followees.end();
    }
    
    // Adds a new follower
    void addFollower(User* follower) {
        followers[follower->getId()] = follower;
    }
    
    // Removes a follower
    void removeFollower(User* follower) {
        followers.erase(follower->getId());
    }
    
    // Adds a followee, updates the feed
    void addFollowee(User* followee) {
        followees[followee->getId()] = followee;
        feed.addTweet(followee->getTweets());
    }
    
    // Removes a followee, updates the feed
    void removeFollowee(User* followee) {
        followees.erase(followee->getId());
        feed.deleteTweet(followee->getTweets());
    }
    
    // Returns all of the user's tweets
    vector<Tweet*>& getTweets() {
        return myTweets;
    }
    
    // Creates a Tweet, updates feed, myTweets, and invokes notifyFollowers()
    void addTweet(const int& tweetId, const int& timestamp) {
        Tweet* tweet = createTweet(tweetId, timestamp);
        feed.addTweet(tweet);
        myTweets.push_back(tweet);
        notifyFollowers(tweet);
    }
    
    // Adds a tweet to the feed (invoked when a followee creates a tweet)
    void addTweet(Tweet* tweet) {
        feed.addTweet(tweet);
    }
    
    // Returns the actual news feed
    vector<int> getNewsFeed() {
        return feed.getRecent();
    }
    
private:
    
    // Updates the feed of all followers when the user creates a new tweet
    void notifyFollowers(Tweet* tweet) {
        for(auto& i : followers) {
            i.second->addTweet(tweet);
        }
    }
    
    // Tweet Factory
    Tweet* createTweet(const int& tweetId, const int& timestamp) {
        return new Tweet(tweetId, userId, timestamp);
    }
    
};


class Twitter {
    
private:
    
    // Timestamp for the tweet
    int timestamp;
    
    // Umap of users
    unordered_map<int, User*> users;
    
public:
    
    /** Initialize your data structure here. */
    Twitter() : timestamp(0) {}
    
    ~Twitter() {
        for(auto& user : users) {
            delete user.second;
        }
    }
    
    /** Compose a new tweet. */
    void postTweet(int userId, int tweetId) {
        if(!userExists(userId)) {
            createUser(userId);
        }
        users[userId]->addTweet(tweetId, timestamp);
        ++timestamp;
    }
    
    /** Retrieve the 10 most recent tweet ids in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user herself. Tweets must be ordered from most recent to least recent. */
    vector<int> getNewsFeed(int userId) {
        if(!userExists(userId)) {
            return {};
        }
        return users[userId]->getNewsFeed();
    }
    
    /** Follower follows a followee. If the operation is invalid, it should be a no-op. */
    void follow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }
        if(!userExists(followerId)) {
            createUser(followerId);
        }
        if(!userExists(followeeId)) {
            createUser(followeeId);
        }
        if(!users[followerId]->doesFollow(followeeId)) {
            users[followerId]->addFollowee(users[followeeId]);
            users[followeeId]->addFollower(users[followerId]);
        }
    }
    
    /** Follower unfollows a followee. If the operation is invalid, it should be a no-op. */
    void unfollow(int followerId, int followeeId) {
        if(followerId == followeeId) {
            return;
        }
        if(!userExists(followerId) || !userExists(followeeId)) {
            return;
        }
        if(users[followerId]->doesFollow(followeeId)) {
            users[followerId]->removeFollowee(users[followeeId]);
            users[followeeId]->removeFollower(users[followerId]);
        }
    }
    
private:
    
    // Checks if the user exists or not
    bool userExists(const int& userId) {
        return users.find(userId) != users.end();
    }
    
    // User Factory
    void createUser(const int& userId) {
        users[userId] = new User(userId);
    }
};

/**
 * Your Twitter object will be instantiated and called as such:
 * Twitter* obj = new Twitter();
 * obj->postTweet(userId,tweetId);
 * vector<int> param_2 = obj->getNewsFeed(userId);
 * obj->follow(followerId,followeeId);
 * obj->unfollow(followerId,followeeId);
 */

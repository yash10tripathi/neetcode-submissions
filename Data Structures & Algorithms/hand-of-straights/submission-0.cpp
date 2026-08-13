class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) 
    {
        int n = hand.size();
        if(n%groupSize) return false;

        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> mp;


        for(auto it:hand)
        {
            mp[it]++;
        }
        for(auto it:mp) pq.push(it.first);

        while(pq.empty()==false)
        {
            int first= pq.top();

            for( int i= first ; i<first+groupSize ; i++)
            {
                if(mp.find(i) ==mp.end()) return false;

                mp[i] -=1;
                if(mp[i]==0)
                {
                    if(i != pq.top()) return false;
                    pq.pop();
                }
                
            }
        }
        return true;
    }
};

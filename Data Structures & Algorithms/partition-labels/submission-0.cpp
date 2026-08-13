class Solution {
public:
    vector<int> partitionLabels(string s) 
    {
        unordered_map<char, int> mp;
        int n=s.size();
        for( int i =0;i<n; i++)
        {
            mp[s[i]]=i;
        }

        int i=0;
        vector<int>ans;

        while(i<n)
        {
            char c = s[i];
            int lo= mp[c];
            int j=i;
            
            while(j<lo and j<n)
            {
                j++;
                if(j==lo) break;
                int ulo= mp[s[j]];
                lo= max(lo, ulo);
            }

            int x = j-i+1;
            i=j+1;
            ans.push_back(x);
        }
        return ans;
    }
};

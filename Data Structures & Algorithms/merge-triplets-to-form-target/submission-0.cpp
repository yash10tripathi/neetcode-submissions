class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool flag1= false;
        bool flag2 = false;
        bool flag3 =false;


        for(auto it:triplets)
        {
            int a = it[0];
            int b = it[1];
            int c = it[2];
            
            if( a== target[0])
            {
                if(b<= target[1] and c<=target[2])
                {
                    flag1 = true;
                }
            }
            if(b==target[1])
            {
                if(a <= target[0] and c<=target[2])
                {
                    flag2 = true;
                }
            }
            if(c==target[2])
            {
                if(a<=target[0] and b<=target[1])
                {
                    flag3= true;
                }
            }
        }
        return (flag1 and flag2 and flag3);
    }
};

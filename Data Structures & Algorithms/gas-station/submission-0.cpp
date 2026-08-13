class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n =gas.size();

        
        vector<int>v;
        for( int i=0;i<n;i++)
        {
            v.push_back(gas[i]-cost[i]);
        }
        for(auto it:v) cout <<it<<" ";
        cout << endl;

        int sum=0;
        int i=0;
        int j=0;
        int index=0;

        while(true){
            if(j==n){
                break;
            }
            sum+=v[j];
            while(sum<0)
            {
                i--;
                if(i==-1)i=n-1;
                if(i==j) return -1;
                sum+=v[i];
                index=i;
            }
            if(sum <0) {
                break;
                return -1;
            }
            j++;
        }  
        
    
        return index;
    }
};

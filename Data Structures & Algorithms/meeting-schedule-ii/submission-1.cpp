/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) 
    {
        int n= intervals.size();
        sort(intervals.begin(), intervals.end() , [](Interval &i1 , Interval &i2){
            return i1.start < i2.start;
        });

        priority_queue<int, vector<int>, greater<int>>pq;

        for( int i=0;i<n;i++)
        {
            int st= intervals[i].start;
            int et = intervals[i].end;

            if(pq.empty() )
            {
                pq.push(et);
            }
            else{
                if(pq.top() <=  st)
                {
                    pq.pop();
                    pq.push(et);
                }
                else pq.push(et);
            }
        }
        return pq.size();
    }
};

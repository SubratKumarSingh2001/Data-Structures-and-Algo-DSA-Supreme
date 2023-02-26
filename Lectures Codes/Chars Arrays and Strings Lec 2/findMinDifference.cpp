class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        //step1: convert time string into minutes integer value
        vector<int> minutes;

        for(int i=0; i<timePoints.size(); i++) {
            string curr = timePoints[i];

            int hours = stoi( curr.substr(0,2) );
            int min = stoi( curr.substr(3,2) );
            int totalMinutes = hours*60 + min;
            minutes.push_back(totalMinutes);
        }

        //Step2: sort
        sort(minutes.begin(), minutes.end());

        //Step3: difference and calculate min diff
        int mini = INT_MAX;
        int n = minutes.size();

        for(int i=0; i<n-1; i++) {
            int diff = minutes[i+1] - minutes[i];
            mini = min(mini, diff);
        }

        //something missing - THIS IS THE GAME
        int lastDiff1 = (minutes[0] + 1440) - minutes[n-1];
        int lastDiff2 = minutes[n-1] - minutes[0];
        int lastDiff = min(lastDiff1, lastDiff2);
        mini = min(mini, lastDiff);

        return mini;

    }
};

















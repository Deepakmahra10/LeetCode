class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int maxCnt = 0;
        int lastfruit = -1, secondlastfruit = -1;
        int currCnt = 0, lastStreak = 0;

        for (int fruit : fruits) {
            if(fruit==lastfruit || fruit==secondlastfruit){
                currCnt++;
            }else{
                currCnt = lastStreak + 1;
            }

            if(fruit == lastfruit){
                lastStreak++;
            }else{
                lastStreak = 1;
                secondlastfruit = lastfruit;
                lastfruit = fruit;
            }
            maxCnt = max(maxCnt, currCnt);
        }
        return maxCnt;
    }
};
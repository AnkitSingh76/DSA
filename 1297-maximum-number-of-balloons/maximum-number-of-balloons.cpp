class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int> fq(26,0);
        for(char& c: text){
            ++fq[c-'a'];
        }

        return min({
            fq[1],
            fq[0],
            fq[11]/2,
            fq[14]/2,
            fq[13]});
    }
};
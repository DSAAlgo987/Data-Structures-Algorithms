// Time Complexity: O(1) bcoz ip size is fixed
class Solution {
public:
    double E = 0.1; // 0.006 koi si bhi le skte hai 
    bool solve(vector<double> &cards){
        // Base case 
        if(cards.size() == 1){
            return abs(cards[0] - 24) <= E;
        }

        // Select two options 
        for(int i = 0; i < cards.size(); i++){
            for(int j = 0; j < cards.size(); j++){
                if(i == j) 
                    continue;

                vector<double> temp;
                // Add remaining elements to temp vector
                for(int k = 0; k < cards.size(); k++){
                    if(k != i && k != j){
                        temp.push_back(cards[k]);
                    }
                }

                double a = cards[i];
                double b = cards[j];

                vector<double> possibleVal = {a+b, a-b, b-a, a*b};

                if(abs(b) > 0.0){
                    possibleVal.push_back(a/b);
                }

                if(abs(a) > 0.0){
                    possibleVal.push_back(b/a);
                }

                for(double val: possibleVal){
                    temp.push_back(val); // Do
                    if(solve(temp) == true){ // Explore
                        return true;
                    }
                    temp.pop_back(); // Undo
                }
            }
        }

        return false;
    }


    bool judgePoint24(vector<int>& cards) {
        // convert int card to double 
        vector<double> nums;

        for(auto c: cards){
            nums.push_back(1.0 * c);
        }

        return solve(nums);
    }
};
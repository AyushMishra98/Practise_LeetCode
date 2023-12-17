class Food {
public:
    int foodRating;
    string foodName;
    Food(int foodRating, string foodName) {
        this->foodRating = foodRating;
        this->foodName = foodName;
    }
    bool operator<(const Food& other) const {
        // If food ratings are same sort on the basis of their name. (lexographically smaller name food will be on top)
        if (foodRating == other.foodRating) {
            return foodName > other.foodName;
        }
        // Sort on the basis of food rating. (bigger rating food will be on top)
        return foodRating < other.foodRating;
    }
};

class FoodRatings {
public:
    unordered_map<string,string> foodCuisine;
    unordered_map<string,int> foodRating;
    unordered_map<string,priority_queue<Food>> pq;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodRating[foods[i]]=ratings[i];
            foodCuisine[foods[i]]=cuisines[i];
            pq[cuisines[i]].push(Food(ratings[i],foods[i]));
        }
    }
    
    void changeRating(string food, int newRating) {
        foodRating[food]=newRating;
        pq[foodCuisine[food]].push(Food(newRating,food));
    }
    
    string highestRated(string cuisine) {
        auto highestRated=pq[cuisine].top();
        while(foodRating[highestRated.foodName] != highestRated.foodRating ){
            pq[cuisine].pop();
            highestRated=pq[cuisine].top();
        }
        return highestRated.foodName;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
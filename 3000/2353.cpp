// 2353. Design a Food Rating System
class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for (int i=0; i<foods.size(); i++) {
            string& food = foods[i];
            string& cuisine = cuisines[i];
            int rating = ratings[i];
            foodRatingMap[food] = rating;
            foodCuisineMap[food] = cuisine;
            cuisineFoodMap[cuisine].insert({-rating, food});
        }        
    }
    
    void changeRating(string food, int newRating) {
        string& cuisine = foodCuisineMap[food];
        int rating = foodRatingMap[food];
        auto it = cuisineFoodMap[cuisine].find({-rating, food});
        cuisineFoodMap[cuisine].erase(it);

        foodRatingMap[food] = newRating;
        cuisineFoodMap[cuisine].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        return cuisineFoodMap[cuisine].begin()->second;
    }

private:
    unordered_map<string, int> foodRatingMap;
    unordered_map<string, string> foodCuisineMap;
    unordered_map<string, set<pair<int, string>>> cuisineFoodMap;
};

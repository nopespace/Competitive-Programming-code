#include <bits/stdc++.h> 
using namespace std;

class FoodRatings {
public:
    map<string, string> foodcuisine;
    map<string, int> foodrate;
    map<string, set<pair<int,string> > > cuisinefood;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        for(int i=0;i<foods.size();i++){
            foodcuisine[foods[i]] = cuisines[i];
            foodrate[foods[i]] = ratings[i];
            cuisinefood[cuisines[i]].insert({-ratings[i], foods[i]});
        }
    } 
    void changeRating(string food, int newRating) {
        cuisinefood[foodcuisine[food]].erase({-foodrate[food], food});
        foodrate[food] = newRating;
        cuisinefood[foodcuisine[food]].insert({-newRating, food});
    }
    
    string highestRated(string cuisine) {
        auto it = cuisinefood[cuisine].begin();
        return it->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
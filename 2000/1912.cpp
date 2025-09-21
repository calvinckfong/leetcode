// 1912. Design Movie Rental System
class MovieRentingSystem {
public:
    MovieRentingSystem(int n, vector<vector<int>>& entries) {
        for (auto& e: entries) {
            shopList[make_key(e[0], e[1])] = e[2];
            movieList[e[1]].insert({e[2], e[0]});
        }
    }
    
    vector<int> search(int movie) {
        vector<int> res;
        auto& movieSet = movieList[movie];
        int i=0;
        for (auto it=movieSet.begin(); it!=movieSet.end() && i<5; it++, i++) {
            res.push_back(it->second);
        }
        return res;
    }
    
    void rent(int shop, int movie) {
        int price = shopList[make_key(shop, movie)];
        movieList[movie].erase({price, shop});
        rented.insert({price, shop, movie});
    }
    
    void drop(int shop, int movie) {
        int price = shopList[make_key(shop, movie)];
        movieList[movie].insert({price, shop});
        rented.erase({price, shop, movie});
    }
    
    vector<vector<int>> report() {
        vector<vector<int>> res;
        int i=0;
        for (auto it=rented.begin(); it!=rented.end() && i<5; it++, i++) {
            auto& [price, shop, movie] = *it;
            res.push_back({shop, movie});
        }
        return res;
    }

private:
    unordered_map<uint64_t, int> shopList;
    unordered_map<int, set<pair<int,int>>> movieList;
    set<tuple<int, int, int>> rented;

    uint64_t make_key(int shop, int movie) {
        return (uint64_t)shop << 32 | movie;
    }
};

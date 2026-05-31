// 2126. Destroying Asteroids
class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        int max_asteroid = asteroids[asteroids.size()-1];

        for (auto& x: asteroids) {
            if (mass < x) return false;
            mass += x;
            if (mass >= max_asteroid) break;
        }

        return true;
    }
};

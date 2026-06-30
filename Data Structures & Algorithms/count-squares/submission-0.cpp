#include <vector>
#include <unordered_map>
#include <cmath>
using namespace std;

struct hash_pair {
    size_t operator()(const pair<int,int>& p) const {
        return hash<int>()(p.first) ^ (hash<int>()(p.second) << 1);
    }
};

class CountSquares {
public:
    vector<pair<int,int>> points;
    unordered_map<pair<int,int>, int, hash_pair> mp;

    CountSquares() {
        points.clear();
    }

    void add(vector<int> point) {
        pair<int,int> p = {point[0], point[1]};

        if(mp.find(p) == mp.end())
            points.push_back(p);

        mp[p]++;
    }

    int count(vector<int> point) {
        int x_coordinate = point[0];
        int y_coordinate = point[1];

        int counter = 0;

        for(int i = 0; i < points.size(); i++) {

            int x2 = points[i].first;
            int y2 = points[i].second;

            // Cannot be in the same row or column
            if(x2 == x_coordinate || y2 == y_coordinate)
                continue;

            // Must be a square
            if(abs(x2 - x_coordinate) != abs(y2 - y_coordinate))
                continue;

            pair<int,int> p1 = {x_coordinate, y2};
            pair<int,int> p2 = {x2, y_coordinate};

            if(mp.find(p1) == mp.end())
                continue;

            if(mp.find(p2) == mp.end())
                continue;

            counter += mp[p1] * mp[p2] * mp[{x2, y2}];
        }

        return counter;
    }
};
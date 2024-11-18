#ifndef CACHE_SIMULATOR_HPP
#define CACHE_SIMULATOR_HPP

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Cache_simulator {
private:
  int hit = 0;
  int miss = 0;

  vector<char*> missout_cache;
  vector<char*> least_occurred;
  vector<char*> modified;
  vector<char*> last_cache;

public:
  void stats(const vector<char*>& parent, const vector<char*>& cache) {
    modified = parent;
    last_cache = cache;
    hit = 0;
    missout_cache.clear();

    for (char* cache_item : cache) {
      bool found = false;
      for (char* parent_item : parent) {
        if (cache_item == parent_item) {
          found = true;
          hit++;
          break;
        }
      }
      if (!found) {
        missout_cache.push_back(cache_item);
      }
    }

    miss = cache.size() - hit;
  }

  void update(const vector<char*>& parent, const vector<char*>& cache) {
    least_occurred.clear();

    for (char* parent_item : parent) {
      bool found = false;
      for (char* cache_item : cache) {
        if (parent_item == cache_item) {
          found = true;
          break;
        }
      }
      if (!found) {
        least_occurred.push_back(parent_item);
      }
    }

    for (char* item : least_occurred) {
      auto it = find(modified.begin(), modified.end(), item);
      if (it != modified.end()) {
        modified.erase(it);
      }
    }

    modified.insert(modified.end(), missout_cache.begin(), missout_cache.end());
  }

  void print_missout_cache() const {
    for (char* item : missout_cache) {
      cout << static_cast<void*>(item) << endl;
    }
  }

  void print_modified_cache() const {
    for (char* item : modified) {
      cout << static_cast<void*>(item) << endl;
    }
  }

  void print_least_occured() const {
    for (char* item : least_occurred) {
      cout << static_cast<void*>(item) << endl;
    }
  }

  void get_stats(const vector<char*>& cache) {
    float hit_percentage = (hit / (float)cache.size()) * 100;
    float miss_percentage = (miss / (float)cache.size()) * 100;
    cout << "HIT STATS: ---> " << hit_percentage << "%" << endl;
    cout << "MISS STATS: ---> " << miss_percentage << "%" << endl;
  }
};

#endif

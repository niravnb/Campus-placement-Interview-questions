// Fruit Statistics
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

struct Fruit {
  int minPrice;
  int maxPrice;
  int totalPrice;
  int count;
  
  Fruit() {}
  
  Fruit(int price) {
    this->minPrice = price;
    this->maxPrice = price;
    this->totalPrice = price;
    this->count = 1;
  }
  
  void addPrice(int price) {
    this->minPrice = min(this->minPrice, price);
    this->maxPrice = max(this->maxPrice, price);
    this->totalPrice += price;
    this->count++;
  }
  
  int getMinPrice() {
    return this->minPrice;
  }
  
  int getMaxPrice() {
    return this->maxPrice;
  }
  
  int getAveragePrice() {
    return this->totalPrice / this->count;
  }
};

void calculatePrices(vector<pair<string, int> > fruits) {
  map<string, Fruit> fruitMap;
  for (int i = 0; i < fruits.size(); i++) {
    if (fruitMap.find(fruits[i].first) != fruitMap.end()) {
      fruitMap[fruits[i].first].addPrice(fruits[i].second);
    } else {
      fruitMap[fruits[i].first] = Fruit(fruits[i].second);
    }
  }
  
  for (auto it : fruitMap) {
    cout << it.first << " " << it.second.getMinPrice() << " " << it.second.getMaxPrice() << " " << it.second.getAveragePrice() << endl;
  }
}

int main() {
  vector<pair<string, int> > fruits;
  fruits.push_back(make_pair("grapefruit", 120));
  fruits.push_back(make_pair("grape", 200));
  fruits.push_back(make_pair("grapefruit", 150));
  fruits.push_back(make_pair("grapefruit", 150));
  fruits.push_back(make_pair("grape", 180));
  calculatePrices(fruits);
	return 0;
}

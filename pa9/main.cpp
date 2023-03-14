#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

// compare averages
bool average_sort(double a, double b) { return a < b; }

void print(string x) { cout << x << " "; }

int main() {
  // part 1
  vector<string> products{"Iphone14", "Ipad Pro", "Headphones", "Back roller",
                          "Bike"};

  // store prices of each item from different stores
  map<string, vector<double>> data;
  data["Ebay"] = {800.00, 999.99, 950.00, 920.00, 980.00};
  data["Amazon"] = {1499, 1459, 1545.99, 1500.00, 20.00};
  data["BestBuy"] = {249.00, 549.98, 348.00, 279.00, 456.99};
  data["OfficeMax"] = {59.99, 69.99, 99.99, 109.99, 78.98};
  data["Staples"] = {900.98, 589.00, 238.98, 799.00, 350.00};
  // print data
  cout << setw(8) << "Name:";
  for (auto d : data) {
    cout << setw(10) << d.first << ":";
  }
  cout << "\n";
  for (int i = 0; i < 5; i++) {
    cout << setw(10) << products[i] << ":";
    for (auto d : data) {
      cout << setw(10) << d.second[i];
    }
    cout << "\n";
  }
  cout << endl;

  // different format
  for (auto d : data) {
    cout << "Store: " << d.first << "\n";
    for (int i = 0; i < 5; i++) {
      cout << setw(10) << products[i] << " " << d.second[i] << "\n";
    }
    cout << endl;
  }

  // // part 2 get the average
  vector<double> averages = {0.0, 0.0, 0.0, 0.0, 0.0};
  vector<pair<string, int>> avg_products;
  // define avg
  int avg = 0;
  int count = 5;
  cout << "Averages: \n";
  for (int i = 0; i < count; i++) {
    for (auto d : data) {
      avg += d.second[i];
    }
    // get the average by diving by count
    avg /= count;
    averages[i] = avg;
    pair<string, double> i_pair;
    i_pair.first = products[i];
    i_pair.second = avg;
    avg_products.push_back(i_pair);
  }

  // sort in ascending
  sort(averages.begin(), averages.end(), average_sort);

  for (int i = 0; i < 5; i++) {
    string found;
    for (auto a : avg_products) {
      if (a.second == averages[i]) {
        found = a.first;
        break;
      }
    }
    cout << found << ", Averages:" << averages[i] << "\n";
  }
  cout << endl;

  // Part 3 find the best price
  vector<string> best_price;
  for (int i = 0; i < 5; i++) {
    vector<double> prods;
    vector<string> names;
    for_each(names.begin(), names.end(), print);
    for (auto d : data) {
      // prods and names
      names.push_back(d.first);
      prods.push_back(d.second[i]);
    }
    // get the min value to find best price
    auto min = min_element(prods.begin(), prods.end());
    // iterator
    int iter = 0;
    for (int j = 0; j < 5; j++) {
      if (prods[j] == min[0]) {
        iter = j;
        break;
      }
    }
    string store_name = names[iter];

    cout << products[i] << ", Best Price Offered by: " << store_name << "\n";
  }

} // end of main

#include <bits/stdc++.h>
using namespace std;

struct Item {
    int value, weight;
    double ratio() const { return (double)value / weight; }
};

class Solution {
public:
    double fractionalKnapsack(int W, vector<Item>& items) {
        sort(items.begin(), items.end(), [](const Item& a, const Item& b) {
            return a.ratio() > b.ratio();
        });

        double totalValue = 0.0;  // Keeps track of the total value of items selected

        for (const auto& item : items) {
            if (item.weight <= W) {
                // If the item can fit completely into the knapsack
                W -= item.weight;  // Subtract the item's weight from the remaining capacity
                totalValue += item.value;  // Add the item's value to the total value
            } else {
                // If the item can't fit completely, take the fraction of it
                double fraction = (double)W / item.weight;  // Fraction of the item we can take
                totalValue += item.value * fraction;  // Add the fractional value to the total value
                break;  // No more space in the knapsack, so we stop
            }
        }

        return totalValue;  // Return the total value of items taken
    }
};

int main() {
    int n = 3, W = 50;
    vector<Item> items = { {100, 20}, {60, 10}, {120, 30} };
    
    Solution sol;
    double maxValue = sol.fractionalKnapsack(W, items);
    cout << "The maximum value is " << fixed << setprecision(2) << maxValue << endl;

    return 0;
}

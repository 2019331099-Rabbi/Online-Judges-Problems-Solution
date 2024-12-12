#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

using namespace std;

// Function to calculate gcd of two numbers
int calculateGCD(int a, int b) {
    if (b == 0) return a;
    return calculateGCD(b, a % b);
}

// Function to maximize the result
int maximizeResult(vector<pair<int, int>>& pairs) {
    // Sort pairs in descending order based on the maximum of the two numbers
    sort(pairs.begin(), pairs.end(), [](const auto& a, const auto& b) {
        return max(a.first, a.second) > max(b.first, b.second);
    });

    // Initialize Red and Blue bags
    vector<int> redBag, blueBag;

    for (const auto& pair : pairs) {
        // Add the larger number to one bag and the smaller number to the other bag
        if (accumulate(redBag.begin(), redBag.end(), 0) <= accumulate(blueBag.begin(), blueBag.end(), 0)) {
            redBag.push_back(pair.first);
            blueBag.push_back(pair.second);
        } else {
            redBag.push_back(pair.second);
            blueBag.push_back(pair.first);
        }
    }

    // Calculate gcd of numbers in each bag
    int g1 = accumulate(redBag.begin(), redBag.end(), redBag[0], calculateGCD);
    int g2 = accumulate(blueBag.begin(), blueBag.end(), blueBag[0], calculateGCD);

    // Calculate the maximum result
    int result = g1 * g2;

    return result;
}

int main() {
    // Example usage
    vector<pair<int, int>> pairs = {{1, 2}, {3, 4}, {5, 6}};
    int maxResult = maximizeResult(pairs);

    cout << "Maximized Result: " << maxResult << endl;

    return 0;
}

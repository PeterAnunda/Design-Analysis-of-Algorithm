#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void countingSortForRadix(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n); // Output array
    int count[10] = {0};   // Count array for digits (0-9)

    // Count occurrences of digits in the current place value
    for (int i = 0; i < n; i++) {
        int index = (arr[i] / exp) % 10;
        count[index]++;
    }

    // Cumulative count to determine positions
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = n - 1; i >= 0; i--) {
        int index = (arr[i] / exp) % 10;
        output[count[index] - 1] = arr[i];
        count[index]--;
    }

    // Copy the sorted output array back to arr
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

vector<int> radixSort(vector<int>& arr) {
    int max_num = *max_element(arr.begin(), arr.end());
    for (int exp = 1; max_num / exp > 0; exp *= 10) {
        countingSortForRadix(arr, exp);
    }
    return arr;
}

// Example usage
int main() {
    vector<int> product_ids = {329, 457, 657, 839, 436, 720, 355};
    vector<int> sorted_product_ids = radixSort(product_ids);
    for (int id : sorted_product_ids) {
        cout << id << " ";
    }
    cout << endl;
    return 0;
}

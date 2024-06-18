#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    vector<int> BubbleSort(vector<int> &arr) {
        int n = arr.size();
        for (int i = 0; i < n - 1; i++) {
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    swap(arr[j], arr[j + 1]);
                }
            }
        }
        return arr;
    }
    
    int SUM_Value(vector<int> &ar) {
        int sum = 0;
        for (int i = 0; i < ar.size(); i++) {
            sum += ar[i];
        }
        return sum;
    }

public:
    int MEAN(vector<int> &ar) {
        int sum = SUM_Value(ar);
        return sum / ar.size();
    }
    int MEDIAN(vector<int>& ar) {
        ar = BubbleSort(ar);
        int n = ar.size();
        if (n % 2 == 0) {
            return (ar[n / 2] + ar[n / 2 - 1]) / 2;
        }
        return ar[n / 2];
    }
    int MODE(vector<int> &ar) {
        int n = ar.size();
        int mode = ar[0];
        int maxCount = 1;
        for (int i = 0; i < n; i++) {
            int count = 0;
            for (int j = 0; j < n; j++) {
                if (ar[j] == ar[i]) {
                    count++;
                }
            }
            if (count > maxCount) {
                maxCount = count;
                mode = ar[i];
            }
        }
        cout << "Mode: " << mode << " with frequency: " << maxCount << "\n";
        return 0;
    }
    int RANGE(vector<int> &ar) {
        ar = BubbleSort(ar);
        int range = (ar[ar.size()-1] - ar[0]);
        cout << "Range: " << range;
        return 0;
    }
};

int main() {
    int myArray[5] = {12, 17, 22, 15, 19};
    vector<int> myVector(myArray, myArray + sizeof(myArray) / sizeof(myArray[0]));
    Solution s;
    cout << "Mean: " << s.MEAN(myVector) << endl;
    cout << "Median: " << s.MEDIAN(myVector) << endl;
    cout << "Mode: " << s.MODE(myVector) << endl;
    cout << "Range: " << s.RANGE(myVector) << endl;
    
    return 0;
}

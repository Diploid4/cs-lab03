#include "histogram.h"
#include <vector>
#include <algorithm>
using namespace std;

void find_minmax(vector<double> numbers, double& min, double& max) {
    if (not numbers.size())
        return;
    min = *min_element(numbers.begin(), numbers.end());
    max = *max_element(numbers.begin(), numbers.end());
}
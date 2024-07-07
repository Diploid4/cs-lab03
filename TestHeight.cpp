#include "HeightCalculation.h"
#include <cassert>


void test_equal() {
	int max = 100;
	int indent = 10;
	int bin_height = 10;
	auto res = height_calc(max, indent, bin_height);
	assert(res == 1010);
}

void test_empty() {
	int max = 0;
	int indent = 20;
	int bin_height = 10;
	auto res = height_calc(max, indent, bin_height);
	assert(res == 0);
}

int main() {
	test_equal();
	test_empty();
}
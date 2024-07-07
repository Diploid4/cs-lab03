#pragma once
#include <vector>
#include <algorithm>


int height_calc(size_t max, size_t indent, size_t bin_height) {
	return max * bin_height + indent;
}
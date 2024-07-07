#pragma once
#include <vector>
#include <algorithm>
#include "HeightCalculation.h"

void svg_text(double left, double baseline, string text) {
    cout << "<text x='" << left << "' y='" << baseline << "'>" << text << "</text>" << '\n';
}
void svg_rect(double x, double y, double width, double height, string stroke = "red", string fill = "black") {
    cout << "<rect x='" << x << "' y='" << y << "' width='" << width << "' height='" << height << "' stroke='" << stroke << "' fill='" << fill << "' />" << '\n';
}

void svg_begin(double width, double height) {
    cout << "<?xml version='1.0' encoding='UTF-8'?>\n";
    cout << "<svg ";
    cout << "width='" << width << "' ";
    cout << "height='" << height << "' ";
    cout << "viewBox='0 0 " << width << " " << height << "' ";
    cout << "xmlns='http://www.w3.org/2000/svg'>\n";
}
void svg_end() {
    cout << "</svg>\n";
}

void show_histogram_svg(const vector<size_t>& bins) {
    const auto IMAGE_WIDTH = 400;
    const auto TEXT_LEFT = 20;
    const auto TEXT_BASELINE = 20;
    const auto TEXT_WIDTH = 50;
    const auto BIN_INDENT = 10;
    const auto BIN_WIDTH = 30;
    const auto BLOCK_HEIGHT = 10;
    auto max = *max_element(bins.begin(), bins.end());
    const auto IMAGE_HEIGHT = height_calc(max, BIN_INDENT, BLOCK_HEIGHT);
    svg_begin(IMAGE_WIDTH, IMAGE_HEIGHT);
    
    double top = 0;
    for (size_t bin : bins) {
        const double bin_height = BLOCK_HEIGHT * bin;
        svg_text(TEXT_LEFT + top, TEXT_BASELINE, to_string(bin));
        svg_rect(BIN_INDENT + top, TEXT_BASELINE + BIN_INDENT, BIN_WIDTH, bin_height);
        top += BIN_WIDTH;
    }
    svg_end();
}
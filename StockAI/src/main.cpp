#include <iostream>     // cout, endl
#include <fstream>      // fstream
#include <vector>
#include <string>
#include <algorithm>    // copy
#include <iterator>     // ostream_operator
#include <unordered_map>
#include <boost/tokenizer.hpp>
#include "../include/data_handler.hpp"

//test if list output is good
void testUnorderedList() {
	std::unordered_map<int, double> data({
		{1, 10}, {2, 20}, {3, 30},
		{4, 40}, {5, 50}, {6, 60},
		{7, 70}, {8, 80}, {9, 90}
	});

	data.insert({ 11, 110 }); data.insert({ 12, 120 }); data.insert({ 13, 130 });
	data.insert({ 14, 140 }); data.insert({ 15, 150 }); data.insert({ 17, 170 });
	data.insert({ 18, 180 }); data.insert({ 19, 190 }); data.insert({ 20, 200 });

	for (auto val : data) {
		std::cout << val.first << ", " << val.second << std::endl;
	}
}

//test if list output is good
void testParsing() {
	data::data_handler dh;
	using namespace std::filesystem;
	path p = current_path();
	dh.read_moves_vector(p.string() + "\\AAPL.csv");

	for (size_t i = 0; i < dh.header.size(); ++i) {
		std::cout << dh.header[i];
		if ((i+1) % 6 == 0 && i > 0)std::cout << std::endl;
		else std::cout << ", ";
	}
}

int main(){
	//testUnorderedList(); //passed
	//testParsing(); //passed
}
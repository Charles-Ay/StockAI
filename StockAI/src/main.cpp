#include <iostream>     // cout, endl
#include <fstream>      // fstream
#include <vector>
#include <string>
#include <algorithm>    // copy
#include <iterator>     // ostream_operator
#include <unordered_map>
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

namespace date_test {
	void date_to_number_test() {
		date d(2021, 12, 16);
		year_t y = date_to_number(d);//passed
		std::cout << y << std::endl;

		y = date_to_number(2021, 12, 16);//passed
		std::cout << y << std::endl;
	}

	void number_to_date_test() {
		year_t y = 20211216;
		date d = number_to_date(y);
		std::cout << d << std::endl;
	}
}

namespace data_test {
	void data_3_arg_test() {
		data::data_handler dh;
		using namespace std::filesystem;
		path p = current_path();
		dh.read_moves(p.string() + "\\AAPL.csv");

		data::data da("Apple", "AAPL", dh.header);

		for (size_t i = 0; i < data::moves.size(); ++i) {
			std::cout << data::moves.at(i) << std::endl;
		}
	}

	namespace data_handling_test {
		void testParsing() {
			data::data_handler dh;
			using namespace std::filesystem;
			path p = current_path();
			dh.read_moves(p.string() + "\\AAPL.csv");

			for (size_t i = 0; i < dh.header.size(); ++i) {
				std::cout << dh.header[i];
				if ((i + 1) % 6 == 0 && i > 0)std::cout << std::endl;
				else std::cout << ", ";
			}
		}

		void tempout() {
			data::data_handler dh;
			using namespace std::filesystem;
			path p = current_path();
			dh.read_moves(p.string() + "\\AAPL.csv");

			int cnt = 1;
			int cn2 = 1;
			for (size_t i = 6; i < dh.header.size(); ++i) {
				if (cn2 == 3) {
					//if(cnt % 3 == 0 && cnt != 0)
					//	std::cout << "[" << cnt <<", " << dh.header[i] << "], " << std::endl;
					//else std::cout << "[" << cnt << ", " << dh.header[i] << "], ";
					if (cnt % 3 == 0 && cnt != 0)
						std::cout << dh.header[i] << ", " << std::endl;
					else std::cout << dh.header[i] << ", ";
					++cnt;
					cn2 = 0;
				}
				if (i % 6 == 0)cn2 = -1;
				++cn2;
			}
		}
	}
}

namespace regtest{
	void regtest_main() {
		data::data_handler dh;
		using namespace std::filesystem;
		path p = current_path();
		dh.read_moves(p.string() + "\\AAPL.csv");

		dh.reparse_header(dh);
	}
}




//test if list output is good

int main(){
	//testUnorderedList(); //passed
	//data_test::data_handling_test::testParsing(); //passed
	//data_test::data_3_arg_test(); //passed
	//date_test::date_to_number_test(); //passed
	//date_test::number_to_date_test();
	//data_test::data_handling_test::tempout();
	regtest::regtest_main();
}
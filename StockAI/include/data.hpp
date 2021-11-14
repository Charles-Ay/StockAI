#pragma once

#include<string>
#include<vector>
#include<iostream>
#include "util.hpp"
#include "convert_date.hpp"

namespace data {
	using namespace util;
	class data {
		//date info
		date d;

		//stock info
		std::string name;
		std::string ticker;
		
		//value info
		money_t open;
		money_t close;
		money_t high;
		money_t low;
		volume_t volume;

		//store moves each day(open, close, high, low, volume)
		std::vector<data>* moves;
		
	public:
		data();
		~data();

		/// <summary>
		/// add to moves vector
		/// </summary>
		/// <param name="">move to add</param>
		constexpr void add_moves(data*);
		/// <summary>
		/// get a day move
		/// </summary>
		/// <param name="">day index</param>
		/// <returns></returns>
		constexpr data* get_move(date);
	};
}
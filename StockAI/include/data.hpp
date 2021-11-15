#pragma once

#include<string>
#include<vector>
#include<iostream>
#include "util.hpp"
#include "date.hpp"

namespace data {
	class data {
		//date info
		date trade_date;

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
		/// <summary>
		/// initialize data
		/// </summary>
		/// <param name="name"></param>
		/// <param name="ticker"></param>
		/// <param name="open"></param>
		/// <param name="close"></param>
		/// <param name="high"></param>
		/// <param name="low"></param>
		/// <param name="volume"></param>
		data(std::string, std::string, money_t, money_t, money_t, money_t, volume_t);
		~data();

		data(data* d);

		/// <summary>
		/// add to moves vector
		/// </summary>
		/// <param name="">move to add</param>
		void add_move(data*);
		/// <summary>
		/// get a day move
		/// </summary>
		/// <param name="">day index</param>
		/// <returns></returns>
		data get_move(date);

		/// <summary>
		/// get the amount of trade days in the vector
		/// </summary>
		/// <returns>size of moves vector</returns>
		constexpr size_t moves_vector_size();
	};
}
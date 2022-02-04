#pragma once

#include<string>
#include<vector>
#include<iostream>
#include "util.hpp"
#include "date.hpp"
#include <ostream>
#include <ostream>
#include <ostream>

namespace data {
	class data {
		//date info
		date trade_date;

		//stock info
		std::string name = "*uninitalized*";
		std::string ticker = "*uninitalized*";

		//value info
		money_t open = 0.0;
		money_t close = 0.0;
		money_t high = 0.0;
		money_t low = 0.0;
		volume_t volume = 0;
		
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
		data(std::string, std::string, date, money_t, money_t, money_t, money_t, volume_t);
		~data();

		/// <summary>
		/// initialize data
		/// </summary>
		/// <param name="name">stock name</param>
		/// <param name="tick">stock ticker</param>
		/// <param name="v">vector to convert to data</param>
		data(const std::string& name, const std::string& tick, const std::vector<std::string>& v);

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
		data get_move_on_date(date);

		/// <summary>
		/// get the amount of trade days in the vector
		/// </summary>
		/// <returns>size of moves vector</returns>
		constexpr size_t moves_vector_size();
		
		/// <summary>
		/// osteam overload
		/// </summary>
		friend std::ostream& operator<<(std::ostream& os, const data & d);

		constexpr money_t get_price_at_close() { return close; }
		constexpr money_t get_price_at_open() { return open; }
		inline date get_date() { return trade_date; }
		constexpr volume_t get_volume() { return volume; }
		constexpr std::string get_name() { return name; }
	};
	void reset_moves();

	//store moves each day(open, close, high, low, volume)
	inline std::vector<data> moves;
}
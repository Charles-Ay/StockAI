#include "../include/data.hpp"

data::data::data(std::string name, std::string ticker, date da, money_t open, money_t close, 
	money_t high, money_t low, volume_t volume)
{
	this->name = name;
	this->ticker = ticker;
	this->trade_date = da;
	this->open = open;
	this->high = high;
	this->low = low;
	this->close = close;
	this->volume = volume;
}

data::data::data(const std::string &name, const std::string &tick, const std::vector<std::string> &v)
{
	//exclude headers
	for (size_t i = 6; i < v.size(); i+= 6) {
		date date_n(extract_date_from_string(v[i])); money_t open = string_to_money(v[i + 1]);
		money_t high = string_to_money(v[i + 2]); money_t low= string_to_money(v[i + 3]);
		money_t close = string_to_money(v[i + 4]); volume_t volume = string_to_volume(v[i + 5]);

		this->name = name;
		this->ticker = tick;
		this->trade_date = date_n;
		this->open = open;
		this->high = high;
		this->low = low;
		this->close = close;
		this->volume = volume;
		moves.push_back(this);
		//intlize values using another constructor
		//data d(name, tick, date_n, open, high, low, close, volume);
		//moves->push_back(data(name, tick, date_n, open, high, low, close, volume));
	}
}

data::data::data(data* d) {
	trade_date = d->trade_date;
	name = d->name;
	ticker = d->ticker;
	open = d->open;
	high = d->high;
	low = d->low;
	close = d->close;
	volume = d->volume;
}


data::data::~data(){

}

void data::data::add_move(data* d) { moves.push_back(d); }

data::data data::data::get_move_on_date(date d) {
	//O(n)
	for (unsigned i = 0; i < moves.size(); ++i) {
		if (moves.at(i).trade_date == d)return moves.at(i);
	}
	return nullptr;
}

constexpr size_t data::data::moves_vector_size() { return moves.size(); }

namespace data {
	std::ostream& operator<<(std::ostream& os, const data& d)
	{
		os << d.trade_date << ", " << d.ticker << ", " << d.open << ", " << d.high
			<< ", " << d.low << ", " << d.close << ", " << d.volume;
		return os;
	}
	void reset_moves() { moves.clear(); }
}
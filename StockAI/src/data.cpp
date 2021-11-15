#include "../include/data.hpp"
#include<string>

data::data::data(std::string name, std::string ticker, money_t open, money_t close, 
	money_t high, money_t low, volume_t volume)
{
	moves = new std::vector<data>;
	this->name = name;
	this->ticker = ticker;
	this->open = open;
	this->close = close;
	this->high = high;
	this->low = low;
	this->volume = volume;
}

data::data::data(data* d) {
	trade_date = d->trade_date;
	name = d->name;
	ticker = d->ticker;
	open = d->open;
	close = d->close;
	high = d->high;
	low = d->low;
	volume = d->volume;
	moves = d->moves;
}

data::data::~data(){

}

void data::data::add_move(data* d) { moves->push_back(d); }

data::data data::data::get_move(date d) {
	//O(n)
	for (unsigned i = 0; i < moves->size(); ++i) {
		if (moves->at(i).trade_date == d)return moves->at(i);
	}
}

constexpr size_t data::data::moves_vector_size() { return moves->size(); }
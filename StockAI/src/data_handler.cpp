#include "../include/data_handler.hpp"

data::data_handler::data_handler() {
	data_array = new std::vector<data*>;
	test_data = new std::vector<data*>;
	training_data = new std::vector<data*>;
	validation_data = new std::vector<data*>;
}

//Free data dynimically allocated
data::data_handler::~data_handler() {
}


void data::data_handler::read_moves(std::string path) {
	using namespace boost;

	std::ifstream in(path.c_str());//get file path
	if (in.is_open()) {
		typedef tokenizer< escaped_list_separator<char> > Tokenizer;//token seperator ','
		std::vector<std::string> vec;//read vector
		std::vector<std::string> vec2;//store vector

		std::string line;//current line

		bool lab = true;
		while (getline(in, line))//read each line
		{
			Tokenizer tok(line);//seperate by line
			vec.assign(tok.begin(), tok.end());//assign seprated line to a vector

			//get headers
			if (lab) {
				header.push_back(vec[0]);
				header.push_back(vec[1]);
				header.push_back(vec[2]);
				header.push_back(vec[3]);
				header.push_back(vec[4]);
				header.push_back(vec[5]);
				lab = false;
			}
			else {
				//date
				year_t year = 0;
				month_t month = 0;
				day_t day = 0;
				std::string tmp = "";

				bool y = true;
				bool m = true;
				bool d = true;

				//seprate slash in string
				std::string x = header[0];
				//get date
				while (string_contains(x, "-")) {
					if (year == 0 && x[0] != '-') {
						tmp += std::string(1, x[0]);
						x = x.replace(0, 1, "");
					}
					else if (month == 0 && x[0] != '-') {
						tmp += std::string(1, x[0]);
						x = x.replace(0, 1, "");
					}
					else if (day == 0 && x[0] != '-') {
						tmp += std::string(1, x[0]);
						x = x.replace(0, 1, "");
					}
					else {
						if (y) {
							year = std::stoi(tmp);
							tmp = "";
							y = false;
						}
						else if (m) {
							month = std::stoi(tmp);
							tmp = "";
							m = false;
						}
						else if (d) {
							day = std::stoi(tmp);
							tmp = "";
							d = false;
						}
					}
				}

				copy(vec.begin(), vec.end(), std::back_inserter(vec2));//copy line to main vector
				header.insert(header.end(), vec.begin(), vec.end());
			}
		}
		//std::reverse(header.begin(), header.end());
	}

	
}
void data::data_handler::split_data() {
	//keep track of indexes used and fill other arrays without emptying data array
	std::unordered_set<int> used_indexes;
	int train_size = int(data_array->size() * TRAIN_SET_PERCENT);//cast for loss warning
	int test_size = int(data_array->size() * TEST_SET_PERCENT);
	int valid_size = int(data_array->size() * VALIDATION_SET_PERCENT);

	//Training Data
	int count = 0;
	while (count <train_size)
	{
		int rand_index = rand() % data_array->size();//rand bettween 0 - data_array->size()-1
		//if iterator is at the end value was not found meaning we can use it
		if (used_indexes.find(rand_index) == used_indexes.end()) {
			training_data->push_back(data_array->at(rand_index));
			used_indexes.insert(rand_index);
			++count;
		}
	}

	//Test Data
	count = 0;
	while (count < test_size)
	{
		int rand_index = rand() % data_array->size();//rand bettween 0 - data_array->size()-1
		//if iterator is at the end value was not found meaning we can use it
		if (used_indexes.find(rand_index) == used_indexes.end()) {
			test_data->push_back(data_array->at(rand_index));
			used_indexes.insert(rand_index);
			++count;
		}
	}
	//Valid Data
	count = 0;
	while (count < valid_size)
	{
		int rand_index = rand() % data_array->size();//rand bettween 0 - data_array->size()-1
		//if iterator is at the end value was not found meaning we can use it
		if (used_indexes.find(rand_index) == used_indexes.end()) {
			validation_data->push_back(data_array->at(rand_index));
			used_indexes.insert(rand_index);
			++count;
		}
	}
	std::cout << "Training Data Size: " << training_data->size() << std::endl;
	std::cout << "Test Data Size: " << training_data->size() << std::endl;
	std::cout << "Validation Data Size: " << training_data->size() << std::endl;
}

//might be implemented in the future
//std::vector<data*>* data::data_handler::get_all_data()
//{
//	return nullptr;
//}

std::unordered_map<money_t, year_t> data::data_handler::vector_parse() {
	std::unordered_map<money_t, year_t> m;
	for (auto val : moves) {
		date d = val.get_date();
		m.insert({ val.get_price_at_close(), date_to_number(d) });
	}
	return m;
}


std::vector<data::data*>* data::data_handler::get_training_data() {
	return training_data;
}
std::vector<data::data*>* data::data_handler::get_test_data() {
	return test_data;
}
std::vector<data::data*>* data::data_handler::get_validation_data() {
	return validation_data;
}



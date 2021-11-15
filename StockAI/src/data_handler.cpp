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


void data::data_handler::read_moves_vector(std::string path) {
	using namespace boost;

	std::ifstream in(path.c_str());//get file path
	if (!in.is_open()) {
		typedef tokenizer< escaped_list_separator<char> > Tokenizer;//token seperator ','
		std::vector<std::string> vec;//read vector
		std::vector<std::string> vec2;//store vector

		std::string line;//current line

		bool lab = true;
		while (getline(in, line))
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



				copy(vec.begin(), vec.end(), std::back_inserter(vec2));//copy line to main vector
			}
			
		}
	}

	
}
void data::data_handler::split_data() {
	//keep track of indexes used and fill other arrays without emptying data array
	std::unordered_set<int> used_indexes;
	int train_size = data_array->size() * TRAIN_SET_PERCENT;
	int test_size = data_array->size() * TEST_SET_PERCENT;
	int valid_size = data_array->size() * VALIDATION_SET_PERCENT;

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
	printf("Training Data Size: %ul.\n", training_data->size());
	printf("Test Data Size: %ul.\n", test_data->size());
	printf("Validation Data Size: %ul.\n", validation_data->size());

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



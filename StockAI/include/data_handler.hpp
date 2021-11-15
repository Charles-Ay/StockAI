#pragma once

#include"data.hpp"
#include<fstream>
#include<stdint.h>
#include<iostream>
#include<ostream>
#include<vector>
#include<map>
#include<string>
#include<filesystem>
#include<unordered_set>
#include <algorithm>    // copy
#include <iterator>     // ostream_operator
#include <boost/tokenizer.hpp>



//class used to read data, split data
//count number of unique classes
//pass train, test and validation data

namespace data {
	class data_handler {
		std::vector<data*>* data_array;//all of data pre-split
		std::vector<data*>* training_data;
		std::vector<data*>* test_data;
		std::vector<data*>* validation_data;

		//int num_classes;//number of classes we currently have
		//int feature_vector_size;
		//std::map<uint8_t, int>class_map;

		//Set percent of data in vector to be used on different parts of
		//Algorithm adding up to 100
		const double TRAIN_SET_PERCENT = 0.75;
		const double TEST_SET_PERCENT = 0.20;
		const double VALIDATION_SET_PERCENT = 0.05;

	public:
		std::vector<std::string>header;
		data_handler();
		~data_handler();

		/// <summary>
		/// read moves data
		/// </summary>
		/// <param name="path">the path to data</param>
		void read_moves_vector(std::string path);
		/// <summary>
		/// read moves headers
		/// </summary>
		/// <param name="path">the path to data</param>
		void read_moves_headers(std::string path);
		/// <summary>
		/// split data according to corresponding percentages
		/// </summary>
		void split_data();

		//void count_classes();

		std::vector<data*>* get_training_data();
		std::vector<data*>* get_test_data();
		std::vector<data*>* get_validation_data();
	};
}



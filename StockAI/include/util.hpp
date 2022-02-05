#pragma once

#include <map>
#include<string>
#include <stdexcept>
namespace util {
	//data values
	using day_t = int;
	using month_t = int;
	using year_t = long long;

	//stock values
	using money_t = double;
	using volume_t = long long;

	inline bool string_contains(std::string orig, std::string to_find) { return orig.find(to_find) != std::string::npos; }

	/// <summary>
	/// checks to see if data is valid.
	/// </summary>
	/// <param name="value">value to check</param>
	/// <param name="type">type to compare to. accpetable types: int</param>
	/// <returns></returns>
	inline bool validate(std::string value, std::string type) {
		if (type == "int") {
			bool valid = true;
			for (unsigned i = 0; i < value.size(); ++i) {
				if (!isdigit(value[i]))return false;
			}
		}
		return true;
	}

	inline money_t string_to_money(std::string s) { return std::stod(s); }
	inline volume_t string_to_volume(std::string s) { return std::stoll(s); }

	std::map <std::string, std::string> saved_names({
		{"APPL", "Apple"} });

	inline std::string derive_name(const std::string &tick) {
		for (auto n : saved_names) {
			if (n.first == tick)return n.second;
		}
		throw std::invalid_argument(tick + " not known");
	}
}
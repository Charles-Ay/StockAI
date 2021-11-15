#pragma once

#include<string>
namespace util {
	//data values
	using day_t = int;
	using month_t = int;
	using year_t = long long;

	//stock values
	using money_t = double;
	using volume_t = long long;

	constexpr bool string_contains(std::string orig, std::string to_find) { return orig.find(to_find) != std::string::npos; }
}
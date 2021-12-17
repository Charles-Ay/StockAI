#include "../include/data.hpp"

constexpr char const* month_name_short(month_t month) {
	constexpr char const* const names[13] = {
		"",
		"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
		"JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
	};
	return names[month];
}

constexpr char const* month_name_long(month_t month) {
	constexpr char const* const names[13] = {
		"",
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};
	return names[month];
}

constexpr double convert_to_day_num(int* year, int* month, int* day) {
	return 0;
}

year_t date_to_number(date& d) {
	int x = 100 * d.get_month();
	return 10000 * d.get_year() + x + d.get_day();
}

year_t date_to_number(year_t year, month_t month, day_t day) {
	return 10000 *year + static_cast<year_t>(year_t(100) * month + day);
}

date number_to_date(year_t num) {
	year_t y = num / 10000;
	double tmp = y - (num / 10000.0);
	if (tmp < 0)tmp *= -1;
	tmp *= 10000;
	month_t m = tmp / 100;
	tmp -= static_cast<double>(m * 100.0);
	day_t d = ceil(tmp);
	return date(y, m, d);
}

date extract_date_from_string(std::string s) {
	if (string_contains(s, "-")) {
		bool y = true;
		bool m = true;
		bool d = true;

		std::string yr;
		std::string mo;
		std::string da;

		//need to find more efficent way to parse date
		for (size_t i = 0; i < s.size(); ++i) {
			if (y && s[i] != '-') yr += s[i];
			else if(y){ y = false; ++i; }//increment to go to next index
			if (m && !y && s[i] != '-') mo += s[i];
			else if(!y)m = false;
			if(!m && s[i] != '-')da += s[i];
		}
		return date(string_to_year(yr), string_to_month(mo), string_to_day(da));
	}
	else if (string_contains(s, "/")) {
		bool y = true;
		bool m = true;
		bool d = true;

		std::string yr;
		std::string mo;
		std::string da;

		for (size_t i = 0; i < s.size(); ++i) {
			if (y && s[i] != '/') yr += s[i];
			else if (y) { y = false; ++i; }//increment to go to next index
			if (m && !y && s[i] != '/') mo += s[i];
			else if (!y)m = false;
			if (!m && s[i] != '-')da += s[i];
		}
		return date(string_to_year(yr), string_to_month(mo), string_to_day(da));
	}
	else throw std::invalid_argument("Invalid date format");
}
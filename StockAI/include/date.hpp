#pragma once

#include "util.hpp"

using namespace util;

enum month_val { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };


/** Get the short name of the civil month.
	@return pointer to the 3-letter month name as a c-string.
	@param month [in] month number [1..12]
*/
constexpr char const* month_name_short(month_t month);

/** Get the full name of the civil month.
	@return pointer to the month name as a c-string.
	@param month [in] month number [1..12]
*/
constexpr char const* month_name_long(month_t month);

/*
* date layout:
* month/day/year
* year = year
* month = month / 12
* day = day / 30
*
*/

/// <summary>
/// convert a date to a special day number
/// </summary>
/// <param name="year">year</param>
/// <param name="month">month</param>
/// <param name="day">day</param>
constexpr double convert_to_day_num(int* year, int* month, int* day);

class date {
	year_t year = 0;
	month_t month = 0;
	day_t day = 0;
public:
	date(){}
	inline date(year_t y, month_t m, day_t d) :year(y), month(m), day(d){}

	constexpr year_t get_year() { return year; }
	constexpr month_t get_month() { return month; }
	constexpr day_t get_day() { return day; }

	constexpr void set_date(year_t y, month_t m, day_t d) {
		year = y; month = m; day = d;
	}
	friend inline std::ostream& operator<<(std::ostream& os, const date& dt);
};

inline bool operator==(date lhs, date rhs) {
	if (lhs.get_year() == rhs.get_year() && lhs.get_month() == rhs.get_month() && lhs.get_day() == rhs.get_day())
		return true;
	return false;
}

/// <summary>
/// turn date into int value
/// </summary>
/// <param name="d">date to parse</param>
/// <returns>date int val</returns>
year_t date_to_number(date& d);

/// <summary>
/// turn date into int value
/// </summary>
/// <param name="year"></param>
/// <param name="month"></param>
/// <param name="day"></param>
/// <returns>date int val</returns>
year_t date_to_number(year_t year, month_t month, day_t day);

/// <summary>
/// turn a number into a formated date
/// </summary>
/// <param name="num">number to use</param>
/// <returns></returns>
date number_to_date(year_t num);


/// <summary>
/// extract a date class from a string
/// </summary>
/// <param name="s">string to extract from</param>
/// <returns>a date class</returns>
date extract_date_from_string(std::string s);

inline year_t string_to_year(std::string s) { return stoll(s); }
inline month_t string_to_month(std::string s) { return stoi(s); }
inline day_t string_to_day(std::string s) { return stoi(s); }
inline std::ostream& operator<<(std::ostream& os, const date& dt) {
	os << dt.year << '/' << dt.month << '/' << dt.day;
	return os;
}

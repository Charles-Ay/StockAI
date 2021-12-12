#pragma once

#include "util.hpp"

using namespace util;

/** Get the short name of the civil month.
	@return pointer to the 3-letter month name as a c-string.
	@param month [in] month number [1..12]
*/
constexpr char const* month_name_short(month_t month) {
	constexpr char const* const names[13] = {
		"",
		"JAN", "FEB", "MAR", "APR", "MAY", "JUN",
		"JUL", "AUG", "SEP", "OCT", "NOV", "DEC"
	};
	return names[month];
}

/** Get the full name of the civil month.
	@return pointer to the month name as a c-string.
	@param month [in] month number [1..12]
*/
constexpr char const* month_name_long(month_t month) {
	constexpr char const* const names[13] = {
		"",
		"January", "February", "March", "April", "May", "June",
		"July", "August", "September", "October", "November", "December"
	};
	return names[month];
}

enum month_val { JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC };

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
constexpr double convert_to_day_num(int* year, int* month, int* day) {
	return 0;
}

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
		year = y;
		month = m;
		day = d;
	}
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
int parseDate(date &d) {
	return 10000 * d.get_year() + 100 * d.get_month() + d.get_day();
}

/// <summary>
/// turn date into int value
/// </summary>
/// <param name="year"></param>
/// <param name="month"></param>
/// <param name="day"></param>
/// <returns>date int val</returns>
int parseDate(year_t year, month_t month, day_t day) {
	return 10000 * year + 100 * month + day;
}
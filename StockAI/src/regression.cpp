#include "../include/regression.hpp"

util::money_t maths::cal_mean_x(const std::unordered_map<util::money_t, util::year_t>& data)
{
	util::money_t count = 0;
	for (auto val : data) {
		count += val.first;
	}
	return count/static_cast<util::money_t>(data.size());
}

util::year_t maths::cal_mean_y(const std::unordered_map<util::money_t, util::year_t>& data)
{
	util::year_t count = 0;
	for (auto val : data) {
		count += val.second;
	}
	return count/static_cast<util::year_t>(data.size());
}

util::money_t maths::cal_std_deviation_x(const std::unordered_map<util::money_t, util::year_t>& data, const util::money_t& xmean)
{
	util::money_t sum = 0;
	for (auto val : data) {
		sum += std::pow(val.first - xmean, 2.0);
	}
	return std::sqrt(sum / static_cast<util::money_t>(data.size()));
}

util::money_t maths::cal_std_deviation_y(const std::unordered_map<util::money_t, util::year_t>& data, const util::year_t& ymean)
{
	util::money_t sum = 0;
	for (auto val : data) {
		sum += std::pow(val.first - ymean, 2);
	}
	return std::sqrt(sum / static_cast<util::money_t>(data.size()));
}

util::money_t maths::per_top(const std::unordered_map<util::money_t, util::year_t>& data, const util::money_t& xmean, const util::year_t& ymean)
{
	util::money_t total = 0;
	for (auto val : data) {
		total += (val.first - xmean) * (val.second - static_cast<util::money_t>(ymean));
	}
	return total;
}

util::money_t maths::per_bot(const std::unordered_map<util::money_t, util::year_t>& data, const util::money_t& xmean, const util::year_t& ymean)
{
	util::money_t sumx = 0;
	util::year_t sumy = 0;
	for (auto val : data) {
		sumx += (std::pow(val.first - xmean, 2.0));
		sumy += static_cast<util::year_t>(std::pow(val.second - ymean, 2));
	}
	return std::sqrt(static_cast<util::money_t>(sumx) * sumy);
}

util::money_t maths::cal_per_corr(const std::unordered_map<util::money_t, util::year_t>& data, const util::money_t& xmean, const util::year_t& ymean)
{
	return maths::per_top(data, xmean, ymean) / maths::per_bot(data, xmean, ymean);
}

util::money_t maths::reg_slope(const std::unordered_map<util::money_t, util::year_t>& data, const util::money_t& xmean, const util::year_t& ymean)
{
	return maths::cal_per_corr(data, xmean, ymean) * (maths::cal_std_deviation_x(data, xmean) / maths::cal_std_deviation_y(data, ymean));
}

util::money_t maths::reg_y_intercept(const std::unordered_map<util::money_t, util::year_t>& data, const util::money_t& xmean, const util::year_t& ymean)
{
	return ymean - (maths::reg_slope(data, xmean, ymean) * xmean);
}

util::money_t maths::cal_regression(const std::unordered_map<util::money_t, util::year_t>& data)
{
	//y = a + b * x
	util::money_t xmean = cal_mean_x(data);
	util::year_t ymean = cal_mean_y(data);

	util::money_t ret = 0;
	//std::unordered_map<util::money_t, util::year_t> reg;

	for (auto val : data) {
		ret += static_cast<util::year_t>(maths::reg_y_intercept(data, xmean, ymean) + (maths::reg_slope(data, xmean, ymean) * val.first));
		//reg.insert(std::make_pair(val.first, static_cast<util::year_t>(maths::reg_y_intercept(data, xmean, ymean) + (maths::reg_slope(data, xmean, ymean) * val.first))));
	}

	return ret;
}


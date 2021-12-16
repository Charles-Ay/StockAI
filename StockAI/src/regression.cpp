#include "../include/regression.hpp"

int maths::cal_mean_x(const std::unordered_map<int, double>& data)
{
	int count = 0;
	for (auto val : data) {
		count += val.first;
	}
	return count/data.size();
}

double maths::cal_mean_y(const std::unordered_map<int, double>& data)
{
	double count = 0;
	for (auto val : data) {
		count += val.second;
	}
	return count/data.size();
}

int maths::cal_std_deviation_x(const std::unordered_map<int, double>& data, const int& xmean)
{
	int sum = 0;
	for (auto val : data) {
		sum += std::pow(val.first - xmean, 2);
	}
	return std::sqrt(sum / data.size());
}

int maths::cal_std_deviation_y(const std::unordered_map<int, double>& data, const double& ymean)
{
	int sum = 0;
	for (auto val : data) {
		sum += std::pow(val.first - ymean, 2);
	}
	return std::sqrt(sum / data.size());
}

double maths::per_top(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean)
{
	double total = 0;
	for (auto val : data) {
		total += (double(val.first) - xmean) * (val.second - ymean);
	}
	return total;
}

double maths::per_bot(const std::unordered_map<int, double>& data, const int &xmean, const double& ymean)
{
	int sumx = 0;
	double sumy = 0;
	for (auto val : data) {
		sumx += std::pow(val.first - xmean, 2);
		sumy += std::pow(val.second - ymean, 2);
	}
	return std::sqrt(sumx * sumy);
}

double maths::cal_per_corr(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean)
{
	return maths::per_top(data, xmean, ymean) / maths::per_bot(data, xmean, ymean);
}

double maths::reg_slope(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean)
{
	return maths::cal_per_corr(data, xmean, ymean) * (maths::cal_std_deviation_x(data, xmean) / maths::cal_std_deviation_y(data, ymean));
}

double maths::reg_y_intercept(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean)
{
	return ymean - (maths::reg_slope(data, xmean, ymean) * xmean);
}

double maths::cal_regression(const std::unordered_map<int, double>& data)
{
	//y = a + b * x
	int xmean = cal_mean_x(data);
	double ymean = cal_mean_y(data);

	std::unordered_map<int, double> reg;

	for (auto val : data) {
		reg.insert(std::make_pair(val.first, maths::reg_y_intercept(data, xmean, ymean) + (maths::reg_slope(data, xmean, ymean) * val.first)));
	}
	return 0.0;
}


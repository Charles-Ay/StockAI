#include "../include/regression.hpp"

int cal_mean_x(const std::unordered_map<int, double>& data)
{
	int count = 0;
	for (auto val : data) {
		count += val.first;
	}
	return count/data.size();
}

double cal_mean_y(const std::unordered_map<int, double>& data)
{
	double count = 0;
	for (auto val : data) {
		count += val.second;
	}
	return count/data.size();
}

int cal_std_deviation_x(const std::unordered_map<int, double>& data, const int& xmean)
{
	int sum = 0;
	for (auto val : data) {
		sum += std::pow(val.first - xmean, 2);
	}
	return std::sqrt(sum / data.size());
}

int cal_std_deviation_y(const std::unordered_map<int, double>& data, const double& ymean)
{
	int sum = 0;
	for (auto val : data) {
		sum += std::pow(val.first - ymean, 2);
	}
	return std::sqrt(sum / data.size());
}

double per_top(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean)
{
	double total = 0;
	for (auto val : data) {
		total += (double(val.first) - xmean) * (val.second - ymean);
	}
	return total;
}

double per_bot(const std::unordered_map<int, double>& data, const int &xmean, const double& ymean)
{
	int sumx = 0;
	double sumy = 0;
	for (auto val : data) {
		sumx += std::pow(val.first - xmean, 2);
		sumy += std::pow(val.second - ymean, 2);
	}
	return std::sqrt(sumx * sumy);
}

double cal_per_corr(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean)
{
	return per_top(data, xmean, ymean) / per_bot(data, xmean, ymean);
}

double reg_slope(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean)
{
	return cal_per_corr(data, xmean, ymean) * (cal_std_deviation_x(data, xmean) / cal_std_deviation_y(data, ymean));
}

double reg_y_intercept(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean)
{
	return ymean - (reg_slope(data, xmean, ymean) * xmean);
}

double cal_regression(const std::unordered_map<int, double>& data)
{
	//y = a + b * x
	int xmean = cal_mean_x(data);
	double ymean = cal_mean_y(data);

	std::unordered_map<int, double> reg;

	for (auto val : data) {
		reg.insert(std::make_pair(val.first, reg_y_intercept(data, xmean, ymean) + (reg_slope(data, xmean, ymean) * val.first)));
	}
}


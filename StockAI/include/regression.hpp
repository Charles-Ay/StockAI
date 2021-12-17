#pragma once
#include "util.hpp"
#include <unordered_map>
#include <cmath>
namespace maths {
	/// <summary>
	/// calculate the mean of the x elements in a map
	/// </summary>
	/// <param name="data">the map to use</param>
	/// <returns>the x mean</returns>
	int cal_mean_x(const std::unordered_map<int, double>& data);
	/// <summary>
	/// calculate the mean of the y elements in a map
	/// </summary>
	/// <param name="data">the map to use</param>
	/// <returns>the y mean</returns>
	double cal_mean_y(const std::unordered_map<int, double>& data);

	/// <summary>
	/// calculates the population standard deviation of the x elements of a map(population formula)
	/// </summary>
	/// <param name="data">the map to use</param>
	/// <param name="xmean">the mean of the x elements</param>
	/// <returns></returns>
	int cal_std_deviation_x(const std::unordered_map<int, double>& data, const int& xmean);
	/// <summary>
	/// calculates the population standard deviation of the y elements of a map(population formula)
	/// </summary>
	/// <param name="data">the map to use</param>
	/// <param name="ymean">the mean of the y elements</param>
	/// <returns></returns>
	double cal_std_deviation_y(const std::unordered_map<int, double>& data, const double& ymean);


	/// <summary>
	/// calculate the top half of Pearson correlation
	/// </summary>
	/// <param name="data">the map to use</param>
	/// <param name="xmean">the mean of the x elements</param>
	/// <param name="ymean">the mean of the y elements</param>
	/// <returns>top half value</returns>
	double per_top(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean);
	/// <summary>
	/// calculate the bottom half of Pearson correlation
	/// </summary>
	/// <param name="data">the map to use</param>
	/// <param name="xmean">the mean of the x elements</param>
	/// <param name="ymean">the mean of the y elements</param>
	/// <returns>bottom half value</returns>
	double per_bot(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean);
	/// <summary>
	/// calculate the Pearson correlation coefficient of a map
	/// </summary>
	/// <param name="data">the map to use</param>
	/// <param name="xmean">the mean of the x elements</param>
	/// <param name="ymean">the mean of the y elements</param>
	/// <returns>the person Pearson correlation coefficient of the map</returns>
	double cal_per_corr(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean);


	/// <summary>
	/// caluculate slope of linear regression line
	/// </summary>
	/// <param name="data">the map to use</param>
	/// <param name="xmean">the mean of the x elements</param>
	/// <param name="ymean">the mean of the y elements</param>
	/// <returns>the regression line slope</returns>
	double reg_slope(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean);

	/// <summary>
	/// caluculate y-intercept of linear regression line
	/// </summary>
	/// <param name="data">the map to use</param>
	/// <param name="xmean">the mean of the x elements</param>
	/// <param name="ymean">the mean of the y elements</param>
	/// <returns>the y-intercept line slope</returns>
	double reg_y_intercept(const std::unordered_map<int, double>& data, const int& xmean, const double& ymean);

	/// <summary>
	/// calculate the simple linear regression
	/// </summary>
	/// <param name="data">map to use</param>
	/// <returns>regressionLine?</returns>
	double cal_regression(const std::unordered_map<int, double>& data);
}
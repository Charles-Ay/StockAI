#include <iostream>     // cout, endl
#include <fstream>      // fstream
#include <vector>
#include <string>
#include <algorithm>    // copy
#include <iterator>     // ostream_operator
#include <boost/tokenizer.hpp>
#include "include/data_handler.hpp"

int main()
{
    using namespace std;
    using namespace boost;
    string path("HistoricalData_Apple.csv");
    
    data::data_handler hand;
    hand.read_moves_vector(path);

    for (int i = 0; i < hand.v.size(); ++i) {
        if (i % 6 == 0)cout << endl;
        cout << vec[i] << " ";
    }
}
#include <iostream>     // cout, endl
#include <fstream>      // fstream
#include <vector>
#include <string>
#include <algorithm>    // copy
#include <iterator>     // ostream_operator
#include <boost/tokenizer.hpp>

int main()
{
    using namespace std;
    using namespace boost;
    string data("HistoricalData_Apple.csv");

    ifstream in(data.c_str());
    if (!in.is_open()) return 1;

    typedef tokenizer< escaped_list_separator<char> > Tokenizer;
    vector< string > vec;
    string line;

    vector< string > vec2;
    while (getline(in, line))
    {
        Tokenizer tok(line);
        vec.assign(tok.begin(), tok.end());
        cout << vec[0];
        // vector now contains strings from one row, output to cout here
        copy(vec.begin(), vec.end(), std::back_inserter(vec2));

        //cout << "\n----------------------" << endl;
    }
    //for (int i = 0; i < vec.size(); ++i) {
    //    if (i % 6 == 0)cout << endl;
    //    cout << vec[i] << " ";
    //}
}
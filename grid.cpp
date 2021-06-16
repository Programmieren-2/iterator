#include <algorithm>
using std::count_if;
using std::for_each;

#include <iostream>
using std::endl;
using std::cout;

#include "grid.h"

int main()
{
    Grid2D<int> grid({
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20},
        {21, 22, 23, 24, 25}
    });
    for_each(grid.begin(), grid.end(), [] (auto const & item) { cout << item << endl; });
    auto cnt = count_if(grid.begin(), grid.end(), [] (auto const & i) { return i > 7; });
    cout << "Count: " << cnt << endl;
}

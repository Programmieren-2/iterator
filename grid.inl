#pragma once

template <typename T>
Grid2D<T>::Grid2D(size_t x, size_t y, T const & init)
    : grid(y, std::vector<T>(x, init))
{
    if (x < 1)
        throw std::invalid_argument("x must be >= 1");
        
    if (y < 1)
        throw std::invalid_argument("y must be >= 1");
}

template <typename T>
Grid2D<T>::Grid2D(std::vector<std::vector<T>> const & grid)
    : grid(grid)
{}

template <typename T>
Grid2D<T>::Grid2D(std::initializer_list<std::initializer_list<T>> const & list)
    : grid(list.begin(), list.end())
{}

template <typename T>
T const & Grid2D<T>::operator()(size_t x, size_t y) const
{
    return grid.at(y).at(x);
}

template <typename T>
T & Grid2D<T>::operator()(size_t x, size_t y)
{
    return grid.at(y).at(x);
}

template <typename T>
T const & Grid2D<T>::operator[](std::pair<size_t, size_t> const & coordinate) const
{
    return grid(coordinate.first, coordinate.second);
}

template <typename T>
T & Grid2D<T>::operator[](std::pair<size_t, size_t> const & coordinate)
{
    return grid(coordinate.first, coordinate.second);
}

template <typename T>
size_t Grid2D<T>::sizeX() const
{
    return grid[0].size();
}

template <typename T>
size_t Grid2D<T>::sizeY() const
{
    return grid.size();
}

template <typename T>
size_t Grid2D<T>::size() const
{
    return sizeX() * sizeY();
}

template <typename T>
Grid2DIterator<T> Grid2D<T>::begin()
{
    return Grid2DIterator(this, 0);
}

template <typename T>
Grid2DIterator<T> Grid2D<T>::end()
{
    return Grid2DIterator(this, sizeX() * sizeY());
}

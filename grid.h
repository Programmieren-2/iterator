#pragma once

#include <iterator>
#include <stdexcept>
#include <utility>
#include <vector>


template <typename T>
class Grid2DIterator;


template <typename T>
class Grid2D {
private:
    std::vector<std::vector<T>> grid;
public:
    Grid2D(size_t x, size_t y, T const & init);
    Grid2D(std::vector<std::vector<T>> const & grid);
    
    T const & operator()(size_t x, size_t y) const;
    T & operator()(size_t x, size_t y);
    T const & operator[](std::pair<size_t, size_t> const & coordinate) const;
    T & operator[](std::pair<size_t, size_t> const & coordinate);
    bool operator==(Grid2D<T> const & other) const;
    
    size_t sizeX() const;
    size_t sizeY() const;
    size_t size() const;
    
    Grid2DIterator<T> begin();
    Grid2DIterator<T> end();
};

#include "grid.inl"


template <typename T>
class Grid2DIterator : public std::iterator<std::input_iterator_tag, T> {
private:
    Grid2D<T> & grid;
    size_t index;

    size_t getX() const;
    size_t getY() const;
public:
    using iterator = Grid2DIterator<T>;

    Grid2DIterator(Grid2D<T> * grid, size_t index);

    T & operator*();
    Grid2DIterator & operator++();
    bool operator==(Grid2DIterator const & other) const;
    bool operator!=(Grid2DIterator const & other) const;
};

#include "grid_iterator.inl"

#pragma once

template <typename T>
size_t Grid2DIterator<T>::getX() const
{
    return index % grid.sizeX();
}

template <typename T>
size_t Grid2DIterator<T>::getY() const
{
    return index / grid.sizeX();
}

template <typename T>
Grid2DIterator<T>::Grid2DIterator(Grid2D<T> * grid, size_t index)
    : grid(*grid), index(index)
{}

template <typename T>
T & Grid2DIterator<T>::operator*()
{
    return grid(getX(), getY());
}

template <typename T>
Grid2DIterator<T> & Grid2DIterator<T>::operator++()
{
    ++index;
    return *this;
}

template <typename T>
bool Grid2DIterator<T>::operator==(Grid2DIterator const & other) const
{
    return index == other.index;
}

template <typename T>
bool Grid2DIterator<T>::operator!=(Grid2DIterator const & other) const
{
    return index != other.index;
}

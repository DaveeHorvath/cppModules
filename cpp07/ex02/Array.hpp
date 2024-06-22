#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <exception>
#include <stdexcept>
template<class T>
class Array
{
    private:
        unsigned int _size;
        T* _array;
    public:
        Array() : _size(0) {_array = NULL;}
        Array(unsigned int size): _size(size) {_array = new T[size]();}
        ~Array() {if (_array) delete[] _array;}
        Array(Array const& other) {
            _size = other._size;
            _array = new T[_size]();
            for (unsigned int i = 0; i < _size; i++)
                _array[i] = other._array[i];
        }
        Array& operator=(Array const& other) {
            if (this != &other)
            {
                if (_array)
                    delete[] _array;
                _size = other._size;
                _array = new T[_size]();
                for (unsigned int i = 0; i < _size; i++)
                    _array[i] = other._array[i];
            }
            return *this;
        }
        T& operator[](unsigned int index) {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _array[index];
        }

        const T& operator[](unsigned int index) const {
            if (index >= _size)
                throw std::out_of_range("Index out of bounds");
            return _array[index];
        }
        inline unsigned int size() {return _size;}
};

#endif
#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>
# include <stdexcept>

template <class T>
class Array {
private:
	T*      arr;
	size_t  n;

public:
	Array() : arr(NULL), n(0) {};

	Array(size_t size) : n(size) {
		arr = new T[n]();
	}

	~Array() {
		delete[] arr;
	}

	Array(const Array<T>& other) {
		n = other.n;
		arr = new T[n]();
		for (size_t i = 0; i < n; ++i)
			arr[i] = other.arr[i];
	}

	Array<T>& operator=(const Array<T>& other) {
		if (this == &other)
			return *this;
		delete [] arr;
		n = other.n;
		arr = new T[n];
		for (size_t i = 0; i < n; ++i)
			arr[i] = other.arr[i];
	    return *this;
	}

	T& operator[](size_t index) {
		if (index >= n)
			throw std::out_of_range("Index out of range");
		return arr[index];
	}

    const T& operator[](size_t index) const {
        if (index >= n)
            throw std::out_of_range("Index out of range");
        return arr[index];
    }

	size_t size() const {
		return n;
	}
};

#endif
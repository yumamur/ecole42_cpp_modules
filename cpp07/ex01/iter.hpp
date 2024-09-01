#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>

template <typename T>
void iter(T *a, size_t l, void (*f)(T const &)) {
	for (size_t i = 0; i < l; i++) {
		f(a[i]);
	}
}

#endif // !ITER_HPP

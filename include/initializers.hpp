#ifndef LIGHTGEBRA_INITIALIZERS_HPP
#define LIGHTGEBRA_INITIALIZERS_HPP

#include <smatrix.hpp>

template <typename Number, int lin, int col>
constexpr void eye(SMatrix<Number, lin, col>& mat) {
	for (int i = 0; i < lin; ++i)
		for (int j = 0; j < col; ++j)
			mat(i, j) = Number{static_cast<int>(i == j)};
}

#endif

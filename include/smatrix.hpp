#ifndef LIGHTGEBRA_SMATRIX_HPP
#define LIGHTGEBRA_SMATRIX_HPP

#include <array>
#include <algorithm>

#include <cassert>

template <typename Number, int nb_lines, int nb_columns>
class SMatrix {
	static_assert(nb_lines > 0, "Incorrect number of lines.");
	static_assert(nb_columns > 0, "Incorrect number of columns.");

    private:
	std::array<Number, nb_lines * nb_columns> arr_;

    public:
	// rule of 5
	constexpr SMatrix() = default;
	constexpr SMatrix(SMatrix const&) = default;
	constexpr SMatrix(SMatrix&&) = default;
	constexpr SMatrix& operator=(SMatrix&&) = default;
	constexpr SMatrix& operator=(SMatrix const&) = default;
	constexpr SMatrix(std::initializer_list<Number> elems) {
		assert(static_cast<int>(elems.size()) == lines() * columns() &&
		       "Initializer size does not match required size.");
		std::copy(elems.begin(), elems.end(), arr_.begin());
	}
	constexpr SMatrix(std::initializer_list<std::initializer_list<Number>> elems) {
		int i = 0;
		for (auto const& line : elems) {
			for (auto const& e : line) {
				assert(i < lines() * columns() && "Too many elements provided");
				arr_[i++] = e;
			}
		}
		assert(i + 1 == lines() * columns() && "Not enough elemenrs provided.");
	}

	// access operator
	constexpr Number& operator()(int line, int col) {
		assert(line < lines() && "Line index out of range.");
		assert(col < columns() && "Columns index out of range.");
		return arr_[line * columns() + col];
	}
	constexpr Number const& operator()(int line, int col) const {
		assert(line < lines() && "Line index out of range.");
		assert(col < columns() && "Columns index out of range.");
		return arr_[line * columns() + col];
	}
	template <typename U = Number>
	constexpr typename std::enable_if_t<nb_lines == 1 || nb_columns == 1, U&> operator()(int num) {
		assert((nb_columns > 1 && num < columns()) ||
		       (nb_lines > 1 && num < nb_lines) && "Index of vector out of range.");
		return arr_[num];
	}
	template <typename U = Number, typename std::enable_if_t<nb_lines == 1 && nb_columns == 1, U&>>
	constexpr operator Number() const {
		return arr_[0];
	}

	// infos
	constexpr int lines() const { return nb_lines; }
	constexpr int columns() const { return nb_columns; }

	constexpr decltype(arr_.begin()) begin() { return arr_.begin(); }
	constexpr decltype(arr_.end()) end() { return arr_.end(); }
	constexpr decltype(arr_.cbegin()) begin() const { return arr_.cbegin(); }
	constexpr decltype(arr_.cend()) end() const { return arr_.cend(); }
	constexpr decltype(arr_.cbegin()) cbegin() const { return arr_.begin(); }
	constexpr decltype(arr_.cend()) cend() const { return arr_.end(); }

	// ops
	constexpr SMatrix<Number, nb_lines, nb_columns>& operator+=(SMatrix<Number, nb_lines, nb_columns> const& oth) {
		for (int i = 0; i < static_cast<int>(arr_.size()); ++i)
			arr_[i] += oth.arr_[i];
		return *this;
	}
	template <typename N, int oth_col>
	constexpr SMatrix<Number, nb_lines, nb_columns>& operator*=(SMatrix<N, nb_columns, oth_col> const& oth) {
		for (int i = 0; i < nb_lines; ++i) {
			for (int j = 0; j < nb_columns; ++j) {
				auto tmp = Number{};
				for (int k = 0; k < nb_columns; ++k) {
					tmp += *this(i, k) * oth(k, j);
				}
				this(i, j) = tmp;
			}
		}
		return *this;
	}
	template <typename K>
	constexpr SMatrix<Number, nb_lines, nb_columns>& operator*=(K&& val) {
		for (auto& e : arr_)
			e *= val;
		return *this;
	}

};

#endif

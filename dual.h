// dual.h - Dual numbers
#pragma once
#include <initializer_list>
#include <valarray>

namespace fms {

	template<class X, std::size_t N>
	class dual {
		std::valarray<X> x;
		static constexpr std::size_t factorial(std::size_t n)
		{
			return n == 0 ? 1 : n*factorial(n-1);
		}
	public:
		dual()
			: x(X(0), N)
		{ }
		dual(const X& y)
			: x(X(0), N)
	    {
			x[0] = y;
			if (N > 1)
			    x[1] = X(1);
		}
		dual(const X* x)
			: x(x, N)
		{ }
		//dual(std::initializer_list<T> il)
		std::size_t size() const
		{
			return N;
		}
		X operator[](std::size_t i) const
		{
			return x[i];
		}
		// the i-th derivative
		X operator()(std::size_t i) const
		{
			return x[i]/factorial(i);
		}
		dual& operator+=(const X& y)
		{
			x[0] += y;

			return *this;
		}
		dual& operator+=(const dual& y)
		{
			x += y;

			return *this;
		}
		dual& operator-=(const X& y)
		{
			x[0] -= y;

			return *this;
		}
		dual& operator-=(const dual& y)
		{
			x -= y;

			return *this;
		}
		dual& operator*=(const X& y)
		{
			x *= y;

			return *this;
		}
		dual& operator*=(const dual& y)
		{
			std::valarray<X> z(X(0),N);
			for (std::size_t i = 0; i < N; ++i) {
				for (std::size_t j = 0; j <= i; ++j) {
					z[i] += x[j]*y[i - j];
				}
			}
			std::swap(x, z);

			return *this;
		}
		dual& operator/=(const X& y)
		{
			x /= y;

			return *this;
		}
		dual& operator/=(const dual& y)
		{
			std::valarray<X> z(X(0),N);
			z[0] = 1/y[0];
			for (std::size_t i = 1; i < N; ++i) {
				for (std::size_t j = 1; j <= i; ++j) {
					z[i] -= z[j-1]*y[j];
				}
				z[i] /= y[0];
			}
			std::swap(x, z);

			return *this;
		}
	};
}

template<class X, std::size_t N>
inline auto operator+(fms::dual<X,N> x, const X& y)
{
	return x += y;
}
template<class X, std::size_t N>
inline auto operator+(fms::dual<X,N> x, const fms::dual<X,N>& y)
{
	return x += y;
}

template<class X, std::size_t N>
inline auto operator-(fms::dual<X,N> x, const X& y)
{
	return x -= y;
}
template<class X, std::size_t N>
inline auto operator-(fms::dual<X,N> x, const fms::dual<X,N>& y)
{
	return x -= y;
}

template<class X, std::size_t N>
inline auto operator*(fms::dual<X,N> x, const X& y)
{
	return x *= y;
}
template<class X, std::size_t N>
inline auto operator*(fms::dual<X,N> x, const fms::dual<X,N>& y)
{
	return x *= y;
}

template<class X, std::size_t N>
inline auto operator/(fms::dual<X,N> x, const X& y)
{
	return x /= y;
}
template<class X, std::size_t N>
inline auto operator/(fms::dual<X,N> x, const fms::dual<X,N>& y)
{
	return x /= y;
}

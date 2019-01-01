// tdual.cpp
#include <cassert>
#include "dual.h"

using fms::dual;

template<class X>
void test_constructor()
{
	{
		dual<X,1> x1;
		assert (x1.size() == 1);
		assert (x1[0] == X(0));
		auto x1_{x1};
		assert (x1_.size() == 1);
		assert (x1_[0] == X(0));
		x1 = x1_;
		assert (x1.size() == 1);
		assert (x1[0] == X(0));
		assert (x1(0) == X(0));
	}
	{
		dual<X,2> x1;
		assert (x1.size() == 2);
		assert (x1[0] == X(0));
		assert (x1[1] == X(0));
		auto x1_{x1};
		assert (x1_.size() == 2);
		assert (x1_[0] == X(0));
		assert (x1_[1] == X(0));
		x1 = x1_;
		assert (x1.size() == 2);
		assert (x1[0] == X(0));
		assert (x1[1] == X(0));
		assert (x1(0) == X(0));
		assert (x1(1) == X(0));
	}
	{
		X x[] = {X(1),X(2),X(3)};
		dual<X,3> x1(x);
		assert (x1.size() == 3);
		assert (x1[0] == X(1));
		assert (x1[1] == X(2));
		assert (x1[2] == X(3));
		auto x1_{x1};
		assert (x1_.size() == 3);
		assert (x1_[0] == X(1));
		assert (x1_[1] == X(2));
		assert (x1_[2] == X(3));
		x1 = x1_;
		assert (x1.size() == 3);
		assert (x1[0] == X(1));
		assert (x1[1] == X(2));
		assert (x1[2] == X(3));
		assert (x1(0) == X(1));
		assert (x1(1) == X(2));
		assert (x1(2) == X(3)/X(2));
	}
}

// derivative of x^2
template<class X>
void test_x2()
{
	using fms::dual;
	{
		double x = 3;
		dual<X,2> x_(x);
		auto x2 = x_*x_;
		assert (x2(0) == x*x);
		assert (x2(1) == 2*x);
	}
}

int main()
{
	test_constructor<double>();
	test_x2<double>();

	return 0;
}

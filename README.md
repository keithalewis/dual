# Dual Numbers

Dual numbers let you compute derivatives to machine precision.

The basic idea is that if there were a number <math>&epsilon; &ne; 0</math> with &epsilon;<sup>2</sup> = 0
then <math>f(x + &epsilon;) = f(x) + f'(x)&epsilon;</math>.

For example, (x + &epsilon;)<sup>2</sup> = x<sup>2</sup> + 2x&epsilon; so the derivative of
x<sup>2</sup> is 2x.

Likewise, if there were a number with &epsilon;<sup>j</sup> &ne; 0 for j = 1, ..., n-1 and
&epsilon;<sup>n</sup> = 0 then f(x + &epsilon;)
= f(x) + f'(x)&epsilon; + ... + f<sup>(n-1)</sup>(x) &epsilon;<sup>n-1</sup>/(n-1)!.

There are such "numbers". Let &epsilon; be a square matrix having upper diagonal entries equal to 1
and 0 everywhere else. Use `operator()` in this library to extract derivatives. This is much simpler than the
machinery involved with [Automatic Differentiation](https://en.wikipedia.org/wiki/Automatic_differentiation).

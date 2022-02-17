/* This C program computes pi using a Monte Carlo method.
 *
 * The structure is very similar to the python code you implemented
 * last week.  To keep it simple, we won't worry about the
 * convergence plot.  We simply want a fast implementation of Monte
 * Carlo pi.
 *
 * There is a "Makefile" come with this program.  On Unix/Linux, you
 * can just type `make` on command line to compile this program.
 *
 * If you are on Windows (but not inside your WSL) or do not have have
 * `make`, then you may compile this program using
 *
 *     gcc pi.c -O3 -o pi.exe
 *
 * You can then run this program by
 *
 *     ./pi.exe
 *
 * or
 *
 *     ./pi.exe 1000000
 *
 * if you want to use more samples to compute pi.
 */



/* Step 1. Import libraries.
 *
 * C import library in a very different way compared to python.
 * The effect of including a library is similar to doing
 * "from <module> import *" in python: you can directly call all
 * the functions in the imported module.
 */
#include <time.h>   /* required for time() */
#include <stdlib.h> /* required for srand() and rand(), RAND_MAX */
#include <stdio.h>  /* required for printf() */

/* Step 2. Define a two-dimension point

   Because there is no way for C to return multiple values, we need to
   first define a "structure" to package together multiple values.
 */
struct point {
	double x, y;
};

/* Step 3. Generate one random point within the 1x1 box.
 *
 * The "struct point" means that we are returing an object of type
 * struct point.
 */
struct point random_point()
{
	return (struct point) {
		rand()/(RAND_MAX+1.0),
		rand()/(RAND_MAX+1.0)
	};
}

/* Step 4. Check if a point is in the quarter circle
 *
 * What equation should go into this function?  The first part of the
 * equation is provided as a sample to access the x-coordinate of the
 * point.  Simply replace the underscores "________" in the following
 * function.
 */
int inside(struct point p)
{
	double x_coordinate = p.x;
	________;
	return ________;
}

/* Step 5. Write the function that computes pi
 */
double montecarlo_pi(int n_sample)
{
	int n_inside = 0;

	/* 5.1. What should go into this loop?
	 */
	for (________) {
		/* 5.2. Call which function to get a point?
		 */
		struct point p = ________;

		/* 5.3. Call which function to check if the point is
		 * inside the circle?
		 */
		if (________)
			++n_inside;
	}

	/* 5.4. What formula to use to compute pi?
	 */
	return ________;
}

/* Step 6. Put montecarlo_pi() inside main() to compute pi
 */
int main(int argc, char *argv[])
{
	int n_sample = argc > 1 ? atoi(argv[1]) : 1000; /* parse input */

	/* This syntax is called ternary operator and it equivalent to:

	   int n_sample;
	   if (argc > 1) {
	       n_sample = atoi(argv[1]);
	   } else {
	       n_sample = 1000;
	   }

	   atoi transforms a command-line argument to an integer */

	srand(time(NULL)); /* seed the random number generator using
	                      the current time */

	double pi = montecarlo_pi(n_sample);

	printf("%d %g\n", n_sample, pi); /* output */

	return 0;
}

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

struct point {
	double x, y;
};
struct point random_point()
{
	return (struct point) {
		rand()/(RAND_MAX+1.0),
		rand()/(RAND_MAX+1.0)
	};
}
int inside(struct point p)
{
	double x_coordinate = p.x;
	double y_coordinate = p.y;
	double r = p.x*p.x + p.y*p.y;
	if (r <= 1)
	return 1;
	else
	return 0;
}
double montecarlo_pi(int n_sample)
{
	int n_inside = 0;
	for(int i = 0; i < n_sample; ++i){
		struct point po = random_point();
		if (inside(po))
			++n_inside;
	}


	return ( 4. * n_inside/n_sample );
}

int main(int argc, char *argv[])
{
	int n_sample = argc > 1 ? atoi(argv[1]) : 1000;


	srand(time(NULL)); 

	double pi = montecarlo_pi(n_sample);

	printf(pi);

	return 0;
}
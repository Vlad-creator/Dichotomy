#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define EQUATION(middle) (middle) * (middle) * sin(middle) - 5 * (middle) + 7

double dichotomy(double lbrace , double rbrace);

int main()
{
	double res = dichotomy(-3 , 3);
	printf("%.15f" , res);
	return 0;
}


double dichotomy(double lbrace , double rbrace)
{
	double middle = lbrace + (rbrace - lbrace) / 2;
	if ((EQUATION(middle) < __DBL_EPSILON__ * 10) && (EQUATION(middle) > -__DBL_EPSILON__ * 10))
		return middle;
	else
	{
		if (EQUATION(middle) > 0)
			middle = dichotomy(middle , rbrace);
		if (EQUATION(middle) < 0)
			middle = dichotomy(lbrace , middle);
	};
	return middle;
};

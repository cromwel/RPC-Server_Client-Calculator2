#include "calculator.h"

int *
sqr_1_svc(intWrapper *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("\nParameter: %d\n", argp->a);
	result = argp->a * argp->a;
	printf("square function Returning: %d\n\n", result);

	return &result;
}

int *
add_1_svc(intPair *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("\nParameters: %d, %d\n", argp->a, argp->b);
	result = argp->a + argp->b;
	printf("add function Returning: %d\n\n", result);

	return &result;
}

int *
mul_1_svc(intTripple *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("\nParameters: %d, %d and %d\n", argp->a, argp->b, argp->c);
	result = argp->a * argp->b * argp->c;
	printf("multiplication function Returning: %d\n\n", result);

	return &result;
}

mystring *
disp_1_svc(mystring *argp, struct svc_req *rqstp)
{
	static mystring  result;

	printf("\nParameter: %s\n", *argp);
	result = *argp;
	printf("text function Returning: %s\n\n", result);

	return &result;
}

int *
diff_1_svc(intMinus *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("\nParameters: %d, %d\n", argp->a, argp->b);
	result = argp->a - argp->b;
	printf("difference function Returning: %d\n\n", result);

	return &result;
}

int *
div_1_svc(intDivision *argp, struct svc_req *rqstp)
{
	static int  result;

	printf("\nParameters: %d, %d\n", argp->a, argp->b);
	result = argp->a / argp->b;
	printf("division function Returning: %d\n\n", result);

	return &result;
}

#include "calculator.h"


void
arith_prog_1(char *host)
{
	CLIENT *clnt;
	int  *result_1;
	intWrapper  sqr_1_arg;
	int  *result_2;
	intPair  add_1_arg;
	int  *result_3;
	intTripple  mul_1_arg;
	mystring  *result_4;
	mystring  disp_1_arg;
	int  *result_5;
	intMinus  diff_1_arg;
	int  *result_6;
	intDivision  div_1_arg;
	int option;
	char disp_arg[255];

#ifndef	DEBUG
	clnt = clnt_create (host, ARITH_PROG, ARITH_VERS, "udp");
	if (clnt == NULL) {
		clnt_pcreateerror (host);
		exit (1);
	}
#endif	/* DEBUG */

//function menu
	printf("\n\n\tOPTIONS\n\n1.Square\n2.Add\n3.Multiply\n4.Send a message\n5.Difference\n6.Division\n\tchoice:");
	scanf("%d", &option);

//checking users function choise to run its case
	switch(option) {

	case 1:// 1 variable = squaring function
			printf("Enter the number to square\n");
			scanf("%d", &sqr_1_arg);
			result_1 = sqr_1(&sqr_1_arg, clnt);
			if (result_1 == (int *) NULL) {
				clnt_perror (clnt, "call failed");
             }
                else{
				printf("Server returned: \"%d\"\n\n", *result_1);
			}

		break;

	case 2:// 2 variable  = addition function
			printf("Enter the two integers to add\n");
			scanf("%d%d", &(add_1_arg.a), &(add_1_arg.b));
			result_2 = add_1(&add_1_arg, clnt);
			if (result_2 == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			 
		else{
				printf("Server returned: \"%d\"\n\n", *result_2);
			}

		break;



	case 3:// 3 variable = multiplication function
			printf("Enter 3 integers to multiply\n");
			scanf("%d%d%d", &(mul_1_arg.a),&(mul_1_arg.b),&(mul_1_arg.c));
			result_3 = mul_1(&mul_1_arg, clnt);
			if (result_3 == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}

		else{
				printf("Server returned: \"%d\"\n\n", *result_3);
			}
		break;

	case 4:// string function
			
			printf("Enter a message to display.\n");
			scanf("%s", disp_arg);
			disp_1_arg = disp_arg;
			result_4 = disp_1(&disp_1_arg, clnt);
			if (result_4 == (mystring *) NULL) {
				clnt_perror (clnt, "call failed");

			}
			else{
				printf("Server returned: \"%s\"\n\n", *result_4);
			}
		break;


	case 5:// 2 variable  = difference function
			printf("Enter the two integers to find the difference\n");
			scanf("%d%d", &(diff_1_arg.a), &(diff_1_arg.b));
			result_5 = diff_1(&diff_1_arg, clnt);
	                if (result_5 == (int *) NULL) {
				clnt_perror (clnt, "call failed");
			}
			 
		else{
				printf("Server returned: \"%d\"\n\n", *result_5);
			}

		break;
		
		

	case 6:// 2 variable  = division function
			printf("Enter the two integers to find the quotient\n");
			scanf("%d%d", &(div_1_arg.a), &(div_1_arg.b));
	                result_6 = div_1(&div_1_arg, clnt);
	                if (result_6 == (int *) NULL) {
		                clnt_perror (clnt, "call failed");
	                }
			 
		else{
				printf("Server returned: \"%d\"\n\n", *result_6);
			}

		break;
	
		
		
	default:
		        exit(0);
		break;
		}
	

	
	
	
	
#ifndef	DEBUG
	clnt_destroy (clnt);
#endif	 /* DEBUG */
}


int
main (int argc, char *argv[])
{
	char *host;

	if (argc < 2) {
		printf ("usage: %s server_host\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	arith_prog_1 (host);
exit (0);
}

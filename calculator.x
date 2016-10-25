struct intWrapper{
	int a;
};

struct intPair {
	int a;
	int b;
};

struct intTripple {
	int a;
	int b;
	int c;
};

typedef string mystring<255>;

struct intMinus {
	int a;
	int b;
};

struct intDivision {
	int a;
	int b;
};

program ARITH_PROG {
	version ARITH_VERS {
		int SQR(intWrapper)=1;
		int ADD(intPair)=2;
		int MUL(intTripple)=3;
		mystring DISP(mystring)=4;
		int DIFF(intMinus)=5;
		int DIV(intDivision)=6;
		
		
	}=1;
}=0x3141;


typedef struct div {
	int quo;
	int remai;
}Div;

Div IntDiv(int n1, int n2)
{
	Div dval;
	dval.quo = n1 / n2;
	dval.remai = n1 % n2;

	return dval;
}
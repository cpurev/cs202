//Source.cpp
//Chuluunbat Purev
//2020-3-30
//Ackermans Analysis

//Ackerman's Function
unsigned int ackerman(int m, int n) {
	if (m == 0) return n + 1;
	if (n == 0) return ackerman(m - 1, 1);
	return ackerman(m - 1, ackerman(m, n - 1));
}

int main(void) {



	return 1;
}
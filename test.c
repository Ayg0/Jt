#include "JTest.h"


int i = 0;
int j = 6;

int cmpInt(void *i, void *j){
	return *(int *)i == *(int *)j;
}

void printInt(void *i){
	fprintf(stderr, "%d", *((int *)i));
}

int	main(){
	JTEST_START();
	ASSERT_INT_EQU(3, printf("Hi\n"));
	ASSERT_INT_EQU(7, 7);
	ASSERT_INT_EQU(7, 7);
	ASSERT_FLOAT_EQU(7.3, 7.4);
	ASSERT_STR_EQU("Hi", "Hi");
	ASSERT_STR_EQU("Hey", "Hi");
	ASSERT_STR_EQU("Hi", "Hi");
	ASSERT_DATA_EQU(&j, &i, cmpInt, printInt);
	JTEST_END();
}
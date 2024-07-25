#include "JTest.h"

int	main(){
	JTEST_START();
	ASSERT_INT_EQU(3, printf("Hi\n"));
	ASSERT_INT_EQU(7, 7);
	ASSERT_INT_EQU(7, 7);
	ASSERT_FLOAT_EQU(7.3, 7.4);
	ASSERT_STR_EQU("Hi", "Hi");
	ASSERT_STR_EQU("Hey", "Hi");
	ASSERT_STR_EQU("Hi", "Hi");
	JTEST_END();
}
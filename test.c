#include "JTest.h"


typedef struct vector
{
	int x;
	int y;
} _vector;

int cmpVector(void *vec1, void *vec2){
	return *(int *)vec1 == *(int *)vec2;
}

void printVector(void *data){
	_vector *vec = data;

	printf("x = %3d; y = %3d\n", vec->x, vec->y);
}

int	main(){
	_vector v1 = {.x = 0, .y = 6};
	_vector v2 = {.x = -1, .y = 6};
	JTEST_START();
	ASSERT_INT_EQU(3, printf("Hi\n"));
	ASSERT_INT_EQU(7, 7);
	ASSERT_INT_EQU(7, 7);
	ASSERT_FLOAT_EQU(7.3, 7.4);
	ASSERT_STR_EQU("Hi", "Hi");
	ASSERT_STR_EQU("Hey", "Hi");
	ASSERT_STR_EQU("Hi", "Hi");
	ASSERT_DATA_EQU(&v1, &v2, cmpVector, printVector);
	JTEST_END();
}
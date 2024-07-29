#include "JTest.h"

typedef struct vector{
	int x;
	int y;
} _vector;

int cmpVector(void *vec1, void *vec2){
	_vector *v1 = vec1, *v2 = vec2;

	return (v1->x == v2->x) && (v1->y == v2->y);
}

void printVector(void *data){
	_vector *vec = data;

	fprintf(stderr, "x = %3d; y = %3d\n", vec->x, vec->y);
}

void Jsetup(){
    //printf("\033[33mEnv Setup\033[0m\n");
}

void Jcleanup(){
	//printf("\033[33mEnv cleanup\033[0m\n");
}

TEST_START(vectorSimpleTests)
	ASSERT_FLOAT_EQU(7.3, 7.3);
	ASSERT_INT_EQU(7.3, 7.3);
	ASSERT_STR_EQU("Hi", "Hi");
TEST_END

TEST_START(vectorDataTests)IGNORE_ME
	_vector v1 = {.x = 0, .y = 6};
	_vector v2 = {.x = 0, .y = 6};
	ASSERT_DATA_EQU(&v1, &v2, cmpVector, printVector);
	v2.x = 0;
	v2.y = 5;
	ASSERT_DATA_EQU(&v1, &v2, cmpVector, NULL);
TEST_END

TEST_START(sprintfTest)
	char s[20];
	sprintf(s, "%s", "Hey");
	ASSERT_STR_EQU("Hey", s);
TEST_END

int	main(){
	JTEST_START();
	runTests();
	JTEST_END();
}


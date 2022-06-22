#include <iostream>
using namespace std;

int main(){

/*
cout<<'A'
int i1 = 10;
int i2 = 20; 
const int* pInt1; //포인터 변수가 가리키는 주소의 값을 const하였다.
pInt1 = &i1;  
*pInt1 = 30; //const된 '포인터가 가리키는 변수'를 변경하려 하였기에 오류가 발생한다.
*/

/*
cout<<'B'
int i1 = 10;
int i2 = 20;
int* const pInt2 = &i1;  //포인터 변수를 const하였다.
pInt2 = &i2;  //포인터 변수 자체가 const되었기 때문에 변경할 수 없다. 오류 발생.
*pInt2 = 50;  //포인터 변수가 가리키는 변수는 변경 가능하다.
*/

/*
cout<<'C'
int i1 = 10; 
int i2 = 20;
const int* const p = &i2;  //포인터 변수 자체와 포인터 변수가 가리키는 변수 둘다 const하였다.
p = &i1;  //두 변수 모두 변경 불가능하다. 둘 다 오류 발생.
*p = 40;
*/

return 0;
}
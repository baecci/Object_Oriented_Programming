#include <iostream>
#include <cstring>
using namespace std;
#define Num 11

/*
                HW#4 : 개선된 함수기능                    
  작성자 : 배기원 2021041081         날짜 : 2022년 04월 07일   
                                                           
  문제 정의 : 함수 오버로딩 이해하기                             
                                          
*/

//매개변수의 데이터 타입으로 함수 오버로딩.
int GetMin(int a, int b);  //두 정수 중 최소값을 구하는 함수.
double GetMin(double a, double b);  //두 실수 중 최소값을 구하는 함수.
void GetMin(char *a, char *b);  //두 문자열 중 최소값을 구하는 함수.
int GetMin(int *a, int b);  //정수형 배열의 원소들 중 최소값을 구하는 함수.

int main(){
    //정수의 최소 구하기
    int i1, i2;
    cout<<"두 정수를 입력하세요: ";
    cin>>i1>>i2;
    cout<<"두 정수 중 최소값은 "<<GetMin(i1, i2)<<"입니다.\n";

    //실수 최소 구하기
    double d1, d2;
    cout<<"두 실수를 입력하세요: ";
    cin>>d1>>d2;
    cout<<"두 실수 중 최소값은 "<<GetMin(d1, d2)<<"입니다.\n";

    //문자열 최소 구하기
    char c1[10], c2[10];
    cout<<"두 문자열를 입력하세요: ";
    cin>>c1>>c2;
    cout<<"두 문자열 중 최소값은 ";
    GetMin(c1, c2);
    cout<<"입니다.\n";

    //정수형 배열의 원소 최솟값 구하기
    int intArray[Num];
    cout<<"배열의 원소 10개를 입력하세요: ";
    for(int n=0 ;n<Num-1 ;n++){
        cin>>intArray[n];
    }
    cout<<"원소 중 최솟값: "<<GetMin(intArray, Num);

    return 0;
}

int GetMin(int a, int b){
    return a < b ? a : b;
}

double GetMin(double a, double b){
    return a < b ? a : b;
}

void GetMin(char *a, char *b){
    if(strcmp(a, b) == -1) cout<<a;
    else cout<<b;    
}

int GetMin(int *a, int b){
    int min = a[0];
    for(int i = 1; i < b-2; i++) min = min < a[i] ? min : a[i];
    return min;
}

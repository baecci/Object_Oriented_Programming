#include <iostream>
#include <string>
using namespace std;

#include "Subject.h"
#include "Student.h"


/*
                HW#9 : 객체지향방식의 성적처리프로그램#2                   
  작성자 : 배기원 2021041081         날짜 : 2022년 05월 17일   

  문제 정의 : Modify함수 추가 및 생성자와 소멸자 테스트                

*/


int main() {
    Subject sub1("컴퓨터", 3, "C"); 
    Subject sub2(sub1);  //복사 생성자(얕은 복사 상태)
    cout << "\n" << "sub1 정보" << "\n"; 
    sub1.PrintData();
    cout << "\n" << "sub2 정보" << "\n"; 
    sub2.PrintData();
    sub2.Modify();
    
    //Student st1;  //디폴트 생성자 호출
    Student st2("홍길동", 2013909845, 1, &sub1);  //st2의 인자있는 생성자, 멤버변수 sub 디폴트 생성자 호출
    Student st3("김성령", 2015909845, 1, &sub2);  // ''
    Student st1(st2);

    st1 = st2;  
    cout << "\n" << "st1 정보" << "\n"; 
    st1.PrintData();    

    cout << "\n" << "st2 정보" << "\n"; 
    st2.PrintData();
    st2.Modify();
    cout << "\n" << "수정된  st2 정보" << "\n"; 
    
    st2.PrintData();
    cout << "\n" << "st2 수정 후 st1 정보" << "\n";  
    //깊은 복사를 했으므로 학생정보는 st1과 st2가 다르게 출력되었다.
    //하지만 subject 클래스의 생성자는 얕은 복사를 하므로 st2의 과목정보를 수정하니 st1의 과목정보 또한 수정되었다.
    st1.PrintData(); 

    cout << "\n" << "st3 정보" << "\n"; 
    st3.PrintData();    
}
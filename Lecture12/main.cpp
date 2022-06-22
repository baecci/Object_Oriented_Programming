#include <iostream>
#include <string>
using namespace std;

#include "InputUtil.h"
#include "Subject.h"
#include "Student.h"



/*
                HW#9 : 객체지향방식의 성적처리프로그램#3                   
  작성자 : 배기원 2021041081         날짜 : 2022년 05월 20일   

  문제 정의 : Student class의 Subsearch 함수 테스트     

*/
void main() {
    Student std;
    std.InputData(); 
    std.PrintData();
    Subject* sub = std.SubSearch("사진학"); 
    // 과목명이  성공적으로  탐색된  경우
    // 해당  과목정보가  있는  메모리  주소를  리턴 
    
    if (sub != NULL)  {
        sub->PrintTitle(); 
        sub->PrintData();
    }
}

/*

void Data(const Student &s) { // 응용프로그램에  있는  전역함수

  cout << s.GetName() << "이  수강한  과목은  총" << s.GetSubNum() << "개로"; 
  cout << "수강한  과목의  평균평점은" << s.GetAveGPA() << "입니다.\n";

}


void main() {
  Subject sub1("컴퓨터", 3, "C");       
  Subject sub2("계산기", 2, "A"); 
  
  Subject::PrintTitle();      
  sub1.PrintData();     
  sub2.PrintData();

  Student st1("홍길동", 2013909845, 1, &sub1);      
  st1.PrintData(); 
  Data(st1); 
}

*/
/*
void main() {

  Subject sub1[2] = { Subject("컴퓨터", 3, "C"), Subject("현대무용", 2, "A") }; 
  Subject *sub2[2] = {new Subject(), new Subject("수학", 3, “C") };
  Student st1;
  Student st2("홍길동", 2013909845, 2, sub1);
  Student *st3 = new Student[2];

  cout << "\n" << "sub2[0] 입력" << "\n"; 
  sub2[0]->InputData();    
  cout << "\n" << "st1 입력" << "\n"; 
  st1.InputData();    
  cout << "\n" << "st3 입력" << "\n";
  for (int i = 0; i < 2; i++)   (st3 + i)->InputData(); 

  cout << "\n" << "sub1 정보  출력" << "\n";
  Subject::PrintTitle();
  for (int i = 0; i < 2; i++)   sub1[i].PrintData(); 
  cout << "\n" << "sub2 정보  출력" << "\n"; 
  Subject::PrintTitle();
  for (int i = 0; i < 2; i++)   sub2[i]->PrintData(); 
  cout << "\n" << "st1 정보  출력" << "\n";
  st1.PrintData();    
  cout << "\n" << "st2 정보  출력" << "\n"; 
  st2.PrintData();
  cout << "\n" << "st3 정보  출력" << "\n";
  for (int i = 0; i < 2; i++) (st3+i)->PrintData(); 

}

*/
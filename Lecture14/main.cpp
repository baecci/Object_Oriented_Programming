#include <iostream>
#include <string>
using namespace std;

#include "InputUtil.h"
#include "Subject.h"
#include "Student.h"
#include "GradeManager.h"


/*
                HW#12 : 객체지향방식의 성적처리프로그램#5             
  작성자 : 배기원 2021041081         날짜 : 2022년 06월 3일   

  문제 정의 : 가상함수와 다형성 & 추상 클래스 테스트
*/
// int main(){

//   Student std;
//   std.InputData();    

//   IOInterface* IO[2]  = {new Subject("사진학",3,"A+"), &std}; 

//   for (int i=0; i<2; i++) {
//     cout << "\n * " << i+1 << "번째  데이터  : " << "\n";
//     IO[i]->PrintData();   // 파생클래스의  멤버함수가  호출되어야  함 
//     //기본 클래스인 IOInterface에 PrintData() 가상 함수화
//   }
// }


/*
                HW#12 : 객체지향방식의 성적처리프로그램#5             
  작성자 : 배기원 2021041081         날짜 : 2022년 06월 3일   

  문제 정의 : GradeManger 클래스 테스트
*/
int main() { 
  int stdnum;
  
  cout << "학생 수를 입력하세요: "; 
  InputUtil::InputValue(stdnum); 
  cout << endl;

  /* GradeManager 클래스로 전체 프로그램 실행 */
  GradeManager GradeMgr(stdnum); 
  GradeMgr.Execute();
}
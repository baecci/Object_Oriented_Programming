#include <iostream>
#include <string>
using namespace std;

#include "InputUtil.h"
#include "Subject.h"
#include "Student.h"


/*
                HW#11 : 객체지향방식의 성적처리프로그램#4                 
  작성자 : 배기원 2021041081         날짜 : 2022년 05월 27일   

  문제 정의 : 파생 클래스 객체의 기본 클래스 생성자 호출 
*/
// int main(){
//   Student std;  //파생 클래스의 객체 생성 시 항상 기본 클래스의 생성자를 호출(상속받은 멤버 변수를 초기화하기 위함)
//   cout << std.GetData() <<"\n";  //인자있는 생성자가 있는데 기본 클래스의 디폴트 생성자를 정의하지 않으면 오류.
// }


/*
                HW#11 : 객체지향방식의 성적처리프로그램#4                 
  작성자 : 배기원 2021041081         날짜 : 2022년 05월 27일   

  문제 정의 : 기본클래스와 파생클래스의 사용
*/
int main() {
  Subject sub("컴퓨터", 3, "C");
  cout << "-----------------------------\n";
  // IOInterface Class에서  상속받은  GetData() 호출; 
  cout << "m_data : " << sub.Subject::GetData() << endl;
  // Subject Class에서  재정의된  GetName() 호츨; 
  cout << "교과목 이름 : " << sub.Subject::GetName() << endl;
  // IOInterface Class의  GetName() 호출;
  cout << "부모클래스의 이름 : " << sub.IOInterface::GetName() << endl;
  cout << "-----------------------------\n\n"; 

  Student std("홍길동", 2013909845, 1, &sub);
  cout << "-----------------------------\n";
  // IOInterface Class에서  상속받은  GetData() 호출; 
  cout << "m_data : " << std.Student::GetData() << endl;
  // Student Class에서  재정의된  GetName() 호츨; 
  cout << "학생 이름 : " << std.Student::GetName() << endl;
  // IOInterface Class의  GetName() 호출;
  cout << "부모클래스의 이름 : " << std.IOInterface::GetName() << endl;
  cout << "-----------------------------\n\n"; 
}


/*
                HW#11 : 객체지향방식의 성적처리프로그램#4                 
  작성자 : 배기원 2021041081         날짜 : 2022년 05월 27일   

  문제 정의 : Student 클래스의 Modify 멤버함수 수정
*/
// int main() {
//   Subject sub("컴퓨터", 3, "C");
//   Student std("홍길동", 20138342, 1, &sub);
//   std.PrintData();
//   std.Modify();    // Student Class의  멤버변수  값  수정
//   std.PrintData(); 
// }

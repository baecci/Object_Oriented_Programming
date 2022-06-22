#include <iostream>
#include <string>
using namespace std;

#include "Subject.h"
#include "Student.h"


/*
                HW#8 : 클래스 기초-1                   
  작성자 : 배기원 2021041081         날짜 : 2022년 05월 06일   

  문제 정의 : subject 클래스로 정의 및 테스트(다양한 형태의 객체로 과목정보 입력받고 출력)                 

*/
int main() {

    /* 일반객체, 배열객체, 포인터객체로 객체선언 */
    Subject sub1, sub2, sub3[2], *sub4; 
    int i;

    /* 일반객체, 객체배열, 객체포인터 초기화 */
    sub1.Initialize();      
    sub2.Initialize("사진학", 3, "A+"); 
    for (i = 0; i < 2; i++) sub3[i].Initialize("컴퓨터", 3, "C"); 
    sub4 = new Subject[2];
    
    /* 객체에 과목정보 입력 및 출력 */
    sub1.InputData();  
    cout << "\n" << "sub1 정보" << endl; 
    sub1.PrintTitle();          sub1.PrintData(); 

    cout << "\n" << "sub2 정보" << endl; 
    sub2.PrintTitle();          sub2.PrintData();

    cout << "\n" << "sub3 정보" << endl; 
    sub3[0].PrintTitle();
    for (i = 0; i < 2; i++) sub3[i].PrintData();

    for (i = 0; i < 2; i++) (sub4 + i)->InputData(); 
    cout << "\n" << "sub4 정보" << endl;
    sub4->PrintTitle();
    for (i = 0; i < 2; i++) (sub4 + i)->PrintData(); 
    
    /* cout << sub1.m_name;은 protected로 인해 접근 불가 */
    /* read용 접근자 함수로 문제해소 테스트 */
    cout << sub1.GetName() << endl;
    cout << sub2.GetName() << endl;
    
    for(i=0; i < 2; i++)
        cout << sub3[i].GetName() << endl;

    cout << sub4->GetName() << endl;

    /* 동적할당 해체 후 프로그램 종료 */
    delete [] sub4;
    return 0;
}


/*
                HW#8 : 클래스 기초-2                  
  작성자 : 배기원 2021041081         날짜 : 2022년 05월 10일   

  문제 정의 : student 클래스로 정의 및 테스트(다양한 형태의 객체로 학생정보 및 과목정보 입력받고 출력)                  

*/
// int main() { 
//     Subject sub[2];

//     /* Subject 클래스의 객체 초기화 */
//     sub[0].Initialize("컴퓨터", 3, "C"); 
//     sub[1].Initialize("현대무용", 2, "A");
    
//     Student st1, st2;
    
//     /* 두 Student 클래스의 객체 초기화 */
//     st1.Initialize();      
//     st2.Initialize("홍길동", 2013909845, 2, sub);
    
//     /* st1 객체의 학생정보, 과목정보 입력 */
//     st1.InputData();

//     /* 두 Student 클래스의 객체 정보 출력 */
//     cout << "\n" << "st1 정보" << "\n"; 
//     st1.PrintData();
//     cout << "\n" << "st2 정보" << "\n"; 
//     st2.PrintData();

//     /* 동적 할당 해제 후 프로그램 종료 */
//     st1.Remove(); 
//     return 0;
// }


/*
                HW#8 : 클래스 기초-3                 
  작성자 : 배기원 2021041081         날짜 : 2022년 05월 12일   

  문제 정의 : student 클래스로 friend 함수 테스트                  

*/
// void ShowData(const Student &);

// int main() {
//     Student st;

//     /* 객체 기본 초기화 후 학생정보, 과목정보 입력 */
//     st.Initialize();
//     st.InputData();

//     ShowData(st);    
// }

// void ShowData(const Student &s) { // 응용프로그램에 있는 전역함수
//     cout << s.m_name << "이 수강한 과목은 총" << s.m_subnum << "개로 ";
//     cout << "수강한 과목의 평균평점은 " << s.m_aveGPA << "입니다.\n";
// }




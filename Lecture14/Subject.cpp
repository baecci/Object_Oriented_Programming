//  Subject 클래스 멤버함수 구현부

#include <iostream>
#include <string>
using namespace std;

#include "InputUtil.h"
#include "Subject.h"
#include "Student.h"


/* 디폴트 생성자를 통한 Subject 클래스 객체의 초기화 */
Subject::Subject(){  //기본 클래스 생성자 명시적 호출
    cout << "Subject의 디폴트 생성자가 호출됨" << "\n\n";
    
    m_name = "";
    m_hakjum = 0;
    m_grade = "";
    m_GPA = 0.0;
}

/* 인자있는 생성자를 통한 Subject 클래스 객체의 초기화 */
Subject::Subject(string name, int hakjum, string grade){
    cout << "Subject의 인자있는 생성자가 호출됨" << "\n\n";

    this -> m_name = name;
    this -> m_hakjum = hakjum;
    this -> m_grade = grade;

    CalcGPA();
}

/* 복사 생성자를 통한 Subject 클래스 객체의 초기화 */
Subject::Subject(const Subject& sub){
    cout << "Subject의 복사 생성자가 호출됨" << "\n\n"; 
 
    this -> m_name = sub.m_name;  
    this -> m_hakjum = sub.m_hakjum; 
    this -> m_grade = sub.m_grade;  

    CalcGPA();
}

/* 아무것도 안하는 소멸자 */
Subject::~Subject(){
    cout << "Subject의 소멸자가 호출됨" << "\n\n"; 
    //아무일도 하지 않음
}


/* 과목정보를 입력한다. */
void Subject::InputData(){
    cout << "과목의 이름: ";
    InputUtil::InputValue(m_name);
    cout << "과목 학점수: ";
    InputUtil::InputValue(m_hakjum);
    cout << "과목 등급: ";
    InputUtil::InputValue(m_grade);
    cout << endl;
    CalcGPA();
}


/* 과목 타이틀 출력 */
void Subject::PrintTitle(){
    cout << "------------------------------------------------------------------" << endl;
    cout.width(10);
    cout << "과목명"<<"\t과목학점수"<<"\t 과목등급"<<"\t 과목평점" << endl;
    cout << "------------------------------------------------------------------" << endl;
}

/* 과목정보 출력 */
void Subject::PrintData() const{
    cout.width(10);
    cout << m_name << "\t\t" << m_hakjum << "\t\t" << m_grade << "\t\t" << m_GPA << endl;
}


/* 과목평점 계산 */
void Subject::CalcGPA(){
    if(m_grade == "A+"){
        m_GPA = 4.5*(m_hakjum);
    }
    if(m_grade == "A0" || m_grade == "A"){
        m_GPA = 4.0*(m_hakjum);
    }
    if(m_grade == "B+"){
        m_GPA=3.5*(m_hakjum);
    }
    if(m_grade == "B0" || m_grade == "B"){
        m_GPA = 3.0*(m_hakjum);
    }
    if(m_grade == "C+"){
        m_GPA = 2.5*(m_hakjum);
    }
    if(m_grade == "C0" || m_grade == "C"){
        m_GPA = 2.0*(m_hakjum);
    }
    if(m_grade == "D+"){
        m_GPA = 1.5*(m_hakjum);
    }
    if(m_grade == "D0" || m_grade == "D"){
        m_GPA = 1.0*(m_hakjum);
    }
    if(m_grade == "F"){
        m_GPA = 0.0*(m_hakjum);
    }
}


/* 과목정보(교과목명, 학점, 등급) 수정 */
void Subject::Modify(){
    cout << "\n교과목명을 수정: ";
    InputUtil::InputValue(m_name);
    cout << "학점수를 수정: ";
    InputUtil::InputValue(m_hakjum);
    cout << "과목등급을 수정: ";
    InputUtil::InputValue(m_grade);

    CalcGPA();  //수정된 정보에 따라 평점 재계산

    cout << "\n변경되었습니다." << endl;
}


/* Subject 클래스 read용 접근자 함수 정의 */
string Subject::GetName() const{
    return m_name;
}
int Subject::GetHakjum() const{
    return m_hakjum;
}
string Subject::GetGrade() const{
    return m_grade;
}
float Subject::GetGPA() const{
    return m_GPA;
}
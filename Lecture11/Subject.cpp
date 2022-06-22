//  Subject 멤버함수 구현부

#include <iostream>
#include <string>
using namespace std;

#include "Subject.h"


/* 디폴트 생성자를 통한 Subject 클래스 객체의 초기화 */
Subject::Subject(){
    cout << "\n디폴트 생성자가 호출됨!";  //생성자 호출 확인문구
    
    m_name = "";
    m_hakjum = 0;
    m_grade = "";
    m_GPA = 0.0;
}

/* 인자있는 생성자를 통한 Subject 클래스 객체의 초기화 */
Subject::Subject(string name, int hakjum, string grade){
    cout << "\n인자있는 생성자가 호출됨!";  //생성자 호출 확인문구

    this -> m_name = name;
    this -> m_hakjum = hakjum;
    this -> m_grade = grade;

    CalcGPA();
}

/* 복사 생성자를 통한 Subject 클래스 객체의 초기화 */
Subject::Subject(const Subject& sub){
    cout << "\n복사 생성자가 호출됨!";  //생성자 호출 확인문구
 
    this -> m_name = sub.m_name;  
    this -> m_hakjum = sub.m_hakjum; 
    this -> m_grade = sub.m_grade;  

    CalcGPA();
}

/* 아무것도 안하는 소멸자 */
Subject::~Subject(){
    //아무일도 하지 않음
}


/* 정수형 개별 데이터를 입력한다. */
inline void Subject::InputValue(int& x){
    cin >> x;
    cin.ignore();  //버퍼에 있는 '엔터의 개행(\n)'을 처리한다.
}  
/* 문자열 개별 데이터를 입력한다. */
inline void Subject::InputValue(string& str){
    getline(cin, str); 
}  

/* 과목정보를 입력한다. */
void Subject::InputData(){
    cout << "과목의 이름: ";
    InputValue(m_name);
    cout << "\n과목 학점수: ";
    InputValue(m_hakjum);
    cout << "\n과목 등급: ";
    InputValue(m_grade);
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
void Subject::PrintData(){
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
    InputValue(m_name);
    cout << "학점수를 수정: ";
    InputValue(m_hakjum);
    cout << "과목등급을 수정: ";
    InputValue(m_grade);

    CalcGPA();  //수정된 정보에 따라 평점 재계산

    cout << "\n변경되었습니다." << endl;
}


/* Subject 클래스 read용 접근자 함수 정의 */
string Subject::GetName(){
    return m_name;
}
int Subject::GetHakjum(){
    return m_hakjum;
}
string Subject::GetGrade(){
    return m_grade;
}
float Subject::GetGPA(){
    return m_GPA;
}
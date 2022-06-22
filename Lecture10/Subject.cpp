#include <iostream>
#include <string>
using namespace std;

#include "Subject.h"

//  Subject 멤버함수 구현부

/* Subject 클래스 객체 기본 초기화 */
void Subject::Initialize(){
    m_name = "";
    m_hakjum = 0;
    m_grade = "";
    m_GPA = 0.0;
}

/* Subject 클래스 객체의 인자를 통한 초기화 */
void Subject::Initialize(string x, int y, string z){
    m_name = x;
    m_hakjum = y;
    m_grade = z;
    CalcGPA();
}


/* 정수형 개별 데이터를 입력한다. */
inline void Subject::InputValue(int& x){
    cin>>x;
    cin.ignore();  //버퍼에 있는 '엔터의 개행(\n)'을 처리한다.
}  
/* 문자열 개별 데이터를 입력한다. */
inline void Subject::InputValue(string& str){
    getline(cin, str); 
}  

/* 과목정보를 입력한다. */
void Subject::InputData(){
    cout<<"과목의 이름: ";
    InputValue(m_name);
    cout<<"\n과목 학점수: ";
    InputValue(m_hakjum);
    cout<<"\n과목 등급: ";
    InputValue(m_grade);
    CalcGPA();
}


/* 과목 타이틀 출력 */
void Subject::PrintTitle(){
    cout<<"------------------------------------------------------------------"<<endl;
    cout.width(10);
    cout<<"과목명"<<"\t과목학점수"<<"\t 과목등급"<<"\t 과목평점"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
}

/* 과목정보 출력 */
void Subject::PrintData(){
    cout.width(10);
    cout<<m_name<<"\t\t"<<m_hakjum<<"\t\t"<<m_grade<<"\t\t"<<m_GPA<<endl;
}


/* 과목평점 계산 */
void Subject::CalcGPA(){
    if(m_grade=="A+"){
        m_GPA=4.5*(m_hakjum);
    }
    if(m_grade=="A0" || m_grade=="A"){
        m_GPA=4.0*(m_hakjum);
    }
    if(m_grade=="B+"){
        m_GPA=3.5*(m_hakjum);
    }
    if(m_grade=="B0" || m_grade=="B"){
        m_GPA=3.0*(m_hakjum);
    }
    if(m_grade=="C+"){
        m_GPA=2.5*(m_hakjum);
    }
    if(m_grade=="C0" || m_grade=="C"){
        m_GPA=2.0*(m_hakjum);
    }
    if(m_grade=="D+"){
        m_GPA=1.5*(m_hakjum);
    }
    if(m_grade=="D0" || m_grade=="D"){
        m_GPA=1.0*(m_hakjum);
    }
    if(m_grade=="F"){
        m_GPA=0.0*(m_hakjum);
    }
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
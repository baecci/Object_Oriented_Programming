//  Student 클래스 멤버함수 구현부

#include <iostream>
#include <string>
using namespace std;

#include "InputUtil.h"  
#include "Student.h"


/* 디폴트 생성자를 통한 Student 클래스 객체의 초기화 */
Student::Student(){  //기본 클래스 생성자 명시적 호출
    cout << "Student의 디폴트 생성자가 호출됨" << "\n\n"; 
    
    string m_name = "";
    int m_hakbun = 0;
    int m_subnum = 0;
    Subject* m_sub = NULL;
    float m_aveGPA = 0.0;
}

/* 인자있는 생성자를 통한 Student 클래스 객체의 초기화(깊은 복사) */
Student::Student(string name, int hakbun, int subnum, Subject* sub){
    cout << "Student의 인자있는 생성자가 호출됨" << "\n\n";

    /* m_name 깊은 복사 */
    int len = m_name.size();  
    this -> m_name = new char[len+1]; 
    this -> m_name = name; 

    m_hakbun = hakbun;
    m_subnum = subnum;

    /* m_sub 깊은 복사 */
    m_sub = new Subject[subnum]; 
    for(int i = 0; i < subnum; i++)
        m_sub[i] = sub[i];

    CalcAveGPA();  
}

/* 복사 생성자를 통한 Student 클래스 객체의 초기화(깊은 복사) */
Student::Student(const Student& std){
    cout << "Student의 복사 생성자가 호출됨" << "\n\n";  

    /* m_name 깊은 복사 */
    int len = (std.m_name).size();  
    this -> m_name = new char[len+1]; 
    this -> m_name = std.m_name;  

    this -> m_hakbun = std.m_hakbun; 
    this -> m_subnum = std.m_subnum;

    /* m_sub 깊은 복사 */ 
    m_sub = new Subject[std.m_subnum]; 
    for(int i = 0; i < std.m_subnum; i++)
        m_sub[i] = std.m_sub[i];

    CalcAveGPA();
}

/* 소멸자를 통한 동적 할당된 메모리 해제 */
Student::~Student(){
    cout << "Student의 소멸자가 호출됨" << "\n\n";  
    //아무일도 하지 않음
}


/* 학생정보 및 과목정보 입력 */
void Student::InputData(){
    cout << "학생의 이름: ";
    InputUtil::InputValue(m_name); 

    cout << "학생의 학번: ";
    InputUtil::InputValue(m_hakbun);

    cout << "학생이 수강하는 과목의 수: ";
    InputUtil::InputValue(m_subnum);
    m_sub = new Subject[m_subnum];

    for(int i = 0; i < m_subnum ;i++ ) (m_sub+i)->InputData();  

    CalcAveGPA();
}


/* 학생정보와 과목정보 출력 */
void Student::PrintData() const{
    cout << "------------------------------------------------------------------" << endl;
    cout.width(10);
    cout << "이름: " << m_name << "\t\t학번: " << m_hakbun << endl;
    m_sub->PrintTitle();
    for(int i = 0; i < m_subnum ;i++ ){
        cout.width(10);
        cout << (m_sub+i)->GetName() << "\t\t" << (m_sub+i)->GetHakjum() << "\t\t" << (m_sub+i)->GetGrade() << "\t " << (m_sub+i)->GetGPA() << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << " \t\t\t\t평균평점\t" << m_aveGPA << "\n\n";
}


/* 개인 학생의 평균 평점 계산 */
void Student::CalcAveGPA(){  
    float SumGPA = 0.0;  //GPA의 합을 저장할 실수형 변수를 선언한다.
    for(int i = 0; i < m_subnum; i++){  //주소를 이동하며 GPA들을 더해준다.
        SumGPA += (m_sub+i)->GetGPA();  
    }

    m_aveGPA = SumGPA/m_subnum;  //평균 평점의 계산 값을 저장한다.
} 


/* 과목 찾기 */
Subject* Student::SubSearch(string subname) const{
    for(int i = 0; i<m_subnum; i++){
        /* 해당 과목을 찾은 경우 과목 주소를 리턴 */
        if((m_sub+i)->GetName() == subname) 
            return m_sub+i;
    }
    /* 해당 과목을 발견하지 못하면 NULL리턴 */
    return NULL;
}


/* 정보 수정 */
void Student::Modify(){
    string modifyinfo;
    cout << "\n\n입력(학생정보/과목정보/모두) : ";
    InputUtil::InputValue(modifyinfo);
    if(modifyinfo == "학생정보"){
        /* 학생정보 수정 */
        cout << "\n학생이름을 수정: ";
        InputUtil::InputValue(m_name);
        cout << "학번을 수정: ";
        InputUtil::InputValue(m_hakbun);

        cout << "\n변경되었습니다." << endl;
    }
    if(modifyinfo == "과목정보"){
        /* 과목정보 수정 */
        string searchsub;
        Subject* foundsub;
        cout << "수정하려는 과목 이름을 입력: ";
        InputUtil::InputValue(searchsub);

        foundsub = SubSearch(searchsub);

        if(foundsub == NULL){
            cout << "\n발견하지 못했습니다." << endl;
        }
        else{
            foundsub->Modify();
            CalcAveGPA();
            cout << "\n변경되었습니다." << endl;
        }
    }
    if(modifyinfo == "모두"){
        /* 학생정보, 과목정보 수정 */
        cout << "\n학생이름을 수정: ";
        InputUtil::InputValue(m_name);
        cout << "학번을 수정: ";
        InputUtil::InputValue(m_hakbun);

        for(int i = 0; i < m_subnum; i++) (m_sub+i)->Modify();

        cout << "\n변경되었습니다." << endl;
    }
}


/* Student 클래스 read용 접근자 함수 정의 */
string Student::GetName() const{
    return m_name;
}
int Student::GetHakbun() const{
    return m_hakbun;
}
int Student::GetSubNum() const{
    return m_subnum;
}
float Student::GetAveGPA() const{
    return m_aveGPA;
}
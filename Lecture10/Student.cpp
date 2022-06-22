#include <iostream>
#include <string>
using namespace std;

#include "Student.h"



//  Student 멤버함수 구현부 

/* 학생정보 기본 초기화 */
void Student::Initialize(){
    string m_name = "";
    int m_hakbun = 0;
    int m_subnum = 0;
    Subject* m_sub = NULL;
    float m_aveGPA = 0.0;
}

/* 학생정보 인자로 초기화 */
void Student::Initialize(string x, int y, int z, Subject* tsub){
    m_name = x;
    m_hakbun = y;
    m_subnum = z;
    m_sub = tsub;  //과목 정보 초기화 

    CalcAveGPA();  //평균 평점 계산
}


/* 동적 할당 해제 */
void Student::Remove(){
    delete [] m_sub;
}


/* 위 과목정보 입력함수와 같음 */
inline void Student::InputValue(int& x){
    cin>>x;
    cin.ignore(); 
}
inline void Student::InputValue(string& str){
    getline(cin, str);
}

/* 학생정보 및 과목정보 입력 */
void Student::InputData(){
    cout << "학생의 이름: ";
    InputValue(m_name); 

    cout << "학생의 학번: ";
    InputValue(m_hakbun);

    cout << "학생이 수강하는 과목의 수: ";
    InputValue(m_subnum);
    m_sub = new Subject[m_subnum];

    for(int i = 0; i < m_subnum ;i++ ) (m_sub+i)->InputData();  

    CalcAveGPA();
}


/* 학생정보와 과목정보 출력 */
void Student::PrintData(){
    cout << "------------------------------------------------------------------" << endl;
    cout.width(10);
    cout << "이름: " << m_name << "\t\t학번: " << m_hakbun << endl;
    m_sub->PrintTitle();
    for(int i = 0; i < m_subnum ;i++ ){
        cout.width(10);
        cout << (m_sub+i)->GetName() << "\t\t" << (m_sub+i)->GetHakjum() << "\t\t" << (m_sub+i)->GetGrade() << "\t " << (m_sub+i)->GetGPA() << endl;
    }
    cout << "------------------------------------------------------------------" << endl;
    cout << "\t\t\t\t평균평점\t" << m_aveGPA;
}


/* 개인 학생의 평균 평점 계산 */
void Student::CalcAveGPA(){  
    float SumGPA=0.0;  //GPA의 합을 저장할 실수형 변수를 선언한다.
    for(int i=0; i<m_subnum; i++){  //주소를 이동하며 GPA들을 더해준다.
        SumGPA += (m_sub+i)->GetGPA();  
    }

    m_aveGPA = SumGPA/m_subnum;  //평균 평점의 계산 값을 저장한다.
} 


/* Student 클래스 read용 접근자 함수 정의 */
string Student::GetName(){
    return m_name;
}
int Student::GetHakbun(){
    return m_hakbun;
}
int Student::GetSubNum(){
    return m_subnum;
}
float Student::GetAveGPA(){
    return m_aveGPA;
}
//  Student 클래스 선언부

#include <string>
#include "Subject.h"
#include "IOInterface.h"

/* 헤더 파일 중복 오류를 막기 위한 솔루션 */
#ifndef STUDENT_H  
#define STUDENT_H

class Student : public IOInterface{  //학생정보 클래스
    protected:
        /* 멤버변수 */
        string m_name;  //학생 이름
        int m_hakbun;  //학번
        int m_subnum;  //수강과목 개수
        Subject* m_sub;  //수강과목들 정보
        float m_aveGPA;  //평균 평점
    public:
        /* 생성자 */
        Student();
        Student(string name, int hakbun, int subnum, Subject* sub);
        Student(const Student& std);

        /* 소멸자 */
        ~Student();
        
        /* 멤버함수 */
        void Remove();
        void InputData();  //IOInterface 클래스에서 상속받은 멤버함수 재정의

        static void PrintTitle();  
        void PrintData() const;  //IOInterface 클래스에서 상속받은 멤버함수 재정의
        void CalcAveGPA();
        friend void ShowData(const Student &);  

        Subject* SubSearch(string subname) const;
        void Modify(); 

        /* 접근자 함수 */
        string GetName() const;
        int GetHakbun() const;
        int GetSubNum() const;
        float GetAveGPA() const;
};

#endif
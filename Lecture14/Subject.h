//  Subject 클래스 선언부

#include <string>
#include "IOInterface.h"

/* 헤더 파일 중복 오류를 막기 위한 솔루션 */
#ifndef SUBJECT_H  
#define SUBJECT_H

class Subject : public IOInterface{  //과목정보 클래스
    protected:
        /* 멤버변수 */
        string m_name;  //과목명
        int m_hakjum;  //학점수
        string m_grade;  //과목등급
        float m_GPA;  //평점
    public:
        /* 생성자 */
        Subject();  
        Subject(string name, int hakjum, string grade);  
        Subject(const Subject& sub);  
        
        /* 소멸자 */
        ~Subject();
        
        /* 멤버함수 */
        void InputData();

        static void PrintTitle();
        void PrintData() const;
        void CalcGPA();

        void Modify();    
        
        /* 접근자 함수 */
        string GetName() const;
        int GetHakjum() const;
        string GetGrade() const;
        float GetGPA() const;
};

#endif
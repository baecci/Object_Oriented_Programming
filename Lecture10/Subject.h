#include <string>

/* 헤더 파일 중복 오류를 막기 위한 솔루션 */
#ifndef SUBJECT_H  
#define SUBJECT_H

class Subject{  //과목정보 클래스
    protected:
        /* 멤버변수 */
        string m_name;  //과목 이름
        int m_hakjum;  //학점수
        string m_grade;  //과목등급
        float m_GPA;  //평점
    public:
        /* 멤버함수 */
        void Initialize();
        void Initialize(string, int, string);
        void InputValue(int &);
        void InputValue(string &);
        void InputData();

        void PrintTitle();
        void PrintData();
        void CalcGPA();  
    public:
        /* 접근자 함수 */
        string GetName();
        int GetHakjum();
        string GetGrade();
        float GetGPA();
};

#endif
#include <string>
#include "Subject.h"

/* 헤더 파일 중복 오류를 막기 위한 솔루션 */
#ifndef STUDENT_H  
#define STUDENT_H

class Student{  //학생정보 클래스
    protected:
        /* 멤버변수 */
        string m_name;  //학생 이름
        int m_hakbun;  //학번
        int m_subnum;  //수강과목 개수
        Subject* m_sub;  //수강과목들 정보
        float m_aveGPA;  //평균 평점
    public:
        /* 멤버함수 */
        void Initialize();
        void Initialize(string, int, int, Subject*);

        void Remove();
        void InputValue(int &);
        void InputValue(string &);
        void InputData();

        void PrintData();
        void CalcAveGPA();

        friend void ShowData(const Student &);  //friend 함수
    public:
        /* 접근자 함수 */
        string GetName();
        int GetHakbun();
        int GetSubNum();
        float GetAveGPA();
};

#endif
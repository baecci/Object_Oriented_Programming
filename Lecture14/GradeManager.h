//  GradeManger 클래스 선언부


#include <string>
#include "Student.h"

#ifndef GRADEMANAGER_H  
#define GRADEMANAGER_H

class GradeManager{  // 클래스
    protected:
        /* 멤버변수 */
        Student* m_std;  //전체 학생의 정보 객체
        int m_stdnum;  //전체 학생 수 

        /* protected 멤버 함수 */ 
        static void PrintMenu();  //메뉴 출력
        Student* StdSearch(string stdname) const;  //원하는 학생 검색
        void PrintAllStdList() const;  //전체 학생 목록 출력  
        void Modify();  //원하는 학생의 정보 수정
    public:
        /* 생성자 */
        GradeManager();  
        GradeManager(int m_stdnum);    
        
        /* 소멸자 */
        ~GradeManager();
        
        /* public 멤버함수 */
        void Execute();  //학생 성적 관리
};

#endif
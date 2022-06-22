//  GradeManger 클래스 멤버함수 구현부


#include <iostream>
#include <string>
using namespace std;

#include "GradeManager.h"
#include "Student.h"

GradeManager::GradeManager(){
    Student* m_std = NULL;
    int m_stdnum = 0;
}
GradeManager::GradeManager(int m_stdnum){
    this -> m_stdnum = m_stdnum;
    m_std = new Student[m_stdnum];
}

GradeManager::~GradeManager(){
    delete[] m_std;
}

void GradeManager::PrintMenu(){
    cout << endl;
    cout << "====== 메뉴 ======" << endl;
    cout << "1. 학생  성적  입력" << endl;
    cout << "2. 전체  성적  보기" << endl;
    cout << "3. 학생  검색" << endl;
    cout << "4. 학생  목록  보기" << endl;
    cout << "5. 학생  정보  수정" << endl;
    cout << "6. 프로그램  종료" << endl;
    cout << endl;
    cout << "원하는 기능을 입력하세요(번호입력): ";
}

void GradeManager::Execute(){
    while(true){
        PrintMenu();
        int command;
        InputUtil::InputValue(command);
        if(command == 1){ //학생 정보 입력
            for(int i = 0; i<m_stdnum; i++){
                cout << i+1 << "번째 학생의 정보를 입력하세요." << endl;
                m_std[i].InputData();
            }
        }
        if(command == 2){  // 학생 정보 출력
            for(int i = 0; i<m_stdnum; i++){
                m_std[i].PrintData();
            }
        }
        if(command == 3){  // 학생 이름으로 검색 후 정보 출력
            string searchstdname;
            cout << "찾을 학생의 이름을 압력하세요: ";
            InputUtil::InputValue(searchstdname);
            
            Student* std = StdSearch(searchstdname);

            if(std == NULL){
                cout << "\n찾으시는 학생이 없습니다." << endl;
                continue;
            }
            else
                std->PrintData();
        }
        if(command == 4){  // 전체 학생 리스트 출력
            PrintAllStdList();
        }
        if(command == 5){  // 검색한 학생의 정보 수정
            Modify();
        }
        if(command == 6){  // 프로그램 종료
            cout << "\n프로그램을 종료합니다." << endl;
            break;
        }
        else cout << "\n존재하지 않는 커맨드입니다." << endl;
    }
}

Student* GradeManager::StdSearch(string stdname) const{
    for(int i = 0; i<m_stdnum; i++){
        /* 발견에 성공시 해당 학생클래스 객체의 주소 리턴 */
        if(stdname == m_std[i].GetName()){
            return &m_std[i];
        }
    }
    /* 학생을 발견하지 못하면 NULL리턴 */
    return NULL;
}

void GradeManager::PrintAllStdList() const{
    cout << "----------------------------------" << endl;
    for(int i = 0; i<m_stdnum; i++){
        cout.width(10);
        cout << m_std[i].GetName() << "\t" << m_std[i].GetHakbun() << endl;
    }
    cout << "----------------------------------" << endl;
} 

void GradeManager::Modify(){
    string searchname;
    cout << "수정할 학생의 이름을 입력하세요: ";
    InputUtil::InputValue(searchname);

    Student* foundstd = StdSearch(searchname);

    /* 해당 핵생을 찾지 못하면 오류 문구 출력 */
    if(foundstd == NULL){
        cout << "\n찾으시는 학생이 없습니다." << endl;
    }
    /* 학생을 찾았다면 Student클래스의 Modify함수 호출 */
    else foundstd->Modify();
}
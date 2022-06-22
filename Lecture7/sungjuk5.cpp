/*
#include <cstring>:  c  style 문자열
#include <string> : c++ style 문자열
*/

#include <iostream>
#include <string>
using namespace std;

/*
                HW#6 : 문자열                    
  작성자 : 배기원 2021041081         날짜 : 2022년 04월 15일   

  문제 정의 : 성적처리프로그램#5(문자열string을 사용해서 sungjuk4.cpp를 개선)                            

*/

struct Subject{  //과목정보를 위한 구조체.
    string subName;
    int Hakjum;
    string Grade;
    float GPA;
};

struct Student{  //학생정보를 위한 구조체.
    string stName;
    int Hakbun;
    Subject *Sub;
    int SubNum;
    float AveGPA;
};

int StdNum;  //학생 수와 과목 수를 입력 받을 정수형 변수.
struct Student *st;  //Student 타입 구조체 배열 선언.

inline void PrintMenu();  
inline void InputValue(string& str);  
inline void InputValue(int &x);
void CalcGPA(Subject& Sub); 
float CalcAveGPA(Subject *Sub, int SubjectNum);
void InputData(Student *pSt, int StudentNum); 
void PrintAllData(const Student* pSt, int StudentNum);   
void PrintAllStdList(Student *pSt, int StudentNum);    
void PrintOneData(const Student& rSt);  
Student* StdSearch(Student* pSt, int StudentNum);  
Subject* SubSearch(const Student *pSt);
void ModifyStdInfo(Student *pSt);  

int main(){   
    while(1){  //메뉴->기능->메뉴 무한반복.
        PrintMenu();  
        int m;  
        InputValue(m);  //메뉴에서 기능 선택하기.
        if(m==1){  //1번 기능.
            cout<<"전체 학생 수를 입력하세요: ";
            InputValue(StdNum);
            st = new Student[StdNum];  //Student 타입 구조체 변수에 StdNum만큼 동적 메모리를 할당한다.
            InputData(st, StdNum);  //학생의 여러 정보 입력을 위해 함수를 호출한다.
        }
        if(m==2){  //2번 기능
            PrintAllData(st,StdNum);  //구조체 배열 st의 주소와 학생 수를 인자로 넘겨준다.
        }
        if(m==3){  //3번 기능
            Student* FindName;  //찾은 학생 정보의 주소를 저장할 구조체 포인터이다.
            FindName = StdSearch(st,StdNum);  //구조체 배열 st의 주소와 학생 수를 인자로 넘겨준다.
            if(FindName != NULL) PrintOneData(*FindName);  //학생 정보를 찾았으면, 찾은 학생의 정보의 값을 넘겨준다.
            else cout<<"해당 학생의 정보를 찾을 수 없습니다.\n";
        }
        if(m==4){  //4번 기능
            PrintAllStdList(st, StdNum);
        }
        if(m==5){  //5번 기능
            ModifyStdInfo(st);
        }
        if(m==6){  //6번 기능
            delete[] st;  //동적 메모리를 해제한 후, 프로그램을 종료한다.
            for(int i=0;i<StdNum;i++) delete[] st[i].Sub;

            return 0;
        }
    }
}


inline void PrintMenu(){
    cout<<"\n[ㅡㅡㅡㅡㅡㅡ메뉴ㅡㅡㅡㅡㅡㅡ]\n";
    cout<<" 1. 학생 성적 입력하기\n";
    cout<<" 2. 전체 학생 성적 확인하기\n";
    cout<<" 3. 학생의 이름 검색하기\n";
    cout<<" 4. 전체 학생 목록 보기\n";
    cout<<" 5. 학생 정보 수정하기\n";
    cout<<" 6. 프로그램 종료하기\n";
    cout<<"\n원하시는 메뉴를 입력하세요: ";
} //인라인 함수로 메뉴를 더 효율적이게 출력한다.


inline void InputValue(string& str){
    getline(cin, str); 
} //문자열 개별 데이터를 입력한다. (학생 이름, 과목명, 과목등급)


inline void InputValue(int &x){
    cin>>x;
    cin.ignore();  //버퍼에 있는 '엔터의 개행(\n)'을 처리한다.
} //정수형 개별 데이터를 입력한다. (메뉴 번호, 학생 수, 과목 수, 학번, 학점)


void CalcGPA(Subject& Sub){  //과목등급을 점수로 변환하고, 레퍼런스로 참조하여 GPA를 계산한다.
    if(Sub.Grade=="A+"){
        Sub.GPA=4.5*(Sub.Hakjum);
    }
    if(Sub.Grade=="A0"){
        Sub.GPA=4.0*(Sub.Hakjum);
    }
    if(Sub.Grade=="B+"){
        Sub.GPA=3.5*(Sub.Hakjum);
    }
    if(Sub.Grade=="B0"){
        Sub.GPA=3.0*(Sub.Hakjum);
    }
    if(Sub.Grade=="C+"){
        Sub.GPA=2.5*(Sub.Hakjum);
    }
    if(Sub.Grade=="C0"){
        Sub.GPA=2.0*(Sub.Hakjum);
    }
    if(Sub.Grade=="D+"){
        Sub.GPA=1.5*(Sub.Hakjum);
    }
    if(Sub.Grade=="D0"){
        Sub.GPA=1.0*(Sub.Hakjum);
    }
    if(Sub.Grade=="F"){
        Sub.GPA=0.0*(Sub.Hakjum);
    }
} //각 교과목 평점을 계산한다.


float CalcAveGPA(Subject *Sub, int SubjectNum){  
    float SumGPA=0.0;  //GPA의 합을 저장할 실수형 변수를 선언한다.
    for(int i=0; i<SubjectNum; i++){  //구조체 주소를 이동하며 GPA들을 더해준다.
        SumGPA += (Sub+i)->GPA;  
    }

    float SumHakjum=0.0;  //학점의 합을 저장할 실수형 변수를 선언한다.
    for(int j=0;j<SubjectNum;j++){  //구조체 주소를 이동하며 학점들을 더해준다.
        SumHakjum += (Sub+j)->Hakjum;
    }

    float R = SumGPA/SumHakjum;  //R변수에 평균 평점의 계산 값을 저장한다.
    return R;
} //개인 학생의 교과목 평균평점을 계산한다. (각 교과목 평점을 모두 계산 후 한 번에 평균계산)


void InputData(Student *pSt, int StudentNum){
    int i;  
    for(i=0; i<StudentNum; i++){  //각 학생 신상 입력하기. 
        cout<<"\n\n"<<i+1<<"번 학생의 이름과 학번을 입력하세요.";
        cout<<"\n이름: ";
        InputValue(pSt[i].stName);
        cout<<"학번: ";
        InputValue(pSt[i].Hakbun);
        cout<<"\n"<<i+1<<"번 학생이 수강한 과목의 수를 입력하세요: ";
        InputValue(pSt[i].SubNum);
        pSt[i].Sub = new Subject[pSt[i].SubNum];
        cout<<"\n\n학생이 수강한 과목 "<<pSt[i].SubNum<<"개의 과목명, 과목학점수, 과목등급을 입력하세요.";
        int j;
        for(j=0; j<pSt[i].SubNum; j++){  //학생의 과목 정보 입력하기.
            cout<<"\n\n과목명: ";
            InputValue(pSt[i].Sub[j].subName);
            cout<<"과목학점수: ";
            InputValue(pSt[i].Sub[j].Hakjum);
            cout<<"과목등급(A+ ~ F): ";
            InputValue(pSt[i].Sub[j].Grade);
            CalcGPA(pSt[i].Sub[j]);  //학생의 과목 주소를 인자로 넘겨준다.
        }
        pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum);  //평균 평점을 계산해서 각 학생 구조체에 저장한다.
    }
} //학생의 신상 및 성적 정보를 입력한다.


void PrintAllData(const Student *pSt, int StudentNum){ //Student형 포인터가 가리키는 주소 내의 값이 고정됐으므로 읽기 전용이다.
    cout<<"\n"<<"                  [전체 학생의 성적 보기]\n";
    cout<<"--------------------------------------------------------------\n";
    for(int i=0; i<StudentNum; i++){
        cout.width(10);
        cout<<"이름: "<<pSt[i].stName<<"\t학번: "<<pSt[i].Hakbun;  //주소를 이동하며 차례로 학생 정보를 출력한다.
        cout<<"\n--------------------------------------------------------------\n";
        cout.width(10);
        cout<<"과목명"<<"\t과목학점수"<<"\t과목등급"<<"\t과목평점";
        cout<<"\n--------------------------------------------------------------\n";
        for(int j=0;j<st[i].SubNum;j++){  //마찬가지로 구조체의 주소를 이동해주며 각 과목의 정보를 출력한다. 
            cout.width(10);
            cout<<pSt[i].Sub[j].subName<<"\t\t"<<pSt[i].Sub[j].Hakjum<<"\t\t"<<pSt[i].Sub[j].Grade<<"\t\t"<<pSt[i].Sub[j].GPA<<"\n";
        }   
        cout<<"--------------------------------------------------------------\n"; 
        cout.width(10);
        cout<<"\t\t\t\t\t\t평균평점= "<<(pSt+i)->AveGPA<<"\n\n";
    }
} //전체 학생 신상&성적 정보를 출력한다.


void PrintAllStdList(Student *pSt, int StudentNum){
    cout<<"\n------------------------------\n";
    cout.width(10);
    cout<<"학번 "<<"\t이름 ";
    cout<<"\n------------------------------\n";
    for(int i = 0; i < StudentNum; i++){
        cout.width(10);
        cout<<(pSt + i)->Hakbun<<"\t"<<(pSt + i)->stName<<"\n";
    }
    cout<<"------------------------------\n";
} //전체 학생의 학번과 이름의 리스트를 출력한다.


void PrintOneData(const Student& rSt){  //read only reference rSt로 검색한 학생 정보 출력  
    cout.width(10);
    cout<<"\n이름: "<<rSt.stName<<"\t학번: "<<rSt.Hakbun;  //레퍼런스로 참조하여 출력해준다.
    cout<<"\n--------------------------------------------------------------\n";
    cout.width(10);
    cout<<"과목명"<<"\t과목학점수"<<"\t과목등급"<<"\t과목평점";
    cout<<"\n--------------------------------------------------------------\n";
    for(int i=0;i<rSt.SubNum;i++){  //마찬가지로 레퍼런스로 참조하여 각 과목의 정보를 출력한다.
        cout.width(10);
        cout<<rSt.Sub[i].subName<<"\t\t"<<rSt.Sub[i].Hakjum<<"\t"<<rSt.Sub[i].Grade<<"\t\t"<<rSt.Sub[i].GPA<<"\n";
    } 
    cout<<"--------------------------------------------------------------\n"; 
        cout.width(10);
        cout<<"\t\t\t\t\t\t평균평점= "<<rSt.AveGPA<<"\n\n";    
} //개인 학생의 신상&성적 정보를 출력한다.


Student* StdSearch(Student* pSt, int StudentNum){
    string SearchName;  //찾을 이름을 입력받을 문자열 변수를 선언한다.
    cout<<"검색 할 학생의 이름을 입력하세요: ";
    InputValue(SearchName);
    for(int i = 0 ; i<StudentNum ; i++){  //학생들의 이름을 문자열비교함수로 비교하여 검색한 이름이 있으면(함수 리턴 값이 0이면) 해당 학생의 인덱스 주소를 리턴한다.
        if((pSt+i)->stName == SearchName) return &st[i];  
    }
    return NULL;  //발견하지 못했다면 NULL을 리턴해 찾지 못했다는 것을 알린다.
} //학생 이름 검색 후 해당 학생의 정보가 있는 곳의 주소를 리턴한다.



Subject* SubSearch(const Student *pSt, int SubjectNum){
    string SearchName;  //찾을 과목의 이름을 받을 변수를 선언 해준다.
    cout<<"\n수정할 과목명을 입력하세요: ";
    InputValue(SearchName);
    for(int i = 0 ; i<SubjectNum ; i++){  //과목의 이름을 문자열 비교로 찾고 발견시 해당 문자열 주소를 리턴한다.
        if(pSt->Sub[i].subName == SearchName) return pSt->Sub+i; 
    }
    return NULL; 
} 



void ModifyStdInfo(Student *pSt){
    pSt = StdSearch(st,StdNum);  //StdSearch함수를 호출해 학생을 찾고, 해당 학생의 데이터 주소를 pSt에 저장한다.
    if(pSt != NULL){
        cout<<"수정(학생정보 / 과목정보): ";
        string Info;
        InputValue(Info);  //문자열 비교로 학생정보/과목정보 수정 선택 후 입력받은 정보로 변경한다.
        if(Info == "학생정보"){
            cout<<"\n["<<pSt->stName<<" "<<pSt->Hakbun<<"]의 정보를 수정하세요.\n\n";  //데이터를 수정한다.
            cout<<"이름 수정: ";
            InputValue(pSt->stName);
            cout<<"학번 수정: ";
            InputValue(pSt->Hakbun);
            cout<<"\n변경되었습니다.\n"; 
        } 
        else if(Info == "과목정보"){
            Subject *pSj = SubSearch(pSt, pSt->SubNum);
            if(pSj != NULL) {
                cout<<"\n["<<"과목명: "<<pSj->subName<<" / "<<"학점수: "<<pSj->Hakjum<<" / "<<"등급: "<<pSj->Grade<<"]의 정보를 수정하세요.\n\n";
                cout<<"과목명 수정: ";
                InputValue(pSj->subName);
                cout<<"과목학점수 수정: ";
                InputValue(pSj->Hakjum);
                cout<<"과목등급 수정: ";
                InputValue(pSj->Grade);
                CalcGPA(*pSj);
                cout<<"\n변경되었습니다.\n"; 
            }
            else cout<<"해당 과목의 정보를 찾을 수 없습니다.\n"; 
        }
    }
    else cout<<"\n해당 학생의 정보를 찾을 수 없습니다.\n";  //학생을 찾지 못한 경우 오류문구를 출력한다.
} //검색한 학생의 신상 정보를 수정한다.
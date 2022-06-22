/*
    객체지향프로그래밍 성적처리프로그램#2
    
    담당교수: 최경주 교수님 / TA: 유현진, 김주희 선배님

    배기원 2021041081                  
*/  

#include <iostream>
#include <string.h>
using namespace std;      
#define StdNum 2  //학생 수.
#define SubNum 3  //교과목 수.

struct Subject{  //과목정보를 위한 구조체.
    char subName[30];
    int Hakjum;
    string Grade;
    float GPA;
};
struct Student{  //학생정보를 위한 구조체.
    char stName[30];
    int Hakbun;
    Subject Sub[3];
    float AveGPA;
};
Student st[StdNum];  //Student 타입 구조체 배열 선언.

void PrintMenu();  //메뉴를 출력한다.
void CalcGPA(Subject& Sub); //각 교과목 평점을 계산한다.
float CalcAveGPA(Subject* Sub);  //개인 학생의 각 교과목 평점평균을 계산한다.
void PrintAllData(const Student* pSt, int StudentNum);  //전체 학생 신상&성적 정보 출력한다.
void PrintOneData(const Student& rSt);  //개인 학생 신상&성적 정보를 출력한다.
Student* StdSearch(Student* pSt, int StudentNum);  //학생 이름 검색 후 해당 학생의 정보가 있는 곳의 주소를 리턴한다.

int main(){   
    while(1){  //메뉴->기능->메뉴 무한반복.
        PrintMenu();  
        int m;  
        cin>>m;  //메뉴에서 기능 선택하기.
        if(m==1){  //1번 기능.
            int i;
            for(i=0;i<StdNum;i++){  //각 학생 신상 입력하기. 
                cout<<"\n\n"<<i+1<<"번 학생의 이름과 학번을 입력하세요.";
                cout<<"\n이름: ";
                cin>>st[i].stName;
                cout<<"학번: ";
                cin>>st[i].Hakbun;
                cout<<"\n\n학생이 수강한 과목 3개의 과목명, 과목학점수, 과목등급을 입력하세요.";
                int j;
                for(j=0;j<SubNum;j++){  //학생의 과목 정보 입력하기.
                    cout<<"\n\n과목명: ";
                    cin>>st[i].Sub[j].subName;
                    cout<<"과목학점수: ";
                    cin>>st[i].Sub[j].Hakjum;
                    cout<<"과목등급(A+ ~ F): ";
                    cin>>st[i].Sub[j].Grade;
                    CalcGPA(st[i].Sub[j]);  //학생의 과목 주소를 인자로 넘겨준다.
                }
                st[i].AveGPA=CalcAveGPA(st[i].Sub);  //평균 평점을 계산해서 각 학생 구조체에 저장한다.
            }
        }
        if(m==2){  //2번 기능
            PrintAllData(st,StdNum);  //구조체 배열 st의 주소와 학생 수를 인자로 넘겨준다.
        }
        if(m==3){  //3번 기능
            Student* FindName;  //찾은 학생 정보의 주소를 저장할 구조체 포인터이다.
            FindName=StdSearch(st,StdNum);  //구조체 배열 st의 주소와 학생 수를 인자로 넘겨준다.
            if(FindName != NULL) PrintOneData(*FindName);  //학생 정보를 찾았으면, 찾은 학생의 정보의 값을 넘겨준다.
            else cout<<"해당 학생의 정보를 찾을 수 없습니다.";
        }
        if(m==4){  //4번 기능
            return 0;
        }
    }
}

void PrintMenu(){
    cout<<"\n[ㅡㅡㅡㅡㅡㅡ메뉴ㅡㅡㅡㅡㅡㅡ]\n";
    cout<<" 1. 학생 성적 입력하기\n";
    cout<<" 2. 전체 학생 성적 확인하기\n";
    cout<<" 3. 학생의 이름 검색하기\n";
    cout<<" 4. 프로그램 종료하기\n";
    cout<<"\n 원하시는 메뉴를 입력하세요: ";
} //메뉴 출력

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
} //각 교과목의 평점 계산

float CalcAveGPA(Subject* Sub){  
    float SumGPA=0.0;  //GPA의 합을 저장할 실수형 변수를 선언한다.
    for(int i=0;i<SubNum;i++){  //구조체 주소를 이동하며 GPA들을 더해준다.
        SumGPA += (Sub+i)->GPA;  
    }

    float SumHakjum=0.0;  //학점의 합을 저장할 실수형 변수를 선언한다.
    for(int j=0;j<SubNum;j++){  //구조체 주소를 이동하며 학점들을 더해준다.
        SumHakjum += (Sub+j)->Hakjum;
    }

    float R=SumGPA/SumHakjum;  //R변수에 평균 평점의 계산 값을 저장한다.
    return R;
} //개인 학생의 평균 평점 계산(각 교과목 평점을 모두 계산 후 한 번에 평균계산)

void PrintAllData(const Student* pSt, int StudentNum){ //Student형 포인터가 가리키는 주소 내의 값이 고정됐으므로 읽기 전용이다.
    cout<<"\n"<<"                   전체 학생의 성적 보기\n";
    cout<<"==============================================================\n";
    for(int i=0;i<StudentNum;i++){
        cout.width(10);
        cout<<"이름: "<<(pSt+i)->stName<<"\t학번: "<<(pSt+i)->Hakbun;  //주소를 이동하며 차례로 학생 정보를 출력한다.
        cout<<"\n--------------------------------------------------------------\n";
        cout.width(10);
        cout<<"과목명"<<"\t과목학점수"<<"\t과목등급"<<"\t과목평점";
        cout<<"\n--------------------------------------------------------------\n";
        for(int j=0;j<SubNum;j++){  //마찬가지로 구조체의 주소를 이동해주며 각 과목의 정보를 출력한다. 
            cout.width(10);
            cout<<(pSt+i)->Sub[j].subName<<"\t\t"<<(pSt+i)->Sub[j].Hakjum<<"\t\t"<<(pSt+i)->Sub[j].Grade<<"\t\t"<<(pSt+i)->Sub[j].GPA<<"\n";
        }   
        cout<<"--------------------------------------------------------------\n"; 
        cout.width(10);
        cout<<"\t\t\t\t\t\t평균평점= "<<(pSt+i)->AveGPA<<"\n\n";
    }
} //전체 학생 신상&성적 정보 출력

void PrintOneData(const Student& rSt){  //read only reference rSt로 검색한 학생 정보 출력  
    cout.width(10);
    cout<<"\n이름: "<<rSt.stName<<"\t학번: "<<rSt.Hakbun;  //레퍼런스로 참조하여 출력해준다.
    cout<<"\n--------------------------------------------------------------\n";
    cout.width(10);
    cout<<"과목명"<<"\t과목학점수"<<"\t과목등급"<<"\t과목평점";
    cout<<"\n--------------------------------------------------------------\n";
    for(int i=0;i<SubNum;i++){  //마찬가지로 레퍼런스로 참조하여 각 과목의 정보를 출력한다.
        cout.width(10);
        cout<<rSt.Sub[i].subName<<"\t\t"<<rSt.Sub[i].Hakjum<<"\t"<<rSt.Sub[i].Grade<<"\t\t"<<rSt.Sub[i].GPA<<"\n";
    } 
    cout<<"--------------------------------------------------------------\n"; 
        cout.width(10);
        cout<<"\t\t\t\t\t\t평균평점= "<<rSt.AveGPA<<"\n\n";    
} //개인 학생 신상&성적 정보 출력

Student* StdSearch(Student* pSt, int StudentNum){
    char SearchName[30];  //찾을 이름을 입력받을 문자열 변수를 선언한다.
    cout<<"검색 할 학생의 이름을 입력하세요: ";
    cin>>SearchName;
    for(int i=0;i<StudentNum;i++){  //학생들의 이름을 문자열비교함수로 비교하여 검색한 이름이 있으면(함수 리턴 값이 0이면) 해당 학생의 인덱스 주소를 리턴한다.
        if(strcmp((pSt+i)->stName,SearchName)==0) return &st[i];  
    }
    return NULL;  //발견하지 못했다면 NULL을 리턴해 찾지 못했다는 것을 알린다.
} //학생 이름 검색 후 해당 학생의 정보가 있는 곳의 주소를 리턴
#include <iostream>
#include <cstring>
using namespace std;

/*
                HW#5 : ���� �Ҵ�                    
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 04�� 08��   

  ���� ���� : ����ó�����α׷�#4(���� �޸𸮸� ����ؼ� #3�� ����)                            

*/

struct Subject{  //���������� ���� ����ü.
    char subName[30];
    int Hakjum;
    char Grade[10];
    float GPA;
};
struct Student{  //�л������� ���� ����ü.
    char stName[30];
    int Hakbun;
    Subject *Sub;
    int SubNum;
    float AveGPA;
};
int StdNum;  //�л� ���� ���� ���� �Է� ���� ������ ����.
Student *st;  //Student Ÿ�� ����ü �迭 ����.

inline void PrintMenu();  
inline void InputValue(char *str);  
inline void InputValue(int &x);
void InputData(Student *pSt, int StudentNum);  
void PrintAllStdList(Student *pSt, int StudentNum);  
void CalcGPA(Subject& Sub); 
float CalcAveGPA(Subject *Sub, int SubjectNum);  
void PrintAllData(const Student* pSt, int StudentNum);  
void PrintOneData(const Student& rSt);  
Student* StdSearch(Student* pSt, int StudentNum);  
void ModifyStdInfo(Student *pSt);  

int main(){   
    while(1){  //�޴�->���->�޴� ���ѹݺ�.
        PrintMenu();  
        int m;  
        InputValue(m);  //�޴����� ��� �����ϱ�.
        if(m==1){  //1�� ���.
            cout<<" ��ü �л� ���� �Է��ϼ���: ";
            st = new Student[StdNum];  //Student Ÿ�� ����ü ������ StdNum��ŭ ���� �޸𸮸� �Ҵ��Ѵ�.
            InputValue(StdNum);
            InputData(st, StdNum);  //�л��� ���� ���� �Է��� ���� �Լ��� ȣ���Ѵ�.
        }
        if(m==2){  //2�� ���
            PrintAllData(st,StdNum);  //����ü �迭 st�� �ּҿ� �л� ���� ���ڷ� �Ѱ��ش�.
        }
        if(m==3){  //3�� ���
            Student* FindName;  //ã�� �л� ������ �ּҸ� ������ ����ü �������̴�.
            FindName = StdSearch(st,StdNum);  //����ü �迭 st�� �ּҿ� �л� ���� ���ڷ� �Ѱ��ش�.
            if(FindName != NULL) PrintOneData(*FindName);  //�л� ������ ã������, ã�� �л��� ������ ���� �Ѱ��ش�.
            else cout<<"�ش� �л��� ������ ã�� �� �����ϴ�.\n";
        }
        if(m==4){  //4�� ���
            PrintAllStdList(st, StdNum);
        }
        if(m==5){  //5�� ���
            ModifyStdInfo(st);
        }
        if(m==6){  //6�� ���
            delete[] st;  //���� �޸𸮸� ������ ��, ���α׷��� �����Ѵ�.
            return 0;
        }
    }
}


inline void PrintMenu(){
    cout<<"\n[�ѤѤѤѤѤѸ޴��ѤѤѤѤѤ�]\n";
    cout<<" 1. �л� ���� �Է��ϱ�\n";
    cout<<" 2. ��ü �л� ���� Ȯ���ϱ�\n";
    cout<<" 3. �л��� �̸� �˻��ϱ�\n";
    cout<<" 4. ��ü �л� ��� ����\n";
    cout<<" 5. �л� ���� �����ϱ�\n";
    cout<<" 6. ���α׷� �����ϱ�\n";
    cout<<"\n ���Ͻô� �޴��� �Է��ϼ���: ";
} //�ζ��� �Լ��� �޴��� �� ȿ�����̰� ����Ѵ�.


inline void InputValue(char *str){  
    cin>>str;
} //���ڿ� ���� �����͸� �Է��Ѵ�. (�л� �̸�, �����, ������)


inline void InputValue(int &x){
    cin>>x;
} //������ ���� �����͸� �Է��Ѵ�. (�޴� ��ȣ, �л� ��, ���� ��, �й�, ����)


void InputData(Student *pSt, int StudentNum){
    int i;  
    for(i=0; i<StudentNum; i++){  //�� �л� �Ż� �Է��ϱ�. 
        cout<<"\n\n"<<i+1<<"�� �л��� �̸��� �й��� �Է��ϼ���.";
        cout<<"\n�̸�: ";
        InputValue(pSt[i].stName);
        cout<<"�й�: ";
        InputValue(pSt[i].Hakbun);
        cout<<"\n"<<i+1<<"�� �л��� ������ ������ ���� �Է��ϼ���: ";
        InputValue(pSt[i].SubNum);
        pSt[i].Sub = new Subject[pSt[i].SubNum];
        cout<<"\n\n�л��� ������ ���� "<<pSt[i].SubNum<<"���� �����, ����������, �������� �Է��ϼ���.";
        int j;
        for(j=0; j<pSt[i].SubNum; j++){  //�л��� ���� ���� �Է��ϱ�.
            cout<<"\n\n�����: ";
            InputValue(pSt[i].Sub[j].subName);
            cout<<"����������: ";
            InputValue(pSt[i].Sub[j].Hakjum);
            cout<<"������(A+ ~ F): ";
            InputValue(pSt[i].Sub[j].Grade);
            CalcGPA(pSt[i].Sub[j]);  //�л��� ���� �ּҸ� ���ڷ� �Ѱ��ش�.
        }
        pSt[i].AveGPA = CalcAveGPA(pSt[i].Sub, pSt[i].SubNum);  //��� ������ ����ؼ� �� �л� ����ü�� �����Ѵ�.
    }
} //�л��� �Ż� �� ���� ������ �Է��Ѵ�.


void PrintAllStdList(Student *pSt, int StudentNum){
    cout<<"\n--------------------------------\n";
    cout.width(10);
    cout<<"�й� "<<"\t�̸� ";
    cout<<"\n--------------------------------\n";
    for(int i = 0; i < StudentNum; i++){
        cout.width(10);
        cout<<(pSt + i)->Hakbun<<"\t"<<(pSt + i)->stName<<"\n";
    }
    cout<<"--------------------------------\n";
} //��ü �л��� �й��� �̸��� ����Ʈ�� ����Ѵ�.


void CalcGPA(Subject& Sub){  //�������� ������ ��ȯ�ϰ�, ���۷����� �����Ͽ� GPA�� ����Ѵ�.
    if(Sub.Grade[0]=='A'){
        if(Sub.Grade[1]=='+') Sub.GPA=4.5*(Sub.Hakjum);
        else if(Sub.Grade[1]=='0') Sub.GPA=4.0*(Sub.Hakjum);
    }
    if(Sub.Grade[0]=='B'){
        if(Sub.Grade[1]=='+') Sub.GPA=3.5*(Sub.Hakjum);
        else if(Sub.Grade[1]=='0') Sub.GPA=3.0*(Sub.Hakjum);
    }
    if(Sub.Grade[0]=='C'){
        if(Sub.Grade[1]=='+') Sub.GPA=2.5*(Sub.Hakjum);
        else if(Sub.Grade[1]=='0') Sub.GPA=2.0*(Sub.Hakjum);
    }
    if(Sub.Grade[0]=='D'){
        if(Sub.Grade[1]=='+') Sub.GPA=1.5*(Sub.Hakjum);
        else if(Sub.Grade[1]=='0') Sub.GPA=1.0*(Sub.Hakjum);
    }
    if(Sub.Grade[0]=='F'){
        Sub.GPA=0.0*(Sub.Hakjum);
    }
} //�� ������ ������ ����Ѵ�.


float CalcAveGPA(Subject *Sub, int SubjectNum){  
    float SumGPA=0.0;  //GPA�� ���� ������ �Ǽ��� ������ �����Ѵ�.
    for(int i=0; i<SubjectNum; i++){  //����ü �ּҸ� �̵��ϸ� GPA���� �����ش�.
        SumGPA += (Sub+i)->GPA;  
    }

    float SumHakjum=0.0;  //������ ���� ������ �Ǽ��� ������ �����Ѵ�.
    for(int j=0;j<SubjectNum;j++){  //����ü �ּҸ� �̵��ϸ� �������� �����ش�.
        SumHakjum += (Sub+j)->Hakjum;
    }

    float R = SumGPA/SumHakjum;  //R������ ��� ������ ��� ���� �����Ѵ�.
    return R;
} //���� �л��� ������ ��������� ����Ѵ�. (�� ������ ������ ��� ��� �� �� ���� ��հ��)


void PrintAllData(const Student *pSt, int StudentNum){ //Student�� �����Ͱ� ����Ű�� �ּ� ���� ���� ���������Ƿ� �б� �����̴�.
    cout<<"\n"<<"                  [��ü �л��� ���� ����]\n";
    cout<<"--------------------------------------------------------------\n";
    for(int i=0; i<StudentNum; i++){
        cout.width(10);
        cout<<"�̸�: "<<pSt[i].stName<<"\t�й�: "<<pSt[i].Hakbun;  //�ּҸ� �̵��ϸ� ���ʷ� �л� ������ ����Ѵ�.
        cout<<"\n--------------------------------------------------------------\n";
        cout.width(10);
        cout<<"�����"<<"\t����������"<<"\t������"<<"\t��������";
        cout<<"\n--------------------------------------------------------------\n";
        for(int j=0;j<st[i].SubNum;j++){  //���������� ����ü�� �ּҸ� �̵����ָ� �� ������ ������ ����Ѵ�. 
            cout.width(10);
            cout<<pSt[i].Sub[j].subName<<"\t\t"<<pSt[i].Sub[j].Hakjum<<"\t\t"<<pSt[i].Sub[j].Grade<<"\t\t"<<pSt[i].Sub[j].GPA<<"\n";
        }   
        cout<<"--------------------------------------------------------------\n"; 
        cout.width(10);
        cout<<"\t\t\t\t\t\t�������= "<<(pSt+i)->AveGPA<<"\n\n";
    }
} //��ü �л� �Ż�&���� ������ ����Ѵ�.


void PrintOneData(const Student& rSt){  //read only reference rSt�� �˻��� �л� ���� ���  
    cout.width(10);
    cout<<"\n�̸�: "<<rSt.stName<<"\t�й�: "<<rSt.Hakbun;  //���۷����� �����Ͽ� ������ش�.
    cout<<"\n--------------------------------------------------------------\n";
    cout.width(10);
    cout<<"�����"<<"\t����������"<<"\t������"<<"\t��������";
    cout<<"\n--------------------------------------------------------------\n";
    for(int i=0;i<rSt.SubNum;i++){  //���������� ���۷����� �����Ͽ� �� ������ ������ ����Ѵ�.
        cout.width(10);
        cout<<rSt.Sub[i].subName<<"\t\t"<<rSt.Sub[i].Hakjum<<"\t"<<rSt.Sub[i].Grade<<"\t\t"<<rSt.Sub[i].GPA<<"\n";
    } 
    cout<<"--------------------------------------------------------------\n"; 
        cout.width(10);
        cout<<"\t\t\t\t\t\t�������= "<<rSt.AveGPA<<"\n\n";    
} //���� �л��� �Ż�&���� ������ ����Ѵ�.


Student* StdSearch(Student* pSt, int StudentNum){
    char SearchName[30];  //ã�� �̸��� �Է¹��� ���ڿ� ������ �����Ѵ�.
    cout<<"�˻� �� �л��� �̸��� �Է��ϼ���: ";
    InputValue(SearchName);
    for(int i=0;i<StudentNum;i++){  //�л����� �̸��� ���ڿ����Լ��� ���Ͽ� �˻��� �̸��� ������(�Լ� ���� ���� 0�̸�) �ش� �л��� �ε��� �ּҸ� �����Ѵ�.
        if(strcmp((pSt+i)->stName,SearchName)==0) return &st[i];  
    }
    return NULL;  //�߰����� ���ߴٸ� NULL�� ������ ã�� ���ߴٴ� ���� �˸���.
} //�л� �̸� �˻� �� �ش� �л��� ������ �ִ� ���� �ּҸ� �����Ѵ�.


void ModifyStdInfo(Student *pSt){
    pSt=StdSearch(st,StdNum);  //StdSearch�Լ��� ȣ���� �л��� ã��, �ش� �л��� ������ �ּҸ� pSt�� �����Ѵ�.
    if(pSt != NULL){
        cout<<"\n["<<pSt->stName<<" "<<pSt->Hakbun<<"]�� ������ �����ϼ���.\n\n";  //�����͸� �����Ѵ�.
        cout<<"������ �̸�: ";
        InputValue(pSt->stName);
        cout<<"������ �й�: ";
        InputValue(pSt->Hakbun);
        cout<<"\n����Ǿ����ϴ�.\n";  
    }
    else cout<<"\n�ش� �л��� ������ ã�� �� �����ϴ�.\n";  //�л��� ã�� ���� ��� ���������� ����Ѵ�.
} //�˻��� �л��� �Ż� ������ �����Ѵ�.
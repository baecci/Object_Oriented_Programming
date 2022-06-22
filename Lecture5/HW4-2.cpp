#include <iostream>
using namespace std;
#define Num 5  //배열 크기를 정의한다.

/*
                HW#4 : 개선된 함수기능                    
  작성자 : 배기원 2021041081         날짜 : 2022년 04월 07일   
                                                           
  문제 정의 : 함수 템플릿 이해하기                     
                                          
*/

template <class T> void Sort(T *array, int arrayNum);  //함수 템플릿을 통해 Sort()함수를 정의하였다.

int main(){
    while(1){
        cout<<"\n----------메뉴----------\n"<<" 1. 정수 정렬하기\n"<<" 2. 실수 정렬하기\n"<<" 3. 프로그램 종료\n";  //메뉴를 출력한다.
        cout<<"\n메뉴를 선택하세요: ";
        int m;
        cin>>m;
        switch(m){
            case 1:
                int iarr[Num];  //정수형 배열을 선언한다.

                for(int i = 0; i < Num; i++){  //배열 원소를 입력한다.
                    cout<<i + 1<<"번째 정수값을 입력하세요: ";
                    cin>>iarr[i];
                }
                Sort(iarr, Num);  //배열 원소를 오름차순 선택정렬한다.

                cout<<"정렬 후:";
                for(int i = 0; i < Num; i++){  //정렬된 배열 원소들 출력한다.
                    cout<<" "<<iarr[i];
                }

                break;

            case 2:
                float farr[Num];  //실수형 배열을 선언한다.

                for(int i=0;i<Num;i++){  //이 아래부터는 case 1과 같은 알고리즘이다.
                    cout<<i+1<<"번째 실수값을 입력하세요: ";
                    cin>>farr[i];
                }
                Sort(farr, Num);

                cout<<"정렬 후:";
                for(int i = 0; i < Num; i++){
                    cout<<" "<<farr[i];
                }
                cout<<"\n\n";
                break;

            case 3:
                return 0;  
            
            default:  //1~3 이외 번호 입력시 오류 문구를 출력한다.
                cout<<"\n해당 기능은 없습니다."; 
                break;
        }
    }
}

template <class T> void Sort(T *array, int arrayNum){  //선택정렬.
    T temp;
    for(int i = 0; i < arrayNum-1; i++){
        for(int j = i + 1; j < arrayNum; j++){
            if(array[i] > array[j]){
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}


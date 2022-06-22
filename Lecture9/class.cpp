#include <iostream>
#include <string>
#include <vector>  //벡터 클래스 사용
using namespace std;

/*
                      HW#6 : 클래스                     
  작성자 : 배기원 2021041081         날짜 : 2022년 04월 28일   

  문제 정의 : vector클래스를 이용해 입력받은 단어와 빈도수 출력하기                           

*/

void inputWord(string inword);
void RemoveAll();

struct WORD{
  string str;
  int count;
};

vector<WORD*> words;  //WORD구조체의 포인터를 저장하는 벡터 객체

int main(){
    string inWord;

    /* 1. 단어 입력 후 단어처리 함수 호출 */
    cout<<"문자열 입력(Ctrl+z 종료) "<<endl;
    while(cin>>inWord) inputWord(inWord);

    /* 4. 문자열 출력 */
    cout<<"========================="<<endl;
    for(int i = 0 ; i<words.size() ; i++){
      cout<<words[i]->str<<": "<<words[i]->count<<endl;
    } 
    cout<<"========================="; 

    /* 5. 동적 할당 메모리 해제 함수 호출 */
    RemoveAll();
    return 0;
}


void inputWord(string inword){

  for(int i=0; i<words.size(); i++){

    /* 2. Ctrl+z 입력시 단어 입력 종료 */
    if(inword == "^z") return;

    /* 3. 벡터 객체에 이미 있는 단어라면 해당 구조체의 count += 1 */
    else if(inword == words[i]->str){
      words[i]->count += 1;
      return;
    }
  }

  /* 3. 벡터 객체에 없는 단어라면 last in */
    WORD *pWord = new WORD;
    pWord->str = inword;
    pWord->count = 1;
    words.push_back(pWord);  //emplace_back 차이점 확인
}

void RemoveAll(){
    for(int i = 0 ; i<words.size() ; i++){
      delete words[i];
    }
}
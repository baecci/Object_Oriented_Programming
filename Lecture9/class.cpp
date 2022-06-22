#include <iostream>
#include <string>
#include <vector>  //���� Ŭ���� ���
using namespace std;

/*
                      HW#6 : Ŭ����                     
  �ۼ��� : ���� 2021041081         ��¥ : 2022�� 04�� 28��   

  ���� ���� : vectorŬ������ �̿��� �Է¹��� �ܾ�� �󵵼� ����ϱ�                           

*/

void inputWord(string inword);
void RemoveAll();

struct WORD{
  string str;
  int count;
};

vector<WORD*> words;  //WORD����ü�� �����͸� �����ϴ� ���� ��ü

int main(){
    string inWord;

    /* 1. �ܾ� �Է� �� �ܾ�ó�� �Լ� ȣ�� */
    cout<<"���ڿ� �Է�(Ctrl+z ����) "<<endl;
    while(cin>>inWord) inputWord(inWord);

    /* 4. ���ڿ� ��� */
    cout<<"========================="<<endl;
    for(int i = 0 ; i<words.size() ; i++){
      cout<<words[i]->str<<": "<<words[i]->count<<endl;
    } 
    cout<<"========================="; 

    /* 5. ���� �Ҵ� �޸� ���� �Լ� ȣ�� */
    RemoveAll();
    return 0;
}


void inputWord(string inword){

  for(int i=0; i<words.size(); i++){

    /* 2. Ctrl+z �Է½� �ܾ� �Է� ���� */
    if(inword == "^z") return;

    /* 3. ���� ��ü�� �̹� �ִ� �ܾ��� �ش� ����ü�� count += 1 */
    else if(inword == words[i]->str){
      words[i]->count += 1;
      return;
    }
  }

  /* 3. ���� ��ü�� ���� �ܾ��� last in */
    WORD *pWord = new WORD;
    pWord->str = inword;
    pWord->count = 1;
    words.push_back(pWord);  //emplace_back ������ Ȯ��
}

void RemoveAll(){
    for(int i = 0 ; i<words.size() ; i++){
      delete words[i];
    }
}
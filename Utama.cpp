#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

class evalExp{
	public:
	struct node{
		int data;
		node *next;
	};
	
	class stack{
		private:
		node *top = NULL;
		
		public:
		bool isEmpty(){
			return (top==NULL);
		}
		
		void push(int databaru){
			node *nodeBaru = new node;
			nodeBaru->data = databaru;
			nodeBaru->next = top;
			top = nodeBaru;
		}
		
		int pop(){
			node *hapus;
			int dta;
            if(!isEmpty()){
                hapus = top;
                dta = top->data;
                top = top->next;
                delete hapus;
            }
            return dta;
		}
		
		int getTop(){
			return top->data;
		}
		
		void cetakstack(){
			node *bantu = top;
			if(isEmpty()){
				cout << "NULL";
			}else{
				while(bantu!=NULL){
					cout << bantu->data << " ";
					bantu = bantu->next;
				}
			}
		}
	};
	stack s;
class infos{
	public:
	node *head = NULL, *tail = NULL;
	
	bool isEmpty(){
        return (head==NULL);
        }
        
void tBelakang(int databaru){
       	node *nodeBaru = new node;
       	nodeBaru->data = databaru;
       	nodeBaru->next = NULL;
       	if(isEmpty()){
           head = nodeBaru;
           tail = nodeBaru;
           head->next = NULL;
           tail->next = NULL;
        }else{
           tail->next = nodeBaru;
           tail = nodeBaru;
           }}
		
int hDepan(){
	node *hapus = head;
	int dta = head->data;
        head = head->next;
        delete hapus;
        return dta;}
		
int getHead(){
	return head->data;}

void cetakinfos(){
	node *bantu = head;
	while(bantu!=NULL){
	if(bantu->data=='+' || bantu->data=='-' || bantu->data=='*' || bantu->data=='/'){
		cout << (char)bantu->data << " ";
	}else{
		cout << bantu->data << " ";}
		bantu = bantu->next;
	}
	}
	};
	infos infix, postfix;
	int precedence(int op){
        if(op=='+' || op=='-'){
			return 1;
		}
        else if(op=='*' || op=='/'){
            return 2;
		}
    }
    
    int turntoint(char *inp){
    	if(isdigit(*inp)){
    		return atoi(inp);
		}
		else if(inp[0]=='+' || inp[0]=='-' || inp[0]=='*' || inp[0]=='/' || inp[0]=='(' || inp[0]==')'){
			return inp[0];
		}
	}
};

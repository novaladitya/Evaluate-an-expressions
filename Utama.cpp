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

int main(){
	evalExp e;
	char input[6];
	int i = 0;
	
	cout << "Masukkan infix, dipisahkan tiap elemen dengan spasi, " << endl
		 << "dan jika ingin mengakhirinya dengan cara (enter) contoh : ( 5 / 4 ) + 8(enter)" << "\n\n"
		 << "Masukkan infix = ";
	while(input[i]!=10){ //ketika terdeteksi input != enter(10 = ASCII dari enter)
		for(int j=0; j<6; j++)//untuk reset array input
			input[j]='\0';
		i = 0;
		while(input[i-1]!=32 && input[i-1]!=10){
			cin.get(input[i]);
			i++;
		}
		e.infix.tBelakang(e.turntoint(input));
		i--;
	}
	cout << "\n\nInfix = ";
	e.infix.cetakinfos();
	cout << endl;
	
	/**************************TRANSFORMING********************************************/
	while(e.infix.head!=NULL){		
		if(e.infix.getHead()=='+' || e.infix.getHead()=='-' || e.infix.getHead()=='*' || e.infix.getHead()=='/'){
			if(e.s.isEmpty() || e.s.getTop()=='('){
				e.s.push(e.infix.hDepan());
			}else{
				while(!e.s.isEmpty() && e.s.getTop()!='(' && e.precedence(e.infix.getHead())<=e.precedence(e.s.getTop())){
					e.postfix.tBelakang(e.s.pop());
				}
				e.s.push(e.infix.hDepan());
			}
		}
		else if(e.infix.getHead()=='('){
			e.s.push(e.infix.hDepan());
		}
		else if(e.infix.getHead()==')'){
			while(!e.s.isEmpty() && e.s.getTop()!='('){
				e.postfix.tBelakang(e.s.pop());
			}
			e.infix.hDepan();
			e.s.pop();
		}
		else{
			e.postfix.tBelakang(e.s.pop());
		}
	}
	while(!e.s.isEmpty()){
		e.postfix.tBelakang(e.s.pop());
	}
	cout << "Postfix = ";
	e.postfix.cetakinfos();
	cout << endl;
		//evaluating
	int A, B, hasil;
	while(e.postfix.head!=NULL){
		if(e.postfix.getHead()=='*' || e.postfix.getHead()=='/' || e.postfix.getHead()=='+' || e.postfix.getHead()=='-'){
			switch(e.postfix.hDepan()){
				case '*':
					A = e.s.pop();
					B = e.s.pop();
					hasil = B*A;
					e.s.push(hasil);
					break;
				case '/':
					A = e.s.pop();
					B = e.s.pop();
					hasil = B/A;
					e.s.push(hasil);
					break;
				case '-':
					A = e.s.pop();
					B = e.s.pop();
					hasil = B-A;
					e.s.push(hasil);
					break;
				case '+':
					A =e .s.pop();
					B = e.s.pop();
					hasil = B+A;
					e.s.push(hasil);
					break;
			}
		}
		else{
			e.s.push(e.postfix.hDepan());
		}
		
	}
	cout<<"Hasil= "<<e.s.pop();
	
	return 0;
}

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

//
// Assignment 2 : Simple calculator using Stack
//
// Array-based stack data structure
//
// COSE213 Spring 2021
//

template<class type>
Stack<type>::~Stack()
{
	// ToDo
	delete []array;
}

template<class type>
type& Stack<type>::Top()
{
	// ToDo
	if(top==-1) {std::cout<<"Stack Is Empty"<<'\n'; exit(1);}
	else return array[top];
}

template<class type>
void Stack<type>::Push(const type& item)
{
	// ToDo
	if(top==capacity-1){
	capacity*=2;
	type *temp=new type[capacity];
	for(int i=0;i<=top;i++){
	temp[i]=array[i];
	}
	delete[] array;
	array=temp;
	}
	array[++top]=item;
	
}

template<class type>
void Stack<type>::Pop()
{
	// ToDo
	if(top==-1) {std::cout<<"Stack Is Empty"<<'\n'; exit(1);}
	else top--;
}

template<class type>
bool Stack<type>::IsEmpty() const
{
	// ToDo	
	if(top!=-1) return false;
	return true;
}


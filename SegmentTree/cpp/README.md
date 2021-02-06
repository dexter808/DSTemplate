# An Example Usage

1. An array of size 5 with elements 1,2,3,4,5 is decclared. 

2. A Segment Tree is built on the array to perform numeric addition and updation on segments of the array.

3. We deduce that: 
	a) Binary Function required is Add(a,b) which returns a+b and,
	b) The redundant (or the identity) value for this function is 0. Since, **Add(a,0)=a**

~~~
int Add(int a,int b)
{
	return a+b;
}
int main()
{
	//Vector of elements
	vector<int> A={1,2,3,4,5};
	//Initializing and building the segment tree
	STtree<int> tr(A,0,Add);
	//Using tree
	cout<<tr.querry(0,2)<<"\n";
	tr.update(1,4);
	cout<<tr.querry(0,2)<<"\n";
	return 0;
}
~~~

# An Example Usage

1. An array of size 5 with elements 1,2,3,4,5,6,7 is decclared. 

2. A Segment Tree is built on the array to perform numeric addition and updation on segments of the array.

3. We deduce that: 
	a) Binary Function required is Add(a,b) which returns a+b and,
	b) The redundant (or the identity) value for this function is 0. Since, **Add(a,0)=a**

**

# Using Lambda function

~~~
public static void main(String[] args) {
		ArrayList<Integer> A=new ArrayList<Integer>();
		Collections.addAll(A, 1,2,3,4,5,6,7);
			
			
		//Declaration
		SegmentTree<Integer> tr=new SegmentTree<Integer>(A, 0, (a,b)->a+b );
			
			
		//Usage
		System.out.println(tr.querry(0, 2));
		tr.update(1,4);
		System.out.println(tr.querry(1, 5));
	}
~~~

# Using a function

~~~
public static void main(String[] args) {
		ArrayList<Integer> A=new ArrayList<Integer>();
		Collections.addAll(A, 1,2,3,4,5,6,7);
			
		//Declaration
		SegmentTree<Integer> tr=new SegmentTree<Integer>(A, 0, (a,b) -> Add(a,b) );

		//Usage
		System.out.println(tr.querry(0, 2));
		tr.update(1,4);
		System.out.println(tr.querry(1, 5));
	}
	public static int Add(int a,int b){
		return a+b;
	}
~~~

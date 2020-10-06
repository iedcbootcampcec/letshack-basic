import java.io.*;
import java.util.*;

class Reader {
	static BufferedReader reader;
	static StringTokenizer tokenizer;
	static void init(InputStream input) {
	    reader = new BufferedReader(
	                 new InputStreamReader(input) );
	    tokenizer = new StringTokenizer("");
	}
	
	
	static String next() throws IOException {
	    while ( ! tokenizer.hasMoreTokens() ) {
	
	
	        tokenizer = new StringTokenizer(
	               reader.readLine() );
	    }
	    return tokenizer.nextToken();
	}
	
	static int nextInt() throws IOException {
	
		return Integer.parseInt( next() );
	}
		
	static double nextDouble() throws IOException {
	    return Double.parseDouble( next() );
	}
}


class Node {
	 int data, height;
	 Node left, right;

	 Node(int d) {
	     data = d;
	     height = 1;
	 }
}

class AVLTree {
	
	 Node root;
	
	
	 int height(Node N) {
	     if (N == null)
	         return 0;
	
	     return N.height;
	 }
	
	
	 int max(int a, int b) {
	     if (a > b)
	     	return a;
	     else
	     	return b;
	 }
	
	
	 Node rightRotate(Node y) {
	     Node x = y.left;
	     Node T2 = x.right;
	
	
	     x.right = y;
	     y.left = T2;
	
	
	     y.height = max(height(y.left), height(y.right)) + 1;
	     x.height = max(height(x.left), height(x.right)) + 1;
	
	     return x;
	 }
	
	
	 Node leftRotate(Node x) {
	     Node y = x.right;
	     Node T2 = y.left;
	
	     y.left = x;
	     x.right = T2;
	
	     x.height = max(height(x.left), height(x.right)) + 1;
	     y.height = max(height(y.left), height(y.right)) + 1;
	
	     return y;
	 }
	
	 
	 int getBalance(Node N) {
	     if (N == null)
	         return 0;
	
	     return height(N.left) - height(N.right);
	 }
	
	 Node insert(Node node, int data) {
	
	     if (node == null)
	         return (new Node(data));
	
	     if (data < node.data)
	         node.left = insert(node.left, data);
	     else if (data > node.data)
	         node.right = insert(node.right, data);
	     else
	         return node;
	
	
	     node.height = 1 + max(height(node.left),
	                           height(node.right));
	
	
	     int balance = getBalance(node);
	
	
	     if (balance > 1 && data < node.left.data)
	         return rightRotate(node);
	
	     if (balance < -1 && data > node.right.data)
	         return leftRotate(node);
	
	     if (balance > 1 && data > node.left.data) {
	         node.left = leftRotate(node.left);
	         return rightRotate(node);
	     }
	
	     if (balance < -1 && data < node.right.data) {
	         node.right = rightRotate(node.right);
	         return leftRotate(node);
	     }
	
	     return node;
	 }
		boolean f = true;
		
		public void preorder(Node n,int low,int high) {
			if (n != null) {
				if(height(n) == 1 && n.data >=low && n.data <= high) {
					System.out.print(n.data + " ");
					f  = false;
				}
				preorder(n.left,low,high);
				preorder(n.right,low,high);
			}
			
		}

	public static void main(String args[]) throws IOException {
		Reader.init(System.in);
		int t = Reader.nextInt();
		AVLTree avl = new AVLTree();
		for(int test = 0; test < t; test++) {
			String oper = Reader.next();
			if(oper.equals("INSERT")) {
				int anum = Reader.nextInt();
				avl.root = avl.insert(avl.root,anum);
			}
			else if(oper.equals("FIND")) {
				int min = Reader.nextInt();
				int max = Reader.nextInt();
				avl.preorder(avl.root,min,max);
				if(avl.f == true) {
					System.out.println(-1);
				}
				else 
				{
					System.out.println();
					avl.f = true;
				}
			}
		}
        
	}
}

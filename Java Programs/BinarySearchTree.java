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



class Node{
	
	int data;
	Node left;
	Node right;	
	
	public Node(){
		this.data = 0;
		left = null;
		right = null;
	}
	
	public Node(int data){
		this.data = data;
		left = null;
		right = null;
	}
	
}



public class BinarySearchTree {
	
	protected Node root;
	
	public BinarySearchTree(){
		this.root = null;
	}
	
	
	int minValue(Node root)
    {
        int minv = root.data;
        while (root.left != null)
        {
            minv = root.left.data;
            root = root.left;
        }
        return minv;
    }
	
	
	
	Node delete(Node root, int data)
    {

        if (root == null)  return root;
 

        if (data < root.data)
            root.left = delete(root.left, data);
        else if (data > root.data)
            root.right = delete(root.right, data);

        else
        {
            if (root.left == null)
                return root.right;
            else if (root.right == null)
                return root.left;

            root.data = minValue(root.right);
 
            root.right = delete(root.right, root.data);
        }
 
        return root;
    }

	
	public Node insert(Node root, int value){
		if (root == null)
			root = new Node (value);
		else {
			if (value <= root.data)
				root.left = insert(root.left, value);
			else
				root.right = insert(root.right, value);
			}
		return root;
	}
	
	/* preorder display */
	public void preorder (Node root) {
		if (root!=null) {
			System.out.print (root.data + " ");
			preorder(root.left);
			preorder(root.right);
		}
	}
	
	/* inorder display */
	public void inorder (Node root) {
		if (root!=null) {
			inorder(root.left);
			System.out.print (root.data + " ");
			inorder(root.right);
		}
	}
	
	/* postorder display */
	public void postorder(Node root) {
		if (root!=null) {
			postorder(root.left);
			postorder(root.right);
			System.out.print (root.data + " ");
		}
		
	}

	
	public static void main(String arg[]) throws IOException{
		Reader.init(System.in);
		int t = Reader.nextInt();
		BinarySearchTree bst = new BinarySearchTree();
		for(int test = 0; test<t; test++) {
			String oper = Reader.next();
			if(oper.equals("INSERT")) {
				int anum = Reader.nextInt();
				bst.root = bst.insert(bst.root,anum);
			}
			else if(oper.equals("DELETE")) {
				int anum = Reader.nextInt();
					bst.root = bst.delete(bst.root,anum);
			}
			else if(oper.equals("PRINTPRE")) {
				if(bst.root == null) {
					System.out.println(-1);
				}
				else {
					bst.preorder(bst.root);
					System.out.println();
				}
			}
			else if(oper.equals("PRINTPOST")) {
				if(bst.root == null) {
					System.out.println(-1);
				}
				else {
					bst.postorder(bst.root);
					System.out.println();
				}
			}
			else if(oper.equals("PRINTIN")) {
				if(bst.root == null) {
					System.out.println(-1);
				}
				else {
					bst.inorder(bst.root);
					System.out.println();
				}
			}
			
		}
	}
}

import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

class Node {
    com.company.Node left;
    com.company.Node right;
    int data;
}

class BST {

    public boolean checkIfPairExists(com.company.Node node, int sum) {
        List<Integer> list = new ArrayList<>();

        inorder(node, list);
        return checkIfPairExistsUtil(sum, list);
    }

    public void inorder(com.company.Node node, List<Integer> list) {
        if(node == null) {
            return;
        }

        inorder(node.left, list);

        list.add(node.data);

        inorder(node.right, list);
    }

    private boolean checkIfPairExistsUtil(int sum, List<Integer> list) {
        int start = 0;
        int end = list.size() - 1;


        while(start < end) {
            int currentSum = list.get(start) + list.get(end);

            if(currentSum == sum) {
                return true;
            } else if(currentSum < sum) {
                start++;
            } else {
                end--;
            }
        }

        return false;
    }


    public com.company.Node insert(com.company.Node node, int val) {
        if(node == null) {
            return createNewNode(val);
        }

        if(val < node.data) {
            node.left = insert(node.left, val);
        } else if((val > node.data)) {
            node.right = insert(node.right, val);
        }

        return node;
    }

    public com.company.Node createNewNode(int k) {
        com.company.Node a = new com.company.Node();
        a.data = k;
        a.left = null;
        a.right = null;
        return a;
    }
}

public class Main {

    public static void main(String[] args) {
        Scanner in=new Scanner(System.in);
        com.company.BST a = new com.company.BST();
        com.company.Node root = null;
        int n=in.nextInt();
        for(int i=0;i<n;i++)
        {
            root = a.insert(root,in.nextInt());
        }
        int sum=in.nextInt();
        if(a.checkIfPairExists(root,sum))
            System.out.println("yes");
        else
            System.out.println("no");
    }

}

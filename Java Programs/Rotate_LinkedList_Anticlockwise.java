import java.util.*;

public class Main{

    /* Link list node */
    static class Node {

        int data;
        com.company.Main.Node next;
    };
    static com.company.Main.Node head = null;

    static void rotate( int k)
    {
        if (k == 0)
            return;


        com.company.Main.Node current = head;


        while (current.next != null)
            current = current.next;

        current.next = head;
        current = head;

        for (int i = 0; i < k - 1; i++)
            current = current.next;

        head = current.next;
        current.next = null;
    }


    static void push(int new_data)
    {

        com.company.Main.Node new_node = new com.company.Main.Node();

        new_node.data = new_data;


        new_node.next = head;


        head = new_node;
    }


    static void printList(com.company.Main.Node node)
    {
        while (node != null)
        {
            System.out.print(node.data + " ");
            node = node.next;
        }
    }

    public static void  main(String[] args)
    {
        Scanner in=new Scanner(System.in);
        int n=in.nextInt();
        int ar[]=new int[n];
        for (int i = 0; i <n; i ++)
            ar[i]=in.nextInt();
        for (int i = n-1; i >=0; i --)
            push( ar[i]);

        int k=in.nextInt();
        System.out.print("Given linked list \n");
        printList(head);
        rotate( k);

        System.out.print("\nRotated Linked list \n");
        printList(head);
    }
}
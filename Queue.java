import java.util.Scanner;
public class Queue {
	static Scanner scan = new Scanner(System.in);
	static int no, i, front = -1, rear = -1, k, element, size;

static int queue[];

	void enqueue(int x) {
		if (rear == (size - 1))

			System.out.println("\nOverflow.Element not inserted");

		else

		{

			if (front == -1 && rear == -1)

				front = 0;

			rear++;

			queue[rear] = x;

		}
	}
	void dequeue() {
		if (front == -1)

			System.out.println("\nUnderflow.\n");

		else

		{

			k = queue[front];

			System.out.println("\nDeleted element is " + k);

		}

		if (front == rear)

			front = rear = -1;

		else

			front++;
	}
	void display() {
		if (front == -1 && rear == -1)

			System.out.println("\nUnderflow.No elements to display\n");

		else

		{

			System.out.println("\nQueue elements are\n ");

			for (i = front; i <= rear; i++)

			{

				System.out.println("\n\n" + queue[i]);

			}

		}

	}
	Queue() {
		Scanner sc = new Scanner(System.in);
		char c;



		System.out.println("\nPROGRAM TO INSERT, DELETE AND DISPLAY ELEMENTS TO QUEUE");


		do

		{
			System.out.println("\nMENU\n\n");

			System.out.println("1.INSERT\n\n2.DELETE\n\n3.DISPLAY\n\n4.EXIT\n\nEnter your choice: ");

			no = sc.nextInt();

			if (no == 1)

			{
				System.out.println("\n\nEnter the element: ");
				element = sc.nextInt();

				enqueue(element);


			}

			if (no == 2) {

				dequeue();
			}

			if (no == 3)

			{
				display();

			}

			if (no == 4)

				break;

			System.out.println("\n\nDo you want to continue(y/n) ");

			c = sc.next().charAt(0);

		}

		while (c == 'y' || c == 'Y');
	}



Queue(int size) {
	this.size = size;
	queue = new int[size];

}

public static void main(String[] args) 
	{
		System.out.println("\n\nEnter the size of the queue: ");

		int sizeQ = scan.nextInt();
		new Queue(sizeQ);
		new Queue();
	}
}


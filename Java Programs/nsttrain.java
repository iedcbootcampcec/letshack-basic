public class Train {
    // structure of items in list
    private class Car {
        String name;               
        Car next;                   
 
       
        private Car(String initialName) {
            name = initialName;
            
        }
    }
 
    
    private Car first = null;
 

    public void threeCars() {
        first = new Car("Locomotive");        
        first.next = new Car("Cafe");       
        first.next.next = new Car("Passenger A");  
    }
 
    public void printAll() {
       
        Car current = first; 
 
      
        while (current != null) {
           
            StdOut.println(current.name);
            current = current.next;
        }
    }
 
    public void insertAtEnd(String carName) {
        Car newCar = new Car(carName);
        if (first == null)
            first = newCar;
        else {
            Car current = first;
            while (current.next != null)
                current = current.next;
            current.next = newCar;
        }
 
 
    }
 
    // test client
    public static void main(String[] args) {
        Train test = new Train();
        test.threeCars();
        test.printAll();
        test.insertAtEnd("Caboose");
        test.printAll();
    }
 
}

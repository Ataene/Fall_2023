import java.util.List;

public class OrderPrinter {
	
    public static void printOrder(Order order) {
    	
        System.out.println("*********************************************************************");
        
        System.out.println("ORDER ID: " + order.getOrderId());
        
        System.out.println("Date Ordered: " + order.getDateOrdered());
        
        System.out.println("Item description: " + order.getItemDescription());
        
        System.out.println("Amount ordered: " + order.getRequiredQuantity());
        
        System.out.println("Supplier: " + order.getSupplierInfo().getCompanyName());
        
        System.out.println("*********************************************************************");
    }

    public static void main(String[] args) {
    	
        // FileHandler
    	
        FileHandler fileHandler = new FileHandler();

        // Read suppliers and tools data from files
        
        List<Supplier> suppliers = fileHandler.readSuppliersFromFile("suppliers.txt");
        
        List<Tool> tools = fileHandler.readToolsFromFile("items.txt");

        Order order1 = new Order(15181, "January 18, 2016", "Nic Nacs", suppliers.get(0), 250); // Corrected supplier index
        
        Order order2 = new Order(26490, "January 26, 2016", "Wog Wits", suppliers.get(1), 100); // Corrected supplier index

        // Print orders
        printOrder(order1);
        
        printOrder(order2);
    }
}

// Define the OrderGenerator class
class OrderGenerator {
	
	// Random order ID generator
    public int generateOrderId() {
    	  	
        return (int) (Math.random() * 90000) + 10000;
    }

    public Order createOrder(Tool tool, Supplier supplier, int requiredQuantity) {
    	
        // Generate a unique order ID
    	
        int orderId = generateOrderId();
        
        String dateOrdered = "2023-09-23";

        // Create an Order object using the provided information
        
        String itemDescription = tool.getDescription();
        
        return new Order(orderId, dateOrdered, itemDescription, supplier, requiredQuantity);
    }
    
    // Method to generate an order
    
    public Order generateOrder(Tool tool, Supplier supplier, int requiredQuantity) {
    	
        int orderId = generateOrderId();

        // Current date (you can use java.time.LocalDate 
        
        String dateOrdered = "January 18, 2016";

        String itemDescription = tool.getDescription();

        return new Order(orderId, dateOrdered, itemDescription, supplier, requiredQuantity);
    } 
}

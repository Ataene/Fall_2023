
// Task 1: Classes used includes: Order.java, OrderItem.java, Supplier.java and Tools.java
// Task 2: The UML class Diagrams is draw for each class. 

class Tool {
    private int id;
    
    private String description;
    
    private int quantityInStock;
    
    private double price;
    
    private int supplierId;

    public Tool(int id, String description, int quantityInStock, double price, int supplierId) {
    	
        this.id = id;
        
        this.description = description;
        
        this.quantityInStock = quantityInStock;
        
        this.price = price;
        
        this.supplierId = supplierId;
    }

    public int getId() {
    	
        return id;
    }

    public void setId(int id) {
    	
        this.id = id;
    }

    public String getDescription() {
    	
        return description;
    }

    public void setDescription(String description) {
    	
        this.description = description;
    }

    public int getQuantityInStock() {
    	
        return quantityInStock;
    }

    public void setQuantityInStock(int quantityInStock) {
    	
        this.quantityInStock = quantityInStock;
    }

    public double getPrice() {
    	
        return price;
    }

    public void setPrice(double price) {
    	
        this.price = price;
    }

    public int getSupplierId() {
    	
        return supplierId;
    }

    public void setSupplierId(int supplierId) {
    	
        this.supplierId = supplierId;
    }

    @Override
    public String toString() {
    	
        return "Tool{" +
                "id=" + id +
                ", description='" + description + '\'' +
                ", quantityInStock=" + quantityInStock +
                ", price=" + price +
                ", supplierId=" + supplierId +
                '}';
    }
}

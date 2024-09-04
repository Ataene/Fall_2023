class Order {
	
	// Instance variables for the store orders
	
    private int orderId;
    
    private String dateOrdered;
    
    private String itemDescription;
    
    private Supplier supplierInfo;
    
    private int requiredQuantity;

    // Order object initialization.
    
    public Order(int orderId, String dateOrdered, String itemDescription, Supplier supplierInfo, int requiredQuantity) {
    	
        this.orderId = orderId;
        
        this.dateOrdered = dateOrdered;
        
        this.itemDescription = itemDescription;
        
        this.supplierInfo = supplierInfo;
        
        this.requiredQuantity = requiredQuantity;
    }

    // Method to retrieve the order ID
    
    public int getOrderId() {
    	
        return orderId;
    }
    // Method to retrieve the order ID
    public void setOrderId(int orderId) {
    	
        this.orderId = orderId;
    }

    public String getDateOrdered() {
    	
        return dateOrdered;
    }

    public void setDateOrdered(String dateOrdered) {
    	
        this.dateOrdered = dateOrdered;
    }

    public String getItemDescription() {
    	
        return itemDescription;
    }

    public void setItemDescription(String itemDescription) {
    	
        this.itemDescription = itemDescription;
    }

    public Supplier getSupplierInfo() {
    	
        return supplierInfo;
    }

    public void setSupplierInfo(Supplier supplierInfo) {
    	
        this.supplierInfo = supplierInfo;
    }

    public int getRequiredQuantity() {
    	
        return requiredQuantity;
    }
    
    // Setter method for quantity.
    
    public void setRequiredQuantity(int requiredQuantity) {
    	
        this.requiredQuantity = requiredQuantity;
    }
    
    // Override the toString() method of the Order object
    
    @Override
    public String toString() {
    	
        return "Order{" +
                "orderId=" + orderId +
                
                ", dateOrdered='" + dateOrdered + '\'' +
                
                ", itemDescription='" + itemDescription + '\'' +
                
                ", supplierInfo=" + supplierInfo +
                
                ", requiredQuantity=" + requiredQuantity +
                
                '}';
    }
    
    // Method to display order information.
    
    public void displayOrder() {
    	
        System.out.println("ORDER ID: " + orderId);
        
        System.out.println("Date Ordered: " + dateOrdered);
        
        System.out.println("Item description: " + itemDescription);
        
        System.out.println("Amount ordered: " + requiredQuantity);
        
        System.out.println("Supplier: " + supplierInfo.getCompanyName());
    }

}

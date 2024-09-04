import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class FileHandler {
	
	// Read a list of suppliers from the file and return as a List of Supplier objects
	
    public List<Supplier> readSuppliersFromFile(String filePath) {
    	
        List<Supplier> suppliers = new ArrayList<>();
        
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
        	
            String line;
            
            while ((line = reader.readLine()) != null) {
            	
                String[] parts = line.split(";");
                
                int id = Integer.parseInt(parts[0]);
                
                String companyName = parts[1];
                
                String address = parts[2];
                
                String salesContact = parts[3];
                
                Supplier supplier = new Supplier(id, companyName, address, salesContact);
                
                suppliers.add(supplier);
            }
        } catch (IOException e) {
        	
            e.printStackTrace();
        }
        return suppliers;
    }
    // Read a list of tools from the file and return as a List of Tool objects
    
    public List<Tool> readToolsFromFile(String filePath) {
    	
        List<Tool> tools = new ArrayList<>();
        
        try (BufferedReader reader = new BufferedReader(new FileReader(filePath))) {
        	
            String line;
            
            while ((line = reader.readLine()) != null) {
            	
                String[] parts = line.split(";");
                
                // Parse data from the parts
                
                int id = Integer.parseInt(parts[0]);
                
                String description = parts[1];
                
                int quantityInStock = Integer.parseInt(parts[2]);
                
                double price = Double.parseDouble(parts[3]);
                
                int supplierId = Integer.parseInt(parts[4]);
                
                Tool tool = new Tool(id, description, quantityInStock, price, supplierId);
                
                tools.add(tool);
            }
            
        } catch (IOException e) {
        	
        // Handle any IOException by printing the stack trace
        	
            e.printStackTrace();
        }
        
        return tools;
    }
}

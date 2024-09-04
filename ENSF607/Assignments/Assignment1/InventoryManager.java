import java.util.ArrayList;
import java.util.List;

class InventoryManager {
	
    private List<Tool> tools;

    public InventoryManager() {
    	
        tools = new ArrayList<>();
    }

    // Add a new tool to the inventory supplies
    
    public void addTool(Tool tool) {
    	
        tools.add(tool);
    }

    // Delete a tool from the inventory its ID
    
    public boolean deleteTool(int toolId) {
    	
        Tool toolToRemove = null;
        
        for (Tool tool : tools) {
        	
            if (tool.getId() == toolId) {
            	
                toolToRemove = tool;
                
                break;
            }
        }
        if (toolToRemove != null) {
        	
            tools.remove(toolToRemove);
            
            return true; // Tool deleted successfully
        }
        return false;
    }

    // Search for tools by name and return a list of matching tools
    
    public List<Tool> searchToolByName(String toolName) {
    	
        List<Tool> result = new ArrayList<>();
        
        for (Tool tool : tools) {
        	
            if (tool.getDescription().equalsIgnoreCase(toolName)) {
            	
                result.add(tool);
            }
        }
        return result;
    }

    // Search for a tool by ID and return the tool if found
    
    public Tool searchToolById(int toolId) {
    	
        for (Tool tool : tools) {
        	
            if (tool.getId() == toolId) {
            	
                return tool;
            }
        }
        return null;
    }

    // Check if the quantity of a specific tool is below 40 items
    
    public boolean checkQuantity(Tool tool) {
    	
        return tool.getQuantityInStock() < 40;
    }
}

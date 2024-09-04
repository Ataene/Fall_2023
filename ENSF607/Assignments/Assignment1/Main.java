import java.util.List;

public class Main {
	public static void main(String[] args) {
		
		FileHandler fileHandler = new FileHandler();

		List<Tool> tools = fileHandler.readToolsFromFile("items.txt");

		List<Supplier> suppliers = fileHandler.readSuppliersFromFile("suppliers.txt");

		// Initialize InventoryManager with tools

		InventoryManager inventoryManager = new InventoryManager();

		// Add tools to the inventory

		for (Tool tool : tools) {

			inventoryManager.addTool(tool);
		}

		// Attempt to delete a tool by ID
		
		int toolIdToDelete = 1;
		
		boolean deleted = inventoryManager.deleteTool(toolIdToDelete);

		if (deleted) {
			
			System.out.println("Tool with ID " + toolIdToDelete + " deleted successfully.");
			
		} else {
			
			System.out.println("Tool with ID " + toolIdToDelete + " not found.");
		}

		// Search for tools by name
		
		String toolNameToSearch = "Tool Name";
		
		List<Tool> searchResult = inventoryManager.searchToolByName(toolNameToSearch);

		if (!searchResult.isEmpty()) {
			
			System.out.println("Tools with name '" + toolNameToSearch + "' found:");
			
			for (Tool tool : searchResult) {
				
				System.out.println(tool);
			}
		} else {
			
			System.out.println("No tools found with name '" + toolNameToSearch + "'.");
		}

		// Search for a tool by ID
		
		int toolIdToSearch = 2;
		
		Tool foundTool = inventoryManager.searchToolById(toolIdToSearch);

		if (foundTool != null) {
			
			boolean isLowQuantity = inventoryManager.checkQuantity(foundTool);
			
			if (isLowQuantity) {
				
				System.out.println("Tool with ID " + toolIdToSearch + " has low quantity.");
				
			} else {
				
				System.out.println("Tool with ID " + toolIdToSearch + " has sufficient quantity.");
			}
			
		} else {
			
			System.out.println("Tool with ID " + toolIdToSearch + " not found.");
		}

	}

}

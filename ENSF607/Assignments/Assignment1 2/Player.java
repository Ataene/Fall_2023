import java.util.Scanner;

/*
 * The Player class represents a player in the Tic-Tac-Toe game.
 * Each player has a name, a mark (X or O), and interacts with the game board.
 */

public class Player {
	
	private Player opponent;  // Players and the Opponent playing the game.
	
    private String name;  // Name of each opponent
    
    private char mark;
    
    private Board board; // The board of the game.

    public Player(String name, char mark) { // Initialize the name and scores
    	
        this.name = name;
        
        this.mark = mark;
    }

    public void setOpponent(Player opponent) {
    	
        this.opponent = opponent;
    }

    public void setBoard(Board board) {
    	
    // Set the game board for this player.
    	
        this.board = board;
    }

    public String getName() {
    	
        return name;
    }

    public void makeMove() { // Make and predict move in the game.
    	
        Scanner scanner = new Scanner(System.in);

        while (true) {
        	
            try {
            	
                System.out.print(name + ", enter row and column (e.g., 1 2): ");
                
                String input = scanner.nextLine();
                
                String[] inputParts = input.split(" ");

                if (inputParts.length == 2) {
                	
                    int row = Integer.parseInt(inputParts[0]) - 1; // Adjust for zero-based index
                    
                    int col = Integer.parseInt(inputParts[1]) - 1; // Adjust for zero-based index

                    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board.getMark(row, col) == Constants.SPACE_CHAR) {
                    	
                        board.addMark(row, col, mark);
                        
                        return; // Valid move, exit the loop
                    }
                }

                System.out.println("Invalid move. Please try again.");
                
            } catch (NumberFormatException e) {
            	
                System.out.println("Invalid input. Please enter integers for row and column.");
            }
        }
    }

    public void play() { // Make the Player take their turns in the game.
    	
        Scanner scanner = new Scanner(System.in);

        while (true) {
        	
            System.out.print(name + ", enter row and column (e.g., 1 2): ");
            
            String input = scanner.nextLine();
            
            String[] inputParts = input.split(" ");

            try {
            	
                if (inputParts.length == 2) {
                	
                    int row = Integer.parseInt(inputParts[0]) - 1; // Adjust due to the game index
                    
                    int col = Integer.parseInt(inputParts[1]) - 1; // Adjust due to the game index

                    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board.getMark(row, col) == Constants.SPACE_CHAR) {
                    	
                        board.addMark(row, col, mark);
                        
                        return; 
                    }
                }

                System.out.println("Invalid move. Try again."); // Check invalid errors.
                
            } catch (NumberFormatException e) {
            	
                System.out.println("Invalid input. Please enter integers for row and column.");
            }
        }
    }
}

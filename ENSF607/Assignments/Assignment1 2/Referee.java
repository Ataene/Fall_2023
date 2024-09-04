/*
 * The Referee class manages the flow of the Tic-Tac-Toe game.
 * 
 * It coordinates the actions of the players and the game board.
 */

public class Referee {

    private Player playerX; // Player X
    
    private Player playerO; // Player O
    
    private Board board; // Game board

    public Referee() {
    	
    }
    
    /*
     * Sets the game board for the referee.
     * 
     * @param board The game board to be set.
     */
    
    public void setBoard(Board board) {
    	
        this.board = board;
    }

    public void setxPlayer(Player playerX) {
    	
        this.playerX = playerX;
    }

    public void setoPlayer(Player playerO) {
    	
        this.playerO = playerO;
    }

    /*
     * Runs the Tic-Tac-Toe game.
     * 
     * It sets up the players, displays the board, and manages the game loop.
     */
    
    public void runTheGame() {
    	
        playerX.setOpponent(playerO);
        
        playerO.setOpponent(playerX);

        board.display();

        while (true) {
        	
            playerX.play();
            
            if (board.xWins() || board.isFull()) {
            	
                break;
            }
            playerO.play();
            
            if (board.oWins() || board.isFull()) {
            	
                break;
            }
        }

        if (board.xWins()) {
        	
            System.out.println(playerX.getName() + " wins!");
            
        } else if (board.oWins()) {
        	
            System.out.println(playerO.getName() + " wins!");
            
        } else {
        	
            System.out.println("The game ended in a tie");
        }
    }
}

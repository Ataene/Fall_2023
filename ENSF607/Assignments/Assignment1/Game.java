
import java.io.*;

//STUDENTS SHOULD ADD CLASS COMMENTS, METHOD COMMENTS, FIELD COMMENTS 
/*
 * The Game class represents a Tic-Tac-Toe game.
 * 
 * It initializes the game board, players, and referee and starts the game.
 */
public class Game implements Constants {

	private Board theBoard; // Game board

	private Referee theRef; // Referee

	public Game() {

		theBoard = new Board(); // Board Initialize
	}

	/*
	 * Appoints a referee for the game and starts the game.
	 * 
	 * @param r The referee object to be appointed.
	 */
	
	public void appointReferee(Referee r) throws IOException {

		theRef = r;

		theRef.runTheGame();
	}

	public static void main(String[] args) throws IOException {

		Referee theRef;

		Player xPlayer, oPlayer;

		BufferedReader stdin;

		Game theGame = new Game();

		stdin = new BufferedReader(new InputStreamReader(System.in));

		System.out.print("\nPlease enter the name of the \'X\' player: ");

		String name = stdin.readLine();

		while (name == null) {

			System.out.print("Please try again: ");

			name = stdin.readLine();
		}

		xPlayer = new Player(name, LETTER_X);

		xPlayer.setBoard(theGame.theBoard);

		System.out.print("\nPlease enter the name of the \'O\' player: ");

		name = stdin.readLine();

		while (name == null) {

			System.out.print("Please try again: ");

			name = stdin.readLine();
		}

		oPlayer = new Player(name, LETTER_O); // Create the "X" Player.

		oPlayer.setBoard(theGame.theBoard); // Set game board

		theRef = new Referee(); // Create Referee

		theRef.setBoard(theGame.theBoard);

		theRef.setoPlayer(oPlayer);

		theRef.setxPlayer(xPlayer);

		theGame.appointReferee(theRef);
	}

}

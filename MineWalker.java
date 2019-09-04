import java.util.Random;

public class MineWalker 
{
	public int size = 10;
	
	public char[][] board = new char[size][size];
	public boolean[][] mines = new boolean[size][size];
	
	public MineWalker()
	{
		Random rand = new Random();
		
		int icecream = rand.nextInt(((size*size)-1)+1)+1;
		
		//while(int iceCounter < 100)
		for(int r = 0; r < board.length; r++)
		{
			for(int c = 0; c < board[r].length; c++)
			{
				if (icecream == (r+c))
				{
					board[r][c] = '^';
				}
				else
				{
					board[r][c] = '_';
				}
				System.out.print(board[r][c]);
			}
			System.out.println();
		}
	}
	
	public static void main(String[] args)
	{
		MineWalker game1 = new MineWalker();
	}
	
}

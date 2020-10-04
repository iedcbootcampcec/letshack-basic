package Programas_2Kyu;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Stack;

/**
 * Title : Game of Go
 * State : Completed
 */

public class Go {

    private char[][] board;
    private int height;
    private int width;
    private ArrayList<String> movesStack;
    private Stack<ArrayList<String>> turnMoves = new Stack<>();

    //Help to get the surroundings
    private ArrayList<String> Comprobados;
    private int liberties;

    //Stack with the boards with the lastest moves of the players
    private Stack<char[][]> blackLastMove=new Stack<>();
    private Stack<char[][]> whiteLastMove=new Stack<>();
    
    //Auxiliary Variables
    private boolean isHandicapable = true;
    private boolean isBlack = true;
    
    //Static Variables
    private final String PASS = "PASS";
    private final char WHITESTONE = 'o';
    private final char BLACKSTONE = 'x';
    private final char EMPTYCELL = '.';
    private final char ADD_STONE = '+';
    private final char REM_STONE = '-';
    private final String SPACE = " ";
    
    //Handicap stones location
    private ArrayList<String> hand9 = new ArrayList<>(Arrays.asList("2 6","6 2","6 6","2 2","4 4"));
    private ArrayList<String> hand13 = new ArrayList<>(Arrays.asList("3 9","9 3","9 9","3 3","6 6","6 3","6 9","3 6","9 6"));
    private ArrayList<String> hand19 = new ArrayList<>(Arrays.asList("3 15","15 3","15 15","3 3","9 9","9 3","9 15","3 9","15 9"));

    //Simple constructor
    public Go(int size){
        newBoard(size, size);
    }
    
    //Bidimensional constructor
    public Go(int height, int width){
        newBoard(height, width);
    }

    //Method that creates the board and starts a new game
    private void newBoard(int height, int width) throws IllegalArgumentException{
        if (height<1||width<1||height>24||width>24)throw new IllegalArgumentException();
        this.height = height;
        this.width = width;
        board = new char[height][width];
        for (int i = 0; i < height; i++) {
            char[] rows = new char[width];
            Arrays.fill(rows, EMPTYCELL);
            board[i] = rows;
        }
        isBlack=true;
        turnMoves=new Stack<>();
        isHandicapable=true;
        blackLastMove=new Stack<>();
        blackLastMove.push(null);
        whiteLastMove=new Stack<>();
        whiteLastMove.push(null);
        paintBoard();//Uncomment for play
    }

    //Returns the board
    public char[][] getBoard() {
        return board;
    }
    
    //Draws the board (for test purpose)
    private void paintBoard(){
        char[][] board = getBoard();
        for(char[] row:board){
            for(char cell:row)System.out.print(cell+SPACE);
            System.out.println();
        }
    }

    //Returns the color of the allied piece
    private char ally() {
        return (isBlack ? BLACKSTONE : WHITESTONE);
    }

    //Returns the color of the enemy piece
    private char enemy() {
        return (isBlack ? WHITESTONE : BLACKSTONE);
    }

    //Inverts the row num
    private int qRow(String row) {
        int nRow = Integer.parseInt(row);
        return height-nRow;
    }
    
    //Translate the col
    String Columnas = "ABCDEFGHJKLMNOPQRSTUVWXYZ";
    private int qCol(String col){
        return Columnas.indexOf(col);
    }
    
    //Returns the size of the board
    public HashMap<String, Integer> getSize() {
        HashMap<String, Integer> devol = new HashMap<>();
        devol.put("height", this.height);
        devol.put("width", this.width);
        return devol;
    }

    //Returns the current player's turn
    public String getTurn() {
        return (isBlack ? "black" : "white");
    }

    //Resets the game
    public void reset() {
        newBoard(height, width);
    }

    //Method that processes the move's array
    public void move(String... args) throws IllegalArgumentException {
        for (String mov : args) {
            try {
                stonePut(mov);
                isHandicapable=false;
                isBlack = !isBlack;
                paintBoard();//Uncomment for play
            } catch (IllegalArgumentException e) {
                throw e;
            }
        }
    }

    //This method execute the String move (returns int[] for test purpose)
    private int[] stonePut(String strMove) throws IllegalArgumentException {
        String[] move = {strMove.substring(0, strMove.length()-1),strMove.substring(strMove.length()-1)};
        int[] coords = {qRow(move[0]), qCol(move[1])};
        if (isValidMove(coords))return coords;
        else throw new IllegalArgumentException();
    }

    //Evaluates if a move is valid
    private boolean isValidMove(int[] coords) {
        clearLiberties();
        if (coords[0] >= 0 && coords[1] >= 0
                && coords[0] < height && coords[1] < width
                && board[coords[0]][coords[1]] == EMPTYCELL){
            putPosition(coords[0], coords[1], ally());
            movesStack = new ArrayList<String>();
            if(removekills(coords)||surroundingLiberties(coords,ally()) > 0){
                turnMoves.push(movesStack);
                boolean isKO=true;
                if((isBlack?blackLastMove.get(blackLastMove.size()-1):
                        whiteLastMove.get(whiteLastMove.size()-1))==null)isKO=false;
                else for(int i=0;i<board.length;i++)
                    if(!Arrays.equals(board[i],
                            (isBlack?blackLastMove.get(blackLastMove.size()-1)[i]:
                                    whiteLastMove.get(whiteLastMove.size()-1)[i])))isKO=false;
                char[][] arr= new char[height][width];
                for(int i=0;i<board.length;i++)System.arraycopy(board[i], 0, arr[i], 0, board[i].length);
                if(isBlack)blackLastMove.push(arr);
                else whiteLastMove.push(arr);
                if(isKO){
                    isBlack = !isBlack;
                    rollBack(1);
                    return false;
                }
                return true;
            }
            else{
                putPosition(coords[0], coords[1], EMPTYCELL);
                return false;
            }
        }else return false;
    }

    //Removes pieces without liberties (enemy one's)
    private boolean removekills(int[] coords) {
        boolean removed = false;
        movesStack.add(ally()+SPACE+ADD_STONE+SPACE+coords[0]+SPACE+coords[1]);
        clearLiberties();
        if (coords[0]>0&&board[coords[0]-1][coords[1]]==enemy()&&surroundingLiberties(new int[]{coords[0]-1,coords[1]},enemy())==0){
            for(String stone:Comprobados){
                int row=Integer.parseInt(stone.split(SPACE)[0]);
                int col=Integer.parseInt(stone.split(SPACE)[1]);
                putPosition(row, col, EMPTYCELL);
                movesStack.add(enemy()+SPACE+REM_STONE+SPACE+row+SPACE+col);
                removed = true;
            }
        }
        clearLiberties();
        if (coords[0]<height-1&&board[coords[0]+1][coords[1]]==enemy()&&surroundingLiberties(new int[]{coords[0]+1,coords[1]},enemy())==0){
            for(String stone:Comprobados){
                int row=Integer.parseInt(stone.split(SPACE)[0]);
                int col=Integer.parseInt(stone.split(SPACE)[1]);
                putPosition(row, col, EMPTYCELL);
                movesStack.add(enemy()+SPACE+REM_STONE+SPACE+row+SPACE+col);
                removed = true;
            }
        }
        clearLiberties();
        if (coords[1]>0&&board[coords[0]][coords[1]-1]==enemy()&&surroundingLiberties(new int[]{coords[0],coords[1]-1},enemy())==0){
            for(String stone:Comprobados){
                int row=Integer.parseInt(stone.split(SPACE)[0]);
                int col=Integer.parseInt(stone.split(SPACE)[1]);
                putPosition(row, col, EMPTYCELL);
                movesStack.add(enemy()+SPACE+REM_STONE+SPACE+row+SPACE+col);
                removed = true;
            }
        }
        clearLiberties();
        if (coords[1]<width-1&&board[coords[0]][coords[1]+1]==enemy()&&surroundingLiberties(new int[]{coords[0],coords[1]+1},enemy())==0){
            for(String stone:Comprobados){
                int row=Integer.parseInt(stone.split(SPACE)[0]);
                int col=Integer.parseInt(stone.split(SPACE)[1]);
                putPosition(row, col, EMPTYCELL);
                movesStack.add(enemy()+SPACE+REM_STONE+SPACE+row+SPACE+col);
                removed = true;
            }
        }
        clearLiberties();
        return removed;
    }

    //Puts a stone
    private void putPosition(int x, int y, char stone) {
        board[x][y] = stone;
    }

    //Undo moves in the Stack
    private void undoMove(ArrayList<String> moves) {
        for (String strMove : moves) {
            if (!strMove.equals(PASS)) {
                String[] move = strMove.split(SPACE);
                int[] coords = {Integer.parseInt(move[2]), Integer.parseInt(move[3])};
                if (move[1].charAt(0) == REM_STONE) {
                    putPosition(coords[0], coords[1], move[0].charAt(0));
                } else {
                    putPosition(coords[0], coords[1], EMPTYCELL);
                }
            }
        }
    }

    //Returns the cell status
    public char getPosition(String pos) {
        String[] move = {pos.substring(0, pos.length()-1),pos.substring(pos.length()-1)};
        int[] coords = {qRow(move[0]), qCol(move[1])};
        return board[coords[0]][coords[1]];
    }

    //Puts i handicap stones
    public void handicapStones(int i) throws IllegalArgumentException {
        if(i<1 || i>9 || !isHandicapable)throw new IllegalArgumentException();
        if (height == 9 && width == 9) {
            for(int j=0;j<i;j++){
                int[] coords = {Integer.parseInt(hand9.get(j).split(SPACE)[0]),
                                Integer.parseInt(hand9.get(j).split(SPACE)[1])};
                putPosition(coords[0], coords[1], BLACKSTONE);
                        }
        } else if (height == 13 && width == 13) {
            for(int j=0;j<i;j++){
                int[] coords = {Integer.parseInt(hand13.get(j).split(SPACE)[0]),
                                Integer.parseInt(hand13.get(j).split(SPACE)[1])};
                putPosition(coords[0], coords[1], BLACKSTONE);
                        }
        } else if (height == 19 && width == 19) {
            for(int j=0;j<i;j++){
                int[] coords = {Integer.parseInt(hand19.get(j).split(SPACE)[0]),
                                Integer.parseInt(hand19.get(j).split(SPACE)[1])};
                putPosition(coords[0], coords[1], BLACKSTONE);
                        }
        } else throw new IllegalArgumentException();
        isHandicapable = false;
    }

    //Passes the turn
    public void passTurn() {
        ArrayList<String> pass = new ArrayList<>();
        pass.add(PASS);
        turnMoves.push(pass);
        if(isBlack)blackLastMove.push(null);
        else whiteLastMove.push(null);
        isBlack = !isBlack;
        isHandicapable = false;
    }

    //Board goes back i turns
    public void rollBack(int i) throws IllegalArgumentException{
        if(i>turnMoves.size())throw new IllegalArgumentException();
        while (i > 0) {
                isBlack = !isBlack;
                undoMove(turnMoves.pop());
                if(isBlack) blackLastMove.pop();
                else whiteLastMove.pop();
                if(turnMoves.isEmpty())isHandicapable=true;
            i--;
        }
        paintBoard();//Uncomment for play
    }

    //Resets liberties counters
    private void clearLiberties(){
        liberties = 0;
        Comprobados = new ArrayList<>();
    }
    
    //Returns the group's liberties
    public int surroundingLiberties(int[] coords,char stone) {
        Comprobados.add(coords[0] +SPACE+ coords[1]);
        ArrayList<int[]> friends = new ArrayList<>();
        if (coords[0] == 0 && coords[1] > 0 && coords[1] < width - 1) {
            if (board[coords[0] + 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] + 1, coords[1]});
            } else if (board[coords[0] + 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] - 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] - 1});
            } else if (board[coords[0]][coords[1] - 1] == '.') {
                liberties++;
            }
            if (board[coords[0]][coords[1] + 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] + 1});
            } else if (board[coords[0]][coords[1] + 1] == EMPTYCELL) {
                liberties++;
            }

        } else if (coords[0] > 0 && coords[0] < height - 1 && coords[1] == 0) {
            if (board[coords[0] - 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] - 1, coords[1]});
            } else if (board[coords[0] - 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0] + 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] + 1, coords[1]});
            } else if (board[coords[0] + 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] + 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] + 1});
            } else if (board[coords[0]][coords[1] + 1] == EMPTYCELL) {
                liberties++;
            }

        } else if (coords[0] == height - 1 && coords[1] > 0 && coords[1] < width - 1) {
            if (board[coords[0] - 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] - 1, coords[1]});
            } else if (board[coords[0] - 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] - 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] - 1});
            } else if (board[coords[0]][coords[1] - 1] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] + 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] + 1});
            } else if (board[coords[0]][coords[1] + 1] == EMPTYCELL) {
                liberties++;
            }

        } else if (coords[0] > 0 && coords[0] < height - 1 && coords[1] == width - 1) {
            if (board[coords[0] - 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] - 1, coords[1]});
            } else if (board[coords[0] - 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0] + 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] + 1, coords[1]});
            } else if (board[coords[0] + 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] - 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] - 1});
            } else if (board[coords[0]][coords[1] - 1] == EMPTYCELL) {
                liberties++;
            }

        } else if (coords[0] == 0 && coords[1] == 0) {
            if (board[coords[0] + 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] + 1, coords[1]});
            } else if (board[coords[0] + 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] + 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] + 1});
            } else if (board[coords[0]][coords[1] + 1] == EMPTYCELL) {
                liberties++;
            }

        } else if (coords[0] == height - 1 && coords[1] == 0) {
            if (board[coords[0] - 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] - 1, coords[1]});
            } else if (board[coords[0] - 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] + 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] + 1});
            } else if (board[coords[0]][coords[1] + 1] == EMPTYCELL) {
                liberties++;
            }

        } else if (coords[0] == height - 1 && coords[1] == width - 1) {
            if (board[coords[0] - 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] - 1, coords[1]});
            } else if (board[coords[0] - 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] - 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] - 1});
            } else if (board[coords[0]][coords[1] - 1] == EMPTYCELL) {
                liberties++;
            }

        } else if (coords[0] == 0 && coords[1] == width - 1) {
            if (board[coords[0] + 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] + 1, coords[1]});
            } else if (board[coords[0] + 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] - 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] - 1});
            } else if (board[coords[0]][coords[1] - 1] == EMPTYCELL) {
                liberties++;
            }

        } else {
            if (board[coords[0] - 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] - 1, coords[1]});
            } else if (board[coords[0] - 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0] + 1][coords[1]] == stone) {
                friends.add(new int[]{coords[0] + 1, coords[1]});
            } else if (board[coords[0] + 1][coords[1]] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] - 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] - 1});
            } else if (board[coords[0]][coords[1] - 1] == EMPTYCELL) {
                liberties++;
            }
            if (board[coords[0]][coords[1] + 1] == stone) {
                friends.add(new int[]{coords[0], coords[1] + 1});
            } else if (board[coords[0]][coords[1] + 1] == EMPTYCELL) {
                liberties++;
            }
        }
        if (liberties > 1) {
            return liberties;
        } else {
            for (int[] i : friends) {
                if (!Comprobados.contains(i[0] +SPACE+ i[1])) {
                    liberties = surroundingLiberties(i,stone);
                }
            }
        }
        return liberties;
    }
}

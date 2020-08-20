# Chess

Implemented 2 player Chess game using Object Oriented programming concepts.

Implemented **Coordinate notation** to annotate movement of pieces 

For example, 

1) To move a pawn from e2 to e4, enter starting position as 'e2' and finishing position as 'e4'.

2) To castle kingside, enter starting position as 'e1' and finishing position as 'g1'.

The game takes user input of moves and executes them **upon validation**. 
The program also incorporates file handling and records all the played games in a text file.

The game is continued till someone is 'checkmated', the game ends in stalemate or both the players agree to a draw.
The players may save an incomplete game and may continue it later.

If the users choose to start a new game before resuming an incomplete game, the previously saved game is overwritten by the new game.

**En-passant** isn't implemented in the game due to the requirement of storing the previous moves.

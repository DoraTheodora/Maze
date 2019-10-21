# Maze
Maze Game in C++
2d Life

Components:

1.	The Maze
The maze is stored as an array of chars . ‘0’ for a ground and ‘1’ for a wall. Use the sample program as a starting point.The user enters a key to update the maze and redraw it. 

2. 	The walkers
Each walker is represented by an ‘2’ in the array.

At the start of each game the walkers are randomly placed in the ground(anything that’s not a wall). The walkers cannot be placed on a maze position that already contains a plant or another walker. 
With each update the walker randomly chooses a direction to move (it can move in any of the 8 adjoining maze positions).  If there isn't a wall in its way it will move into the next maze position. If it cannot move it tries another direction  until it can move. If you have tried all directions and it still can’t move it just stay where it is.
After a walker has moved it must return the previous position to a ‘0’ for ground.

If the walker hits a plant ( see below) the plant will be removed from the 2D Life.

3: The plants

The plant is represented by a char from ‘a’ to ‘y’ in the array.
The plants are randomly placed on the maze and they  just stay in one spot. At each update the plant counts back one at a time from ‘y’  down to ‘a’..e.g. y, x,v,....a. When it reaches ‘a’ it cycles back to ‘y’ . The plant only updates it’s value only if it can’t ‘see’ a walker . A plant can see a walker if there is  a walker  in the same row or the same column,and if there is not  a wall between it and the walker.

4. Wander forever
Life is over when all the plants are gone, only walkers wandering the maze forever.
Instead of printing the Maze, print “Life Simulation Complete”.

5. Bonus :
Have a look at conway's game of life (https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life)  and grow the plants in a similar way.










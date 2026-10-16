*This project has been created as part of the 42 curriculum by <aielo>aielo and <uponci>uponci.*

## Description 

Using miniLibX and ray-casting principles we must create a “realistic” 3D graphical representation of a maze from a first-person perspective, modelled on the style of Wolfenstein 3D.

## Instructions
The program displays the image in a window and respects the following rules:
1. The left and right arrow keys of the keyboard must allow you to look left and
right in the maze.
2. The W, A, S, and D keys must allow you to move the point of view through
the maze.
3. Pressing ESC must close the window and quit the program cleanly.
4. Clicking on the red cross on the window’s frame must close the window and
quit the program cleanly.

## Resources
Raycasting is a rendering technique used to create a 3D perspective in a 2D map.  

It works by projecting rays from the player’s position at regular angular intervals across their field of view.<br>
Each ray travels until it hits a wall, and the distance determines the apparent height of the wall on the screen.<br>
<br>

https://en.wikipedia.org/wiki/Ray_casting

https://lodev.org/cgtutor/raycasting.html

https://devabdilah.medium.com/3d-ray-casting-game-with-cub3d-7a116376056a

https://medium.com/@elmehdielgarouaz/from-flat-to-fantastic-how-cub3ds-ray-casting-engine-transforms-2d-into-3d-647ff2f7fd4f

<br>
AI was used to handle the mathematics involved in ray casting and the DDA algorithm.

---

Part of my [42 School project collection](../../README.md).

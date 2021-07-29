# cub3d
My first RayCaster with miniLibX

### Summary:
This project is inspired by the world-famous Wolfenstein 3D game, which was the first FPS ever. It will enable you to explore ray-casting. Your goal will be to make a dynamic view inside a maze, in which you’ll have to find your way.  
What I learned:  
Rigor, use of C, use of basic algorithms, information, research, etc.  
As a graphic design project, cub3D will enable you to improve your skills in these areas: windows, colors, events, fill shapes, etc.

### Context
This project was done as part of 42's Software Engineer program. Project was passed the 3rd March 2020.

### Configuration
Configurable elements in this file include:  
- R (for game Resolution): length and height of the screen, in pixels.
- NO (for North texture): path to texture file of object facing north in the game.
- SO (for South texture)
- WE (for West texture)
- EA (for East texture)
- S (for Sprite): path to texture file for sprites objects
- F (for Floor colors): RGB components of the floor color (numbers between 0 and 255)
- C (for Ceiling colors): RGB components of the ceiling color (numbers between 0 and 255)
- Map Configuration:
  - 1 indicates a 1x1 plain wall
  - 0 indicate no wall
  - N or W or E or S indicates the position and facing direction of the player
  - 2 indicates the position of a sprite
The map.cub has a basic configuration.

### How to run

##### Mandatory subject
Use the Makefile to compile the project  
```
make
```
Launch the project
```
./Cub3D map_example.cub
```
Mandatory subject include:  
- Unique color for floor and ceiling
- Unique wall texture for each cardinal directions
- Showing a unique immobile sprite
- Moving in the map with keyboard and no collisions

![cub3d image](https://user-images.githubusercontent.com/35499080/127504731-75e0d0dd-b31a-4dc0-902c-f06a668f878f.png)

##### Bonus subject
Use the Makefile to compile the project  
```
make bonus
```
Launch the project
```
./Cub3D map_example.cub
```
Bonus subject include:  
- Wall collisions
- Sprite animation and trying to kill you
- HUD with healtbar
- Firearm to kill enemies
- Deathscreen
- Mouse to change directions
- Top left corner minimap with FOV
- Sprint

![cub3d bonus image](https://user-images.githubusercontent.com/35499080/127504600-4762278c-3092-4b64-9d65-6414b395454d.png)

### How to play

ESC: quit the game  
W: move forward  
S: move backward  
A: strafe left  
D: strafe right  
<-: rotate left  
->: rotate right  

Bonus subject :  
Mouse to look left or right  
Shift to sprint

### Known Issues
User can experience FPS drop when:  
 - Sprite is near the player
 - Resolution is large
Enemies go through walls and follow you in staight line only if you look at them.

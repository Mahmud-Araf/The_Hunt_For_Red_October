# The_Hunt_For_Red_October
CSE-1211 Lab Project (Fall 2022)

![Intro image](assets/obj%20%26%20background/mainmenubg.png)

## Outline
This is an academic group project of the course CSE-1211 for 1st year 2nd semester in the Department of Computer Science and Engineering of the Univeristy of Dhaka. The game project is developed for only **Linux** as of now using **SDL2**

## Members:
1. Abrar Eyasir , Roll 12
2. Abdullah Al Mahmud , Roll 15
3. Saadman Moyeed , Roll 33
## In Details
**The Hunt For Red October** is a 2D Third-person Shooting game. The game project is inspired by the 1990 movie of the same name [The Hunt for Red October](https://en.wikipedia.org/wiki/The_Hunt_for_Red_October_(film)).

The game has two levels till now **Easy** and **Hard** . Both levels are endless. 

In each level the protagonist submarine **Red October** has to avoid being hunted by enemy submarines and ships and has to shoot the enemys with torpedos and missiles to score.
The game will over when life becomes zero.

I will try to add new levels and challenges in the game in near future.

## Pre-requisites
**For Debian and Debian based distributions:**
* ```g++```
* ```libsdl2-image-dev``` 
* ```libsdl2-ttf-dev```
* ```libsdl2-mixer-dev```
* ```libsdl2-dev``` 
or equivalent packages for other distributions.

## Running the game

### using Terminal
After opening the terminal in the folder where the game folder is simply use the command `make all` or `./a.out` or 
write 
```g++ src/*.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer && ./a.out```
to run the game.

### using Unity Launcher
open the **The Hunt For Red October.desktop** using any text editor (gedit,nano,vim,vscode etc.).

In the file assign the full path of `a.out` in `Exec`. 
Like this:

```Exec=/home/user-name/The_Hunt_For_Red_October/a.out```

then assign the full path of this game folder in `Path`. 
Like this:

```Path=/home/user-name/The_Hunt_For_Red_October/```

finally assign full path of an icon image in `Icon`. 
Like this:

```Icon=/home/user-name/The_Hunt_For_Red_October/assets/obj & background/mainmenubg.png```

After that move or paste the **The Hunt For Red October.desktop** file in desktop and right clicking click on **Allow Launching**
and in **Properties** make sure you ticked **Allow executing as program** in the **Permissions** section.
Now, double clicking will launch the game. 

## Hope you will enjoy
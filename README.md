# The_Hunt_For_Red_October

CSE-1211 Lab Project (Fall 2022)
---

<hr>

![Intro image](assets/obj%20%26%20background/mainmenubg.png)

<hr>

## Current Version

<hr>

1.1

<hr>

## Outline

<hr>

This is an academic project of the course CSE-1211 for 1st year 2nd semester in the Department of Computer Science and Engineering of the Univeristy of Dhaka. The game project is developed for only **Linux** as of now using **SDL2**

<hr>

## In Details

<hr>

**The Hunt For Red October** is a 2D Third-person Shooting game. The game project is inspired by the 1990 movie of the same name [The Hunt for Red October](https://en.wikipedia.org/wiki/The_Hunt_for_Red_October_(film)).

The game has two levels till now **Easy** and **Hard** . Both levels are endless. 

In each level the protagonist submarine **Red October** has to avoid being hunted by enemy submarines and ships and has to shoot the enemies with torpedos and missiles to score.
The game will over when lives becomes zero.

I will try to add new levels and challenges in the game in near future.

<hr>

## Pre-requisites

<hr>

**For Debian and Debian based distributions:**
* ```g++```
* ```libsdl2-image-dev``` 
* ```libsdl2-ttf-dev```
* ```libsdl2-mixer-dev```
* ```libsdl2-dev``` 
or equivalent packages for other distributions.

<hr>

## Running the game

<hr>

### 1. using Terminal

<hr>

After opening the terminal in the folder where the game folder is simply use the command `make all` or `./a.out` or 
write 

```
g++ src/*.cpp -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer && ./a.out
```
to run the game.

<hr>

### 2. using Unity Launcher

<hr>
open the <b>launcher.desktop</b> using any text editor (gedit,nano,vim,vscode etc.).

In the file assign the full path of `a.out` in `Exec`. 
Like this:

```
Exec=/home/user-name/The_Hunt_For_Red_October/a.out
```

then assign the full path of this game folder in `Path`. 
Like this:

```
Path=/home/user-name/The_Hunt_For_Red_October/
```

finally assign full path of an icon image in `Icon`. 
Like this:

```
Icon=/home/user-name/The_Hunt_For_Red_October/assets/obj & background/mainmenubg.png
```

After that move or paste the **launcher.desktop** file in desktop and right clicking tick on **Allow Launching**
and in **Properties** make sure you ticked **Allow executing as program** in the **Permissions** section.
Now, double clicking the icon / launcher will launch the game.

<hr>

## Video Link:
<hr>

https://youtu.be/7D8OlUxwNgY

<hr>

## Hope you will enjoy

<hr>
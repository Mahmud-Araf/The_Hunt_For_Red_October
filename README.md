# The_Hunt_For_Red_October
This is a cse_1211 project for our 2nd semester of University of Dhaka.

Introduction 

The hunt for Red October is a video game based on the 1990 movie The hunt for Red October released by Tom Clancy. In the game one submarine is engaged in combat with every other submarine and ship. The player submarine can fire missiles and torpedoes at opposing submarines and ships To win, it is necessary to sink every hostile submarine and ship. The game consists of two stages. Comparatively speaking, the first level is a tad simpler than the second. Torpedoes can be fired by the player submarine at the opposing submarines at all times. The game has fascinating features including music, pause, framerate counting, high score saving, shooting torpedoes and missiles, and more.

Story

The 1975 rebellion on board the Soviet destroyer Storozhevoy (also known as Sentry) served as the basis for Tom Clancy's novel The Hunt for Red October. Its ultimate goal was the toppling of Leonid Brezhnev and the Soviet Union. A brilliant young political officer named Valery Sablin took charge of the ship by persuading all of the sailors and half of the officers to set sail for Leningrad, where they would start a new Russian Revolution. Young, the first American to discover the rebellion twenty years ago, and Braden finally reveal the hidden tale using freshly declassified KGB records as well as the Sablin family's files after being suppressed in the Soviet Union for fifteen years.

Objective

The major goals of this project are to properly apply the c/c++ language that we studied this semester in a real-world setting and to gain deeper knowledge of the c/c++ graphical portion. Since SDL2.0 was used to create the game, it also served as a means of learning more about SDL. One of the goals of this project was to write code that was simple to understand and modular enough to allow for easy future development.

In terms of the goals we had for the game, creating an engaging experience was our top priority. Games are proven to maintain your attention when there is little to no friction between the controls and the game systems are fair even if they are challenging; as long as they are cohesive and effectively interact with the player, they should have a large amount of replay value. So, in brief, our goal was to create a game that, despite being constrained in scope and challenging, provided the player with the required tools and functioned as the user intended. Therefore, each game action needed to be explained properly and should reward competence.

Game Features

​​A main menu, instructions page, options menu to switch between settings, basic movement functions, collision detection, high score calculation, score presentation, etc. are all aspects that are common to all video games. As additional special features, the game offers diagonal movement, increasing difficulty with time, full screen,guided mines that follow targets, pause/ unpause game & music, frame rate rendering, mouse-mode gaming and time show . The features are briefly detailed below.

Code that is organized, modularized, transparent, and simple to customize with the appropriate comments.
Debian-based computers may be easily installed using a one-click method. Play Direct Install (bash script will download everything required)
The same performance across all devices and memory-efficient design (if possible to play)
Update One Command Game to the most recent release feature using the "./update.h command"
A loading screen with the game's emblem 
Attractive and dynamic game-control menu choices
Displaying directions in the newly generated window
Levels that are Difficult with Several Types of Enemies
Specifications for the Crispy Sound System and a sound-off switch
100% control, simple but intriguing game theory
High Scores are shown in the newly generated window.Players may use this button to examine the game's high scores and increase their level of internal competition. The high score table may also be cleared by going to options and selecting the clear option.
Powerful GitHub Repository with an educational Readme.md for online code presence. GitHub workflow that follows best practices.

In-Game Special Features
Guided mines that follow the target: The mines launched by the ships follow the main target  submarine. This game feature increases the difficulty for the player to win.
Increasing difficulty with time: After time files, the difficulty level of the game will be increased. More enemy submarines and ships will appear on the screen; then the  game will be much more challenging to play .
Frame rate rendering: One of the most unique features of the game is to count frame rate. 
Time show: There is also a time show feature in the game, showing the time play of the game.
Pause and Unpause game: According to the need, players can pause the game using the space button.
Enemy attack: In level-1, there are enemy submarines who move forward diagonally and launch torpedoes continuously. After scoring 10, the player will be able to play the second level. The level-2 is much more difficult compared to the level-1. More and more numbers of enemy submarines will attack the player , and additionally ships also launch bombs to the player submarine.

Project Files & Modules

The project was broken up into various header files, each of which had a specific purpose. Below is a discussion of these modules.

main.cpp

Using the main() function's game_init(), running(), handleEvents(), utilities_init()   procedures to call a struct Game variable and perform the necessary initialization, running loop, event handling like mainmenu.run(), controls.run(), credit.run(), highscores.run(), gamelevels and gamescores etc.Additionally, by using the destroy window() function like closeMedia(),closeFont() and gameclose() ,we are ending the game.

Preprocessor.hpp

This includes the preprocessor constants that can be changed to adjust various game elements for easier access as well as the libraries used to build the project. Unfortunately, the majority of UI and game elements are dependent on the screen's height and width because window events have made them flexible. We were unable to use numerous preprocessor constants as a result.

global.hpp

These are the variables that are commonly accessed throughout the entire program.Particularly important are the renderer, the window (in this example, a struct), the screen variables, scores, health, screen scaling variables, and numerous boolean variables to guide the program on a more general level. It also includes a function for the main gameplay loop and an enumerated screen for understandable record-keeping of the game's many screens.

close.hpp

This includes all the quit functions including  image, ttf ,music etc. It also contains render and windows destroying functions.

utilities.hpp

This includes all the important features that are either necessary for the fundamental structure or often utilized. This includes start music,pause music, resume music & music handle events options , which set up the project's music systems .Players can pause and resume the music according to their needs. In order to delay a frame by precisely the right amount to lock FPS, OptimizeFPS stores the frametimes from the preceding frame. This serves as a backup feature for systems. There is also a frame rate controlling ,fps-show event. The code for showing the top 5 scores has been implemented in this section by calling scoreboard() function. To show the time played by the player , the timeshow function is called here. In addition,  the code for showing the life of the player has been implemented by calling the lifeshow function.
 
text.hpp

This handles all the functions of ttf font ,font color, load text surface which are necessary for the loading text and also responsible for the color. Mainly white,black & red colors are used here.

stages.hpp

This contains all the prototypes of stages like mainmenu, highscore, credit,gamelevels,gameover, controls. In the main menu , there are layers such as buttons for starting the game, showing high score &  credit , exit game etc. In the high score section, different functions are called such as  scan , print ,save and refresh highscores. In the game levels section, three functions  are called such as game objective function, run level one and run level two functions. In the gameover structure, a handle event function is called which will eventually end the game. In the credit structure, there are the descriptions of the person who contributed to build the game.

obj-functions.hpp

This contains structures of torpedo, missile, mine, game background, player, enemy submarine & enemy ship. In these structures, a number of functions are initialized and rendered so that players can launch torpedo, missiles smoothly.  

media.hpp

This manages how the game's textures are loaded. The slowest operations are those using I/O. Because the application is very short in size overall, we load all graphics and music at the beginning, which increases the program's responsiveness even if memory use is high and the first loading takes a while. To make this process simpler, we developed the loadTex method, which accepts the string representing the file location as an input and loads the texture in a surface using the SDL Image's IMG Load function to produce a texture from that surface. Utilizing library functions allows for music loading. Finally this also contains the close function which closes the initialized systems and frees memory using library functions.

init.hpp

initialized every subsystem utilized during the whole game (i.e. audio, image, font etc).

header.hpp

This contains header files containing necessary information such as sdl2 & c++ library header, functions & variables to initialize program, global variables , media related functions & textures , all functions & variables related to text color, all game objectives & game functionalities, structures & functions for game stages , close & free sdl2 initialization.

Team Member Responsibilities

Abdullah Al Mahmud ,Team Leader
Logic Design and implementation
Version control(Git/Github)
Collision detection
Structured Game Source Code Writing in C
Enemy Attack
Player movement
Code testing & Bug fixing
Game development & update

Abrar Eyasir Linkedin Profile  Roll No: FH-12(Reg. No: 2020015622)
Logic Design
Graphics Designing(Photopea)
Basic UI
UI assets
Adding sound effects & background music
Showing scores, lives etc to the screen
High score calculation and printing
Structured Game Source Code Writing in C
Code testing & Bug fixing


Saadman Moyeed
Mouse Mode
Window events
Code testing & Bug fixing
Initialization of SDL and assets
Game pause 
Difficulty level
Logic Design
UI navigation with mouse & keyboard

Platform, Library & Tools

C/C++ : The game's basic code was written in C!
VS Code: Free. Powered by an open source but strong IDE!
SDL2: low level access cross-platform programming library is meant to offer!
Git/Github: utilizing Git for software development and version control!
Photopea: using photopea to edit the images.

Limitations

As it is a 2D game, the collisions between submarines seem unreal.
The characters' movements lack appealing animation, and the visuals have not yet been produced.
After 5 mins of running, the game becomes slow.
Because it is solely coded in C, no enhanced C++ functionality is accessible.
No object-oriented code was utilized or produced; it was organized and written in C.
There are only two levels.
The variety of enemy strikes is still insufficient.
Game replay is currently in development.

Future Plan
In the future, we intend to solve the difficulties mentioned in the restriction section, such as changing the game's progression-type structure from a level-completion one to one with separate levels. To make the game more entertaining, additional player and opponent assaults should be included. In keeping with the accessibility concept, we'd want to shortly include controller support. The game will first be built in 2D SDL2/C++ for the project, but we want to subsequently make it a 3D game that runs on all platforms (Android, IOS, Windows) utilizing tools like Unreal Engine, Unity, Autodesk, Blender, etc.

Github Repository
https://github.com/eyasir2047/The_Hunt_For_Red_October

Youtube Video Intro Link

References
SDL Learning Sources
https://lazyfoo.net/tutorials/SDL/
https://www.packtpub.com/product/sdl-game-development/9781849696821
https://www.libsdl.org/

Free Images Sources
https://www.freepik.com/

License
Freeware, the Hell Yeah!

Conclusion
This game-project taught us teamwork, stress management, peer communication, and many other crucial skills that a software engineer should possess in addition to new language and technology. I hope we will be able to apply these lessons to our lives in the future.


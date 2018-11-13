# Players gonna play

# player class
Using the `player` class that is already created for you, create 2 member functions:
### player Display Player Method
Create a member function `display_player` that prints out the name, job, and level of the player, as
shown in the output below.
### player Fight Method
Create a member function `fight` that passes in a `player` object and returns an `int` value. This
member function should check the level of the `player` object that called this method against the
level of the `player` object that was passed in. If the level of this object is greater than the
level of the object passed in, return a value of `1`. If the level is less than, return a value of `2`.
Otherwise, return a value of `3`.

# player_log class
Create a class called `player_log` that has the following:
### player_log Private Member Variables
Your class should have 3 private member variables, a pointer to the `player` object (\_source_player), an `int` for a size (\_size), and an `int` for a counter (\_counter).
### player_log Default Constructor
Create a default constructor that initializes a value of `0` to the counter, and a value of `3` to the size.
Initialize a new dynamically allocated array using the value of the size.
### player_log Non-Default Constructor
Create a non-default constructor that passes in an `int` for the size. Initialize a value of `0` to the counter,
and initialze the value passed in to the size. Initialize a new dynamically allocated array using the value of the
size.
### player_log Accessors
Create 2 accessors called `size` and `counter`.
### player_log Add Player Method
Create a member function called `add_player` that passes in a `player` object as a parameter. This member function
should store the object passed in into the dynamically allocated array, and display a message (as shown below) if the
object is successfully stored. If the array is full, the object will not be added in and a different message (as shown
below) will be displayed.
### player_log Show Log Method
Create a member function called `show_log` that will display each player's number and call the `player` object's
`display_player` method to display the player attribute (as shown below).
### player_log Show Fight Result Method
Create a member function called `show_fight_result` that will have all `player` objects in the array
battle it out using the `player` object's `fight` method.  
Here is how the fight will be ordered:  
Given an array of size 5 player objects [0, 1, 2, 3, 4], your member function should have
the objects fight like this:
```
0 fights 1
0 fights 2
0 fights 3
0 fights 4
1 fights 2
1 fights 3
1 fights 4
2 fights 3
2 fights 4
3 fights 4
```
Look carefully at the output shown below for the full output.
### player_log Destructor
Create a destructor that will delete the dynamically allocated array and free the memory.

*NOTE*: The main function will be provided. Do not edit `main.cpp`

Output
```
Billy Registered
Marie Registered
Jack Registered
Bob Registered
List is full. Cannot register player.

Player 1
Name: Billy
Job: Warrior
Level: 100

Player 2
Name: Marie
Job: Mage
Level: 30

Player 3
Name: Jack
Job: Assassin
Level: 150

Player 4
Name: Bob
Job: Cleric
Level: 100

Billy defeated Marie
Billy lost to Jack
Billy and Bob were evenly matched
Marie lost to Jack
Marie lost to Bob
Jack defeated Bob
```

# Submission checklist
1. Created function prototype
1. Created function implementation
1. Call function in the driver
1. Followed the [proper file structure for using functions](https://github.com/ILXL-guides/function-file-organization)
1. Compiled and ran the driver
1. No errors on the unit test (make test)
1. No errors on the style check (make stylecheck)
1. No errors on the format check (make formatcheck)

# Code evaluation
Open the terminal and navigate to the folder that contains this exercise. Assuming you have pulled the code inside of `/home/student/labex02-tuffy` and you are currently in `/home/student` you can issue the following commands

```
cd labex02-tuffy
```

You also need to navigate into the problem you want to answer. To access the files needed to answer problem 1, for example, you need to issue the following command.

```
cd prob01
```

When you want to answer another problem, you need to go back up to the parent folder and navigate into the next problem. Assuming you are currently in `prob01`, you can issue the following commands to go to the parent folder then go into another problem you want to answer; `prob02` for example.

```
cd ..
cd prob02
```

Use the `g++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `player_log.cpp` and `main.cpp` into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
g++ -std=c++17 player_log.cpp main.cpp -o main
./main
```

You can run one, two, or all the commands below to `test` your code, `stylecheck` your code's design, or `formatcheck` your work. Kindly make sure that you have compiled and executed your code before issuing any of the commands below to avoid errors.

```
make test
make stylecheck
make formatcheck
```

A faster way of running all these tests uses the `all` parameter.

```
make all
```

# Submission
1. When everything runs correctly,  let's copy your code into the Github repository. The first step is to add your code to what is called the staging area using git's `add` command. The parameter after `add` is the name of the file you want to add. There are cases when you have multiple changed files, so you can just type . (period) to add all modified files.

    ```
    git add .
    ```
1. Once everything is in the staging area, we use the `commit` command to tell git that we have added everything we need into the staging area.

    ```
    git commit
    ```
1. In case it asks you  to configure global variables for an email and name, just copy the commands it provides then replace the dummy text with your email and Github username.

    ```
    git config --global user.email "tuffy@csu.fullerton.edu"
    git config --global user.name "Tuffy Titan"
    ```
    When you're done, make sure you type `git commit` again.    
1. Git will ask you to describe what you have added to the staging area. By default, you will use a command-line based editor called *nano*. Go ahead and provide a description then press <kbd>Ctrl</kbd> + <kbd>x</kbd> to exit. Press <kbd>Y</kbd> to confirm that you want to make changes and then press <kbd>Enter</kbd>.
1. Lets push all changes to the Github repository using git's `push` command. Provide your Github username and password when you are asked.

    ```
    git push
    ```
1. When you finish the exercise, go back to Titanium and click on the `Add submission` button in the lab exercise page. Provide a short message in the text area such as "finished lab exercise" and click on `Save changes`. Finally click on `Submit assignment` to inform your instructor that you are done.

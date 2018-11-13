# committee class
Make a program that constructs a 10 person committee and assign leadership roles to certain members by using `pointers` and `references`

Then at the end, using the accessors, output the name of the members in leadership positions.

## member class
This class is already made for you. Here is a rundown of the member functions and member variables you will need to use.
### Data members
Create a class called `member`. It will have the following data members

1. `_name` which is a `string` that will be the name of the person.
1. `_district_number` which is a `int` that is the district that the person represents
### Member functions
#### Public Methods
##### constructor
The constructor initializes the following variables

For parameters it needs:
1. `string name` for the name of the member.
1. `int district_number` for the district number of the member.

and it initializes the data members with the corresponding parameters.

##### Accessors and Mutators
The class provides accessors and mutators for all its data members.

## committee class
### Private Data members
Create a class called `committee`. It will have the following data members

1. `_members` which is an array of `member` that is of size `10`. This will be the members of our committee
1. `_president` which is a *pointer* to a `member` of the array. Whoever this pointer is pointing is the president.
1. `_vice_president` which is a *pointer* to a `member` of the array. Whoever this pointer is pointing is the vice president.
1. `_treasurer` which is a *pointer* to a `member` of the array. Whoever this pointer is pointing to is the treasurer.

### int find_person(string name)
This is a private member function that uses the parameter `name` for finding the index of the array containing a member whose name matches the parameter. If the person "Stan" was located at index 0 of the array, then this function should return 0.

If it cannot find the person on the list of members, then it should just return `0` to refer to the first person on the list.

### Member functions
#### Public Methods
##### default_constructor
This constructor is partially made for you already. It receives inputs from the user and stores them into variables `name` and `district`. You will need to complete the constructor by making sure it properly assigns the `name` and `district` variables to the `member` objects in the array. Set the `_president`, `_vice_president` and `_treasurer` pointers to `nullptr`.

##### Member Functions
###### void set_president(string name), void set_vice_president(string name), and void set_treasurer(string name)
These sets of functions all do the same thing, they point the `_president`, `_vice_president` and `_treasurer` pointers to the members on the list who have been given these roles.
For Example: if executed
```
set_president("Stan Stokes")
```
Then the first step would to be to *find* where `"Stan Stokes"` is on our array of members.
Do we have a function that *finds* out where members are on our array based on a `string` name?

Once you have figured out what index the member we are promoting to president is at. Assign the pointer `_president` such that it points to the element in the array that the member named `"Stan Stokes"` is located at.

Likewise this should be done for the other function such as `set_vice_president` and `set_treasurer`.

###### void set_leadership()
This function is also almost completed for you. This will have you set all of the leadership positions in one function. Already given to you is the format in which inputs will be received. Using the variables in that function, set all of the leadership positions.


###### string get_member_name(int index)
This should return the name of member at the `index` of the array.

Remember, you should be returning a `string` not a whole `member` object.

###### string president_name(), string vice_president_name(), and string treasurer_name()
All of these functions should return the name of whoever is the president.
If you take `string president_name()` for example.

Using the `_president` pointer, access the member function that will `return` the name of the `member` that `_president` would be pointing to, and return it.

Likewise, you should do this with `string vice_president_name()` and `string treasurer_name` as well. Those should return the names of the vice president and treasurer


# Sample Output
```
Lets construct our committee.
Who are we adding to the committee? Martha Ty
What is their district number?: 24
Who are we adding to the committee? John Politico
What is their district number?: 22
Who are we adding to the committee? Catherine Stark
What is their district number?: 15
Who are we adding to the committee? Jim Stokes
What is their district number?: 34
Who are we adding to the committee? Elliott Cresswell
What is their district number?: 9
Who are we adding to the committee? Ivan Buxton
What is their district number?: 10
Who are we adding to the committee? Kyla Cummings
What is their district number?: 5          
Who are we adding to the committee? Ahmad Craig
What is their district number?: 54
Who are we adding to the committee? Billie-Jo Hartman
What is their district number?: 87
Who are we adding to the committee? Verity Wilde
What is their district number?: 44
Who do you want to make the president? Martha Ty
Who do you want to make the vice-president? Jim Stokes
Who do you want to make the treasurer? Ivan Buxton
The President is: Martha Ty
The Vice President is: Jim Stokes
The Treasurer is: Ivan Buxton

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
cd labex08-tuffy
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

Use the `g++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `committee.cpp` and `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
g++ -std=c++17 committee.cpp main.cpp -o main
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

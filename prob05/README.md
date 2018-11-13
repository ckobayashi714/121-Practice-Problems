# The doctors_schedule Class
## int main
`main()` is almost completed for you, all `cout` statements needed are already included.
Other `cout` statements are contained within the constructor of the `doctors_schedule` class.

You will need to complete the following functionalities:

1. construct a `doctors_schedule` object
1. complete the `while` loop so it iterates through appointments until the doctor is finished with all appointments
1. output the current appointment
1. move on to the next appointment

## appointment
This class is completed for you. You will need to interface with this class to initialize your appointments.

### Data members
1. `_name` which is a `string` that represents WHO this appointment is with.
1. `_location` which is a `string` that represents WHERE this appointment is.
1. `_time` which is a `string` that represents WHEN this appointment is.

### Member functions
This has the necessary accessors and mutators needed to get and set the data members above.

Additionally it has the `string to_string()` function that will take all the class' data members, and output them into a formatted `string` that will be used in `doctors_schedule`'s output.

## doctors_schedule
### Data members
Create a class called `doctors_schedule`. It will have the following data members

1. `_appointments` which is a pointer of type `appointment` that points to a dynamically allocated array.
1. `_num_of_appointments` which is an `int` that stores the total number of appointments scheduled.
1. `_current_appointment_num` which is an `int` that tracks the index of the current appointment (on the array).

For example, if we are at the first appointment, then `_current_appointment_num` is equal to 0.
If we are at the second appointment, then `_current_appointment_num` would be equal to 1.

### Member functions
#### Public Methods
##### non-default constructor
This constructors has already been partially created for you. It should take only 1 parameter called `num_of_appointments` which is an `int` that represents the number of doctor's appointments.

`num_of_appointments` should be used to dynamically allocate an array of `appointments` of that size. The constructor should also initialize the member variable `_num_of_appointments` to `num_of_appointments` so it can track the number of appointments scheduled for that day.

Then we need to ask the user about some information regarding appointments.

*Hint: Since things like names and locations can be more than one word, do we use `getline` or `>>`?*

You will need to get the following inputs:

1. Who is this appointment with?
1. Where is this appointment at?
1. What time is this appointment?

All of these should be stored as `string`s.

For each input, create an `appointment` object and assign the values provided by the user then store it in the array.

##### destructor
If your constructor dynamically allocates an array, what should be done with the dynamically allocated data when the object is destroyed?

##### accessors
Make functions that will return each of our data members.

1. `int num_of_appointments()` return the total amount of appointments you have for this schedule.
1. `int current_appointment_num` returns the current appointment number. For example, if you are on the first appointment, `_current_appointment_num` should be 0.
1. `bool finished()` returns `true` if all appointments for the day are finished and `false` otherwise. (Hint: this has to do with `_num_of_appointments` and `_current_appointment_num`)

##### Member functions
1. `string next_appointment()` which will just move our `_current_appointment_num` to the next appointment.
1. `string current_appointment()` returns the `string` that represents the current appointment. (Hint: use the member function in `appointment` that creates the string for you.)

# Sample Output
```
How many appointments does the doctor have?: 4
Who is this appointment with?: John Doe
Where is this appointment?: Starbucks
What time is this appointment?: 10:30 am


Who is this appointment with?: Waldo
Where is this appointment?: TSU
What time is this appointment?: 12:00 pm


Who is this appointment with?: Paul Inventado
Where is this appointment?: CS-101
What time is this appointment?: 2:30 pm


Who is this appointment with?: Hasan Minhaj
Where is this appointment?: Pollack Library
What time is this appointment?: 4:00 pm


You have an appointment with John Doe at 10:30 am, Starbucks
Press enter to move on to the next appointment
You have an appointment with Waldo at 12:00 pm, TSU
Press enter to move on to the next appointment
You have an appointment with Paul Inventado at 2:30 pm, CS-101
Press enter to move on to the next appointment
You have an appointment with Hasan Minhaj at 4:00 pm, Pollack Library
Press enter to move on to the next appointment
Good work today, doctor!
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

Use the `g++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `doctors_schedule.cpp` and `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
g++ -std=c++17 doctors_schedule.cpp main.cpp -o main
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

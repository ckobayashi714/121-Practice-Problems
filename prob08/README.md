# Manager Class
Create a class called `manager` that has the following:
### manager Private Member Variable
Your class should have 1 private member variable, an `employee` pointer. The `employee` object
will be provided for you, so you **DO NOT** need to create your own.
### manager Non-Default Constructor
Create a non-default constructor that passes in 1 parameter, an `employee` pointer.
### manager Accessor
Create an accessor named `source_employee`.

*NOTE*: `source_employee` should return an object, **NOT A POINTER**
to the object. Remember to `dereference` the member variable.
### manager Change SSN Method
Create a member function called `change_ssn` that will utilize the function `check_valid_ssn` that is given to
you to determine if your member variable has a valid ssn. If your member variable does not have a valid ssn, set
the ssn to the value of `000000000`. Look carefully at the output below to construct your method.
### manager Change Project Method
Create a member function called `change_project` that will utilize the function `check_valid_project` that is given
to you to determine if your member variable has a valid project name. If your member variable does not have a valid
project name, set the project name to the value of "NULL" (as a string). Look carefully at the output below to construct
your method.
### manager Change Hours Worked Method
Create a member function called `change_hours_worked` that will check to see if the member variable has a
valid number of hours worked. If the number of hours worked is less than `0.0`, then set the value of hours
worked to `0.0`. Look carefully at the output below to construct your method.
### manager Change Salary Method
Create a member function called `change_salary`. This member function should check to see if the number of
hours worked is greater than or equal to `40.0`. If it is, double the salary (or multiply the salary by `2`). If
the number of hours is less than `40.0`, then cut the salary in half (or multiply the salary by `0.5`).
Look carefully at the output below to construct your method.
### manager Display Employee Method
Create a member function called `display_employee` that will print out all the attributes of an employee.
Look carefully at the output below to construct your method.

*NOTE*: Complete `main.cpp` as directed.

Output
```
Name: Bill
SSN: 1
Project: Nothing
Department Number: 2
Hours Worked: -40.0
Salary: 10000.00

Checking Valid SSN...
Not Valid SSN. Changing SSN to a temporary one.
Checking Valid Project...
Not Valid Project. Changing Project to NULL.
Checking Hours Worked...
Not Valid Number of Hours Worked. Changing Hours Worked to 0.
Checking Salary...
Cutting Salary in Half.

Name: Bill
SSN: 000000000
Project: NULL
Department Number: 2
Hours Worked: 0.0
Salary: 5000.00

Name: Bob
SSN: 123456789
Project: Research
Department Number: 1
Hours Worked: 40.0
Salary: 55000.00

Checking Valid SSN...
Valid SSN!
Checking Valid Project...
Valid Project!
Checking Hours Worked...
Valid Number of Hours Worked!
Checking Salary...
Doubling the Salary!

Name: Bob
SSN: 123456789
Project: Research
Department Number: 1
Hours Worked: 40.0
Salary: 110000.00
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

Use the `g++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `manager.cpp` and `main.cpp` into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
g++ -std=c++17 manager.cpp main.cpp -o main
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

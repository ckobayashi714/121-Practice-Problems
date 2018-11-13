# Teacher and Student Classes
This program uses two classes: `student` and `teacher`. `teacher` objects contain an array of characters that represent
the correct answers to a test (e.g., #1 is A, #2 is B, #3 is A, etc.). `student` objects contain a particular student's answer to the test (e.g., #1 is B, #2 is B, #3 is A, etc.) and their grade. A `teacher` object's `assign_grade` function can be used to take a pointer to a `student` object and check that student's answers then update their grade accordingly.

## Student class
Create a `student` class with private member variables `string` \_name, `char[]` \_test an array of multiple choice answers, `int` \_num_questions, and `double` \_grade.

Create a default constructor for `student` that sets its \_name to "Student", \_num_questions to 0, and \_grade to 0.

Create a constructor that receives a `string` name, a `char[]` test, an `int` num_questions, and sets grade to 0.

Create accessor functions for all the private member variables. Create a mutator function for \_name and \_grade.

Create a function `add_test` that receives a `char` array and `int` for the number of questions. The test should contain answers `A`, `B`, `C`, `D`, or `E`.

## Teacher class
Create a `teacher` class with private member variables `string` \_name, `char[]` \_master_test, and `int` \_num_questions.

Create a default constructor for `teacher` that sets its name to "Tea Cher" and num_questions to 0.

Create a constructor that receives a `string` name, a `char[]` master_test, and an `int` num_questions.

Create mutator and accessor functions for \_name. Create an accessor function for \_num_questions.

Create a function `add_master_test` that receives a `char` array and an `int` for the number of questions.

Create a function `assign_grade` that receives a `student*`, compares the student's test to the master_test, then changes the student's grade. The grade is computed by adding the number of correct answers (index i of the `student`'s \_test is equivalent to index i of the `teacher`'s \_master_test) and dividing it by the total number of questions. If the `teacher` and `student`'s \_num_questions are different, set the student's grade to 0.

Complete the `main()` function as described.

Sample Output:
```
Please enter the teacher's name: Paul Inventado
Prepare to enter in master test (Q to quit):
Answer 1: A
Answer 2: B
Answer 3: C
Answer 4: D
Answer 5: E
Answer 6: A
Answer 7: B
Answer 8: C
Answer 9: D
Answer 10: E
Answer 11: A
Answer 12: B
Answer 13: C
Answer 14: D
Answer 15: E
Answer 16: Q
Please enter the student's name (Q to Quit): Lonnie Hansen
Prepare to enter student test:
Answer 1: B
Answer 2: C
Answer 3: D
Answer 4: E
Answer 5: A
Answer 6: A
Answer 7: B
Answer 8: C
Answer 9: D
Answer 10: E
Answer 11: A
Answer 12: B
Answer 13: C
Answer 14: D
Answer 15: E
Please enter the student's name (Q to Quit): Andrew Gomez
Prepare to enter student test:
Answer 1: A
Answer 2: B
Answer 3: D
Answer 4: D
Answer 5: E
Answer 6: A
Answer 7: C
Answer 8: C
Answer 9: D
Answer 10: E
Answer 11: B
Answer 12: B
Answer 13: C
Answer 14: D
Answer 15: E
Please enter the student's name (Q to Quit): Q

Student         Grade
Lonnie Hansen   73.33
Andrew Gomez    80.00
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
cd labex12-tuffy
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

Use the `g++` command to compile your code and the `./` command to run it. The sample code below shows how you would compile code saved in `pet.cpp` and `main.cpp` and into the executable file `main`. Make sure you use the correct filenames required in this problem.  Take note that if you make any changes to your code, you will need to compile it first before you see changes when running it.

```
g++ -std=c++17 main.cpp athlete.cpp -o main
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

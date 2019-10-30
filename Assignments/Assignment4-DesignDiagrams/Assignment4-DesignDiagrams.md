# Project Title: Improving Logic Programming Learning Experience
## Goal Statement: 
Create a user-friendly learning experience for Artificial Intelligence students by creating a development environment for Fril (a logical programming language used for fuzzy logic programming and metaprogramming) with support for student and teacher functionalities

## User Stories

### Developer Productivity
* As a learner, I want to use an adapted version of the standard text editor in writing Fril code, so that I do not run into syntax and code-formatting errors when running the Fril language.
* As a learner, I want to have already user-defined predicates in the Fril knowledge base, so that I do not have to load them when I am running Fril code (build fril modules frm)
* As a learner, I would like to be able to run the code using my IDE.
* As a learner, I want to keep the state of the Frill interpreter session maintained in stopping infinite loop/error outputs so that I do not lose the knowledge base.
* As a learner, I want resources to gain a proper understanding of Fril commands and how to use them so that I can understand the Fril language.
* As a learner, I want to visualize learning the Fril language, so that I can cater to my type of learning, to better understand the Fril language.
* As a student learner of the Fril language, I want to have the right platform that enables further interest in learning, so that I can use Fril beyond the classroom and enjoy the benefits including fuzzy logic, metaprogramming, and explainable AI.

### Instructor
As an instructor, I want to incorporate a presentation/lecture mode when running Fril code in the classroom, so that I can have an interactive learning session with students.

## Design Diagrams
### Design D0: gives the highest level view of your project identifying basic input and output to system

* The cloud symbolizes the ideas and knowledge of the student and the professor.
* The computer symbolizes an abstracted view of the IDE we are designing.
* The smiley face symbolizes users (students and professors) who are happy because of the outputs (a running program, FRIL help, shared lecture) which contribute to the educational outcomes of the students.

![Alt text](images/Diagram0.jpg?raw=true "Diagram0")


### Design D1: elaborate design of several modules or subsystems given in D0

This diagram elaborates the components of the FRIL IDE 
* Settings
* Text Editor
* Embedded FRIL Interpreter or Console
* FRIL Help/Support
* Query Visualization (A visualization tool for debugging where the query that is being run will be displayed using a tree)

![Alt text](images/Diagram2.jpg?raw=true "Diagram1")

### Design D2: a further elaboration on D1, giving the most details concerning your system.
This diagram elaborates on specific features for the components:
* **Settings**- Our settings will include features to edit how components of the UI look. We want to focus on having an accessible application where people can change the UI’s font, font size and color scheme to suit their visual needs.
* **Text Editor**- The text editor will incorporate features like syntax highlighting, explanations of built-in predicates, and rainbow parantheses.
* **Embedded FRIL Interpreter or Console**- We will include an embedded console from which you can run code in the text editor, save commands or reset the console.
* **FRIL Help/Support**- We will include documentation on using FRIL, logic programming and using the IDE.
* **Query Visualization**- We will include a query visualization tool which will be able to visualize queries in the knowledge base for debugging purposes. The queries will be displayed as a tree.

![Alt text](images/Diagram2.jpg?raw=true "Diagram2")

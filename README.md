# Car-Rental-Project-OOP
After learning the basics of Object Oriented Programming, we made the decision to apply OOP principles to our prior project in an effort to improve its efficiency. This C++ software is an updated version of our earlier project from the first semester. This was the semester project that we turned in for the second semester of OOP.

# Introduction
In this project, we developed an application using concepts of Object-Oriented Programming. We provide the user with a variety of cars, which are divided into three classes: Economy, Economy Plus and Business. The user chooses for how long they would require the car and according to the specific rate assigned to the car. The user has the option to choose their mode of payment which include cash or credit. If the user chooses credit, they can enter their credit card information. The program checks the information and gives confirmation for the transaction.

# Libraries
iostream
conio.h
ctime
cstdlib
windows.h
iomanip
cctype

# Specifications
Aggregation: The concept of aggregation is used in the paymentdetails class. The object of this cannot exist without it being aggregated with an already existing object of user class.
Multilevel Inheritance: Multilevel inheritance is used in between classes vehicle (parent class), car (child class) and all other price range classes are grandchild classes.
Abstract Classes: They are used in order to form an inheritance hierarchy in between the classes. We created vehicle as an abstract class and included a pure virtual function.
Friend Functions: Friend functions are used in our code to assist in operator overloading and print the details of the vehicle chosen by the user. The details that are supposed to under the access modifier “private” which only allows the data members to be accessed within the class.
Operator Overloading: We overloaded the operator “<<” in order to print the details of the car so we do not have to use cout for every single data member. It just prints all of them at once.
Preprocessor Macros: We also used built-in macros for printing the current date and time at which the receipt is printed. We used the macros “DATE” and “TIME” to print them.
Conditional Statements: If Else and Switch statements are used in our program in order to process the users’ different inputs.
Go-to Functions: Go-to functions are used in case the user enters an incorrect input or chooses to restart.

# Screenshots
Program
Picture1
Picture2
Picture3

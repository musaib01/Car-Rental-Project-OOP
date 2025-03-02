# Car-Rental-Service-V2
Freshly learnt the concepts of Object Oriented Programming, we decided to bring our previous project to another level by applying concepts of OOP and try to make it more efficient. This is a program made with C++ and is an improved version of our previous project in the first semester. We submitted this as our Semester project for the course of OOP in the second semester.

# Introduction
In this project, we developed an application using concepts of Object-Oriented Programming. We provide the user with a variety of cars, which are divided into three classes: Economy, Economy Plus and Business. The user chooses for how long they would require the car and according to the specific rate assigned to the car. The user has the option to choose their mode of payment which include cash or credit. If the user chooses credit, they can enter their credit card information. The program checks the information and gives confirmation for the transaction.

# Libraries
1) iostream
2) conio.h
3) ctime
4) cstdlib
5) windows.h
6) iomanip
7) cctype

# Specifications
1) Aggregation: The concept of aggregation is used in the paymentdetails class. The object of this cannot exist without it being aggregated with an already existing object of user class.
2) Multilevel Inheritance: Multilevel inheritance is used in between classes vehicle (parent class), car (child class) and all other price range classes are grandchild classes.
3) Abstract Classes: They are used in order to form an inheritance hierarchy in between the classes. We created vehicle as an abstract class and included a pure virtual function.
4) Friend Functions: Friend functions are used in our code to assist in operator overloading and print the details of the vehicle chosen by the user. The details that are supposed to under the access modifier “private” which only allows the data members to be accessed within the class.
5) Operator Overloading: We overloaded the operator “<<” in order to print the details of the car so we do not have to use cout for every single data member. It just prints all of them at once.
6) Preprocessor Macros: We also used built-in macros for printing the current date and time at which the receipt is printed. We used the macros “DATE” and “TIME” to print them.
7) Conditional Statements: If Else and Switch statements are used in our program in order to process the users’ different inputs.
8) Go-to Functions: Go-to functions are used in case the user enters an incorrect input or chooses to restart.

# Screenshots
![OOP_Picture1](https://user-images.githubusercontent.com/91963525/193407217-385d757c-5860-4f30-b021-298b3011884f.png)
![OOP_Picture2](https://user-images.githubusercontent.com/91963525/193407231-885f61b4-283e-4b67-af3d-fda645880ca6.png)
![OOP_Picture3](https://user-images.githubusercontent.com/91963525/193407237-59c44dff-ee15-428f-9081-337b9fd26c76.png)

# Contributors
1) Qalb e Ali
2) Syed Ali Raza
3) Muhammad Tayyab
4) Danyal Shah

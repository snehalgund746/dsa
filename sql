CREATE DATABASE Library_managment_system;
USE Library_managment_system;
CREATE TABLE Member1(
    Name VARCHAR(50),
    id INT PRIMARY KEY,
    department VARCHAR(50),
    city VARCHAR(30)
);

INSERT INTO Member1 VALUES('Siddhika',47,'Information Technology','Pune');
INSERT INTO Member1 VALUES('Kituu',68,'Computer Science','Delhi');
INSERT INTO Member1 VALUES('Rohit',12,'ENTC','Goa');
INSERT INTO Member1 VALUES('Disha',54,'Automobile','Nagar');
INSERT INTO Member1 VALUES('Saruu',98,'Mechanical Technology','Mumbai');

SELECT * FROM Member1;

CREATE TABLE BOOK(
    Book_ID INT PRIMARY KEY,
    Book_Name VARCHAR(50)
);

INSERT INTO BOOK VALUES(101,'DBMS');
INSERT INTO BOOK VALUES(201,'BXE');
INSERT INTO BOOK VALUES(301,'Maths');
INSERT INTO BOOK VALUES(402,'EVS');
INSERT INTO BOOK VALUES(506,'DELD');

SELECT * FROM BOOK;

CREATE TABLE Issue_Record(
    Issue_ID INT PRIMARY KEY,
    Member1 INT,
    Book INT
);

INSERT INTO Issue_Record VALUES(1,12,101);
INSERT INTO Issue_Record VALUES(2,54,301);

SELECT * FROM Issue_Record;

SELECT Member1.Name, BOOK.Book_Name
FROM Member1
INNER JOIN Issue_Record
ON Member1.ID = Issue_Record.Member1
INNER JOIN BOOK
ON BOOK.Book_ID = Issue_Record.Book;

SELECT Member1.Name, BOOK.Book_Name
FROM Member1
LEFT JOIN Issue_Record
ON Member1.ID = Issue_Record.Member1
LEFT JOIN BOOK
ON BOOK.Book_ID = Issue_Record.Book;








CREATE DATABASE CollegeDB;

USE CollegeDB;

CREATE TABLE Student(
    Roll_No INT PRIMARY KEY,
    Name VARCHAR(50)
);

INSERT INTO Student VALUES(1,'Rahul');
INSERT INTO Student VALUES(2,'Sneha');

CREATE USER user1 IDENTIFIED BY '123';

CREATE ROLE manager;

GRANT SELECT, INSERT, UPDATE
ON Student
TO manager;

GRANT manager TO user1;

REVOKE UPDATE
ON Student
FROM user1;

SELECT * FROM Student;










-- Create Department Table
CREATE TABLE Department(
    Dept_ID NUMBER PRIMARY KEY,
    Dept_Name VARCHAR2(50)
);

-- Insert Records into Department
INSERT INTO Department VALUES(1,'Computer');
INSERT INTO Department VALUES(2,'Mechanical');

-- Display Department Table
SELECT * FROM Department;

-- Create Employee Table
CREATE TABLE Employee(
    Emp_ID NUMBER PRIMARY KEY,
    Emp_Name VARCHAR2(50),
    Dept_ID NUMBER
);

-- Display Employee Table
SELECT * FROM Employee;

-- Create Trigger
CREATE OR REPLACE TRIGGER Check_Department
BEFORE INSERT ON Employee
FOR EACH ROW
DECLARE
    dept_count NUMBER;
BEGIN
    SELECT COUNT(*)
    INTO dept_count
    FROM Department
    WHERE Dept_ID = :NEW.Dept_ID;

    IF dept_count = 0 THEN
        RAISE_APPLICATION_ERROR(-20001,
        'Department does not exist');
    END IF;
END;
/

-- Valid Insert
INSERT INTO Employee VALUES(101,'Rahul',1);

-- Invalid Insert
INSERT INTO Employee VALUES(102,'Amit',5);

-- Display Employee Table
SELECT * FROM Employee;

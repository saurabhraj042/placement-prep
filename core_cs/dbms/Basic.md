# Basic :

##### Database :

Database is a **collection** of inter-related data which helps in efficient retrieval, insertion and deletion of **data** from database and **organizes** the data in the form of tables, views, schemas, reports etc.

(Data : it's a collection of small unit of information like text,media etc.)

##### Common Database Types :

1. **Centralized DB** : It is the type of database that stores data at a centralized database system.'
2. **Distributed DB** : Data is distributed among different database systems which are connected via communication links that help the end-users to access the data easily.
   In Homogeneous DDB the DB systems execute on the same OS and in Heterogeneous DDB it's opposite
3. **Relational DB** : It is based on the relational data model, which stores data in the form of rows(tuple) and columns(attributes), and together forms a table(relation).
4. **NoSQL DB** : It is a type of database that is used for storing a wide range of data sets. It is not a relational database as it stores data not only in tabular form but in several different ways.
   1. **Key-value storage:** It is the simplest type of database storage where it stores every single item as a key (or attribute name) holding its value, together.
   2. **Document-oriented Database:** A type of database used to store data as JSON-like document.
   3. **Graph Databases:** It is used for storing vast amounts of data in a graph-like structure. Most commonly, social networking websites use the graph database.
   4. **Wide-column stores:** It is similar to the data represented in relational databases. Here, data is stored in large columns together, instead of storing in rows.

##### DBMS :

It is a software for **storing** and **retrieving** users' data while considering appropriate security measures. It consists of a group of programs which manipulate the database. The DBMS accepts the request for data from an application and instructs the operating system to provide the specific data. 

DBMS allows users to create their own databases as per their requirement. It provides an interface between the data and the software application.

##### Advantages of Using a DBMS / Need for DBMS :

* DBMS offers a variety of techniques to store & retrieve data efficiently.
* DBMS serves as an efficient handler to balance the needs of multiple applications using the same data.
* Uniform administration procedures for data.
* Application programmers never exposed to details of data representation and storage.
* Offers Data Integrity and Security.
* The DBMS implies integrity constraints to get a high level of protection against prohibited access to data.
* A DBMS schedules concurrent access to the data in such a manner that only one user can access the same data at a time

##### Some Disadvantages of using DBMS :

* Initial hardware and software costs.
* Cost for training employees for the complex system.

##### DBMS vs File System

| DBMS                                                                | File System                                                            |
| ------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| User is not required to write the procedures.                       | User has to write the procedures for managing the database.            |
| It gives an abstract view of data that hides the details.           | It provides the detail of the data representation and storage of data. |
| It provides a crash recovery mechanism.                             | It dosen't.                                                            |
| Provides a good protection mechanism.                               | It dosen't'                                                            |
| Takes care of Concurrent access of data using some form of locking. | Concurrent access has many problems which leads to loss of<br />data.  |



##### DBMS Architecture :

| Two-Tier                                                                                                                                    | Three-Tier                                                                                                                        |
| ------------------------------------------------------------------------------------------------------------------------------------------- | --------------------------------------------------------------------------------------------------------------------------------- |
| It is a Client-Server Architecture.                                                                                                         | It is a Web-based application.                                                                                                    |
| In two-tier, the application logic is either buried inside the user interface on the client or within the database on the server (or both). | In three-tier, the application logic or process resides in the middle-tier, it is separated from the data and the user interface. |
| Two-tier architecture consists of two layers : Client Tier and Database (Data Tier).                                                        | Three-tier architecture consists of three layers : Client Layer, Business Layer and Data Layer.                                   |
| It is easy to build and maintain.                                                                                                           | It is complex to build and maintain.                                                                                              |
| Two-tier architecture runs slower.                                                                                                          | Three-tier architecture runs faster.                                                                                              |
| It is less secured as client can communicate with database directly.                                                                        | It is secured as client is not allowed to communicate with database directly.                                                     |
| It results in performance loss whenever the users increase rapidly.                                                                         | It results in performance loss whenever the system is run on Internet but gives more performance than two-tier architecture.      |
| Example – Contact Management System created using MS-Access or Railway Reservation System, etc.                                            | Example – Designing registration form which contains text box, label, button or a large website on the Internet, etc.            |


##### Database Language / SQL :

**Structured Query Language(SQL)** is the database language which is used to perform certain operations on the existing database or to create a database.

SQL commands are mainly categorized into five categories as:

1. **DDL – Data Definition Language** : Used to create/modify/define the structure of database objects/database schema in the database. Ex : CREATE,DROP,ALTER,TRUNCATE,COMMENT
2. **DQl – Data Query Language** : Used for performing queries on the data within schema objects to get some schema relation based on the query passed to it. Ex: SELECT
3. **DML – Data Manipulation Language** : Deals with the manipulation of data present in the database.Ex : INSERT,UPDATE,DELETE
4. **DCL – Data Control Language** : Deals with the rights, permissions and other controls. EX : GRANT,REVOKE
5. **TCL - Transaction Control Language** : Deal with the [transaction within the database](https://www.geeksforgeeks.org/sql-transactions/).

   * **COMMIT** – commits a Transaction.
   * [**ROLLBACK**](https://www.geeksforgeeks.org/sql-transactions/)– rollbacks a transaction in case of any error occurs.
   * **SAVEPOINT** –sets a savepoint within a transaction.
   * **SET TRANSACTION** –specify characteristics for the transaction.

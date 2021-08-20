# Basic :

### Database :

Database is a **collection** of inter-related data which helps in efficient retrieval, insertion and deletion of **data** from database and **organizes** the data in the form of tables, views, schemas, reports etc.

(Data : it's a collection of small unit of information like text,media etc.)

### Common Database Types :

1. **Centralized DB** : It is the type of database that stores data at a centralized database system.'
2. **Distributed DB** : Data is distributed among different database systems which are connected via communication links that help the end-users to access the data easily.
   In Homogeneous DDB the DB systems execute on the same OS and in Heterogeneous DDB it's opposite
3. **Relational DB** : It is based on the relational data model, which stores data in the form of rows(tuple) and columns(attributes), and together forms a table(relation).
4. **NoSQL DB** : It is a type of database that is used for storing a wide range of data sets. It is not a relational database as it stores data not only in tabular form but in several different ways.
   1. **Key-value storage:** It is the simplest type of database storage where it stores every single item as a key (or attribute name) holding its value, together.
   2. **Document-oriented Database:** A type of database used to store data as JSON-like document.
   3. **Graph Databases:** It is used for storing vast amounts of data in a graph-like structure. Most commonly, social networking websites use the graph database.
   4. **Wide-column stores:** It is similar to the data represented in relational databases. Here, data is stored in large columns together, instead of storing in rows.

### DBMS :

It is a software for **storing** and **retrieving** users' data while considering appropriate security measures. It consists of a group of programs which manipulate the database. The DBMS accepts the request for data from an application and instructs the operating system to provide the specific data.

DBMS allows users to create their own databases as per their requirement. It provides an interface between the data and the software application.

### Advantages of Using a DBMS / Need for DBMS :

* DBMS offers a variety of techniques to store & retrieve data efficiently.
* DBMS serves as an efficient handler to balance the needs of multiple applications using the same data.
* Uniform administration procedures for data.
* Application programmers never exposed to details of data representation and storage.
* Offers Data Integrity and Security.
* The DBMS implies integrity constraints to get a high level of protection against prohibited access to data.
* A DBMS schedules concurrent access to the data in such a manner that only one user can access the same data at a time

### Some Disadvantages of using DBMS  :

* Initial hardware and software costs.
* Cost for training employees for the complex system.

### DBMS vs File System

| DBMS                                                                | File System                                                            |
| ------------------------------------------------------------------- | ---------------------------------------------------------------------- |
| User is not required to write the procedures.                       | User has to write the procedures for managing the database.            |
| It gives an abstract view of data that hides the details.           | It provides the detail of the data representation and storage of data. |
| It provides a crash recovery mechanism.                             | It dosen't.                                                            |
| Provides a good protection mechanism.                               | It dosen't'                                                            |
| Takes care of Concurrent access of data using some form of locking. | Concurrent access has many problems which leads to loss of<br />data.  |

### DBMS Architecture :

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

### Database Language / SQL :

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

### Instance / DB State :

It is the snapshot of the database taken at a particular moment. It can also be described as collection of the information stored in the database at that particular moment.

### Schema :

Overall description or the overall design of the database specified during the database design.Basically, it displays the record types(entity),names of data items(attribute) but not the relation among the files.Values in schema might change but not the structure of schema.

### Sub-Schema :

It can be defined as the subset or sub-level of schema that has the same properties as the schema.It provides the users a window through which the user can view only that part of database which is of matter of interest

### 3 Level Data Abstraction :

1. **View Level** : This level tells the application about how the data should be shown to the user. Example: If we have a login-id and password in a university system, then as a student, we can view our marks, attendance, fee structure, etc. But the faculty of the university will have a different view. He will have options like salary, edit marks of a student, enter attendance of the students, etc. So, both the student and the faculty have a different view.
2. **Logical Level** : This level tells how the data is actually stored and structured. We have different data models by which we can store the data.Example : Let us take an example where we use the relational model for storing the data. We have to store the data of a student, the columns in the student table will be student_name, age, mail_id, roll_no etc.
3. **Physical Level** : Physical level tells us that where the data is actually stored i.e. it tells the actual location of the data that is being stored by the user. The Database Administrators(DBA) decide that which data should be kept at which particular disk drive, how the data has to be fragmented, where it has to be stored etc.


# RDBMS :

A relational database like SQL is a collection of data items organized in tables.

### Degree of Relation :

1. **one-to-one relationship** : In RDBMS, a one-to-one (1:1) relationship exists when zero or one instance of entity A can be associated with zero or one instance of entity B, and zero or one instance of entity B can be associated with zero or one instance of entity A. (abbreviated 1:1)
2. **one-to-many relationship** : In RDBMS, a one-to-many (1:N) relationship exists when, for one instance of entity A, there exists zero, one, or many instances of entity B; but for one instance of entity B, there exists zero or one instance of entity A.
3. **many-to-many relationship** : In RDBMS, a many-to-many (M:N) relationship exists when, for one instance of entity A, there exists zero, one, or many instances of entity B; and for one instance of entity B, there exists zero, one, or many instances of entity A. (abbreviated M:N)

### Keys :

**Candidate Key:** A candidate key is an attribute or set of an attribute which can uniquely identify a tuple. The value of the Candidate Key is unique and non-null for every tuple.

* There can be more than one candidate key in a relation.
* The candidate key can be simple (having only one attribute) or composite as well.
* No of candidate keys in a Relation are **nC(floor(n/2))**,for example if a Relation have 5 attributes i.e. R(A,B,C,D,E) then total no of candidate keys are 5C(floor(5/2))=10.

**Primary Key:** It is the first key which is used to identify one and only one instance of an entity uniquely.There can be more than one candidate key in relation out of which one can be chosen as the primary key.

**Alternate Key**: The candidate key other than the primary key is called an alternate key. 

**Foreign Key:** Foreign keys are the column of the table which is used to point to the primary key of another table.

**Super Key :** Super key is a set of an attribute which can uniquely identify a tuple. Super key is a superset of a candidate key.

### Schema Diagrams :

#### 1 . ER Model : 

ER Model is used to model the logical view of the system from data perspective which consists of these components: 

* **Entitiy :** An entity may be any object, class, person or place. In the ER diagram, an entity can be represented as rectangles.An entity that depends on another entity called a **Weak Entity.**
* **Attribute :** The attribute is used to describe the property of an entity.
* **Relationship :** A relationship is used to describe the relation between entities. Diamond or rhombus is used to represent the relationship.

Types of Attributes :

1. **Key Attribute** : The key attribute is used to represent the main characteristics of an entity. It represents a primary key. The key attribute is represented by an ellipse with the text underlined.
2. **Composite Attribute :** An attribute that composed of many other attributes is known as a composite attribute.
3. **Multivalued Attribute** : An attribute can have more than one value. These attributes are known as a multivalued attribute. The double oval is used to represent multivalued attribute.
4. **Derived Attribute :** An attribute that can be derived from other attribute is known as a derived attribute. It can be represented by a dashed ellipse.

Types of Relation :

1. One to One
2. One to Many
3. Many to Many

#### 2. Relational Model :

A relational database stores data in the form of relations (tables).

Important terms for this model :

* **Attribute:** Attributes are the properties that define a relation. e.g.;  **ROLL_NO** , **NAME**
* **Relation Schema:** A relation schema represents name of the relation with its attributes. e.g.; STUDENT (ROLL_NO, NAME, ADDRESS, PHONE and AGE) is relation schema for STUDENT. If a schema has more than 1 relation, it is called Relational Schema.
* **Tuple:** Each row in the relation is known as tuple.
* **Relation Instance:** The set of tuples of a relation at a particular instance of time is called as relation instance.
* **Degree:** The number of attributes in the relation is known as degree of the relation.
* **Cardinality:** The number of tuples in a relation is known as cardinality.
* **Column:** Column represents the set of values for a particular attribute.
* **NULL Values:** The value which is not known or unavailable is called NULL value.


### Relational Operations :

#### **SELECT :**

The SELECT operation is used for selecting a subset of the tuples according to a given selection condition. Sigma(σ)Symbol denotes it. It is used as an expression to choose tuples which meet the selection condition. Select operator selects tuples that satisfy a given predicate.

`σ<sub>p</sub>(r)`

`σ` is the predicate

`r` stands for relation which is the name of the table

`p` is prepositional logic

**Example 1**

```
σ topic = "Database" (Tutorials)
```

**Output** - Selects tuples from Tutorials where topic = 'Database'.

#### **PROJECTION :**

The projection eliminates all attributes of the input relation but those mentioned in the projection list. The projection method defines a relation that contains a vertical subset of Relation.

This helps to extract the values of specified attributes to eliminates duplicate values. (pi) symbol is used to choose attributes from a relation. This operator helps you to keep specific columns from a relation and discards the other columns.

**Example of Projection:**

Consider the following table

| CustomerID | CustomerName | Status   |
| ---------- | ------------ | -------- |
| 1          | Google       | Active   |
| 2          | Amazon       | Active   |
| 3          | Apple        | Inactive |
| 4          | Alibaba      | Active   |

Here, the projection of CustomerName and status will give

```
Π CustomerName, Status (Customers)
```

| CustomerName | Status   |
| ------------ | -------- |
| Google       | Active   |
| Amazon       | Active   |
| Apple        | Inactive |
| Alibaba      | Active   |


#### **UNION :**

UNION is symbolized by ∪ symbol. It includes all tuples that are in tables A or in B. It also eliminates duplicate tuples. So, set A UNION set B would be expressed as:

The result <- A ∪ B

For a union operation to be valid, the following conditions must hold -

* R and S must be the same number of attributes.
* Attribute domains need to be compatible.
* Duplicate tuples should be automatically removed.

Example

Consider the following tables.

| Table A  |          | **Table B** |
| -------- | -------- | ----------------- |
| column 1 | column 2 |                   |
| 1        | 1        |                   |
| 1        | 2        |                   |

A ∪ B gives

| Table A ∪ B |
| ------------ |
| column 1     |
| 1            |
| 1            |
| 1            |

#### **SET DIFFERENT :**

Symbol denotes it. The result of A - B, is a relation which includes all tuples that are in A but not in B.

* The attribute name of A has to match with the attribute name in B.
* The two-operand relations A and B should be either compatible or Union compatible.
* It should be defined relation consisting of the tuples that are in relation A, but not in B.

**Example**

```
A-B
```

| Table A - B |
| ----------- |
| column 1    |
| 1           |

#### **CARTESIAN PRODUCT :**

**Cartesian Product in DBMS** is an operation used to merge columns from two relations. Generally, a cartesian product is never a meaningful operation when it performs alone. However, it becomes meaningful when it is followed by other operations. It is also called Cross Product or Cross Join.

σ  ~column 2 ~ =  ~'1' ~ (A X B)

Output – The above example shows all rows from relation A and B whose column 2 has value 1

| σ column 2 = '1' (A X B) |
| ------------------------- |
| column 1                  |
| 1                         |
| 1                         |

#### 
**RENAME :**

Rename is a unary operation used for renaming attributes of a relation.

ρ (a/b)R will rename the attribute 'b' of relation by 'a'.

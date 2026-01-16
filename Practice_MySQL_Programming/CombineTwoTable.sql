CREATE TABLE Person (
    personId INT AUTO_INCREMENT PRIMARY KEY,
    firstname VARCHAR(50) NOT NULL,
    lastname VARCHAR(50) NOT NULL
);

CREATE TABLE Address (
    addressId INT,
    personId INT AUTO_INCREMENT PRIMARY KEY,
    city VARCHAR(50) NOT NULL,
    state VARCHAR(50) NOT NULL
);


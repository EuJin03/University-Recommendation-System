# TOP UNIVERSITY RECOMMENDATION SYSTEM FOR SECONDARY SCHOOL STUDENTS

This is a C++ program designed to help parents of secondary school students better understand the quality of universities around the world and plan a better future education for their children. The program uses the 2023 QS university ranking dataset, which contains information of more than 1400 different universities from all over the world, to provide recommendations to the users.

## Requirements

- C++ compiler (GCC or Clang recommended)
- GNU Make

## Installation

1. Clone this repository to your local machine
2. Navigate to the `root` directory of the project in your terminal
3. Run `make all` to compile the program
4. Run `./university_recommendation_system.exe` to run the program

## Usage

### Normal Users

1. Display all the universities’ information from the dataset.
2. Sort university information in ascending order by university name

   - Two distinct sorting algorithms are implemented to compare their execution time.
   - The result is discussed in the final report.

3. Search individual university details.

   - Two distinct search algorithms are implemented to compare their execution time.
   - The result is discussed in the final report.

4. Register as a customer of the education exhibition.

### Registered Users (Customers)

1. Login and logout.
2. Sort university information in descending order based on academic reputation score, faculty/student ratio score and employer reputation score.
3. Search universities details based on customer decision.
4. Save their favorite universities.
5. Send feedback to MoHE for further information about the University.
6. Read the feedback reply from the MoHE based on the latest date.

### MoHE Admin

1. Login and logout.
2. Display all registered users’ details.
3. Modify a user detail.
4. Delete user accounts based on inactivity status.
5. Move back and forth between the feedback of registered users according to the latest date.
6. Reply to the registered user’s feedback.
7. Based on the list of all customers' favorite universities, summarize the top 10 universities most preferred by parents in Malaysia and generate a report.

Note: The system capabilities mentioned above are mandatory as required in the assignment. However, the program can be further enhanced by adding more features in the future.

## Contributing

If you would like to contribute to this project, please fork the repository and submit a pull request.

## License

This project is licensed under the MIT License. See the LICENSE file for more details.

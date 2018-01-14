Author: Gordon Restivo
Last date modified: 10/22/2017

Discription of program:

This program runs a simulation for a hospital emergency room based by using a priority queue to properly sort patients
based on their given priority. The program takes in a file from the command line which contains data on a random number
of patients (or perhaps no data at all) and adds them into a priority queue based on a priority number that is given
in the file (priority number is from 1-5). The user then has the option to add more patients, run the simulation or
quit. Quit exits the program gracefully. Adding a new patient allows the user to put in error checked information for
a new patient and sorts them into the queue accordingly. Running the simultion processes the patients based on their
order in the priority queue, keeps track of their processing times and when they finished with the doctors. Once all
patients have been processed the program will print out all of the patient data in the order there were given to the
program and not their order based upon their priority.

Assumptions:
1. For output, the client ID can not be past a certain length or the output will become distorted
2. Doctors are somehow super humans who can process patients in 1-10 seconds

To run main:
1. Type in make
2. type "./bin/runMe 'filename.txt'" (without a valid file the program will be terminated)

To run testMain:
1.Type in make
2.type "./bin/runTests"

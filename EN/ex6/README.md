For the needs of one air flights aggregator, it is necessary to make a module that will allow searching for different flights between two cities.

Define a class Flight that will contain:

City of take-off (an array of 50 characters)

Landing city (an array of 50 characters)

Flight duration in hours (real number)

Flight price in euros (real number)

Define the necessary constructors, destructor, and additional methods for the proper functioning of the class (5 points). For the class, define the methods:

void printDuration () - to print the flight duration in the format [hour] h: [min] min. For example, if the value for the flight duration is 1.5, the method should print 1h: 30min (10 points)

void printFlight () - to print the flight in the following format: City of departure -> Flight duration -> City of landing: price (5 points)


Define a class Airline that contains information about:

The airline name (a string of 50 characters)

An array of flight (dynamically allocated array of objects of class Flight)

Number of flights (size of the dynamically allocated array)

Define the necessary constructors, destructor, and methods for the proper functioning of the class (5 points). You need to define a method void addFlight (Flight f) for the addition of a new flight if the flight doesn’t already exist in the airline. Two flights are considered equal if they have the same city of take-off and landing. (10 points).


Additionally, define a global function with a signature:

void searchFlights (Airline a, char departureCity [], char arrivalCity []) - The function should print the direct flight between the two cities passed as arguments. If there is no direct flight, the function should print a list of two flights between the two cities, which include only one hub (a city that is a connection between the two cities). If there is no such flight, it should print "No connection between the cities"

(example: flight between Skopje and Berlin. Direct flight: Skopje-Berlin, single hub flight: Skopje-Vienna, Vienna-Berlin). (20 points)
For example:

Input

1

Skopje

Ohrid

0.3

40.0

Output

====Testing class Flight constructors and additional methods====

Skopje Ohrid

Testing OK
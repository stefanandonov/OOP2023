# Task 1

The class Sneakers is defined in the start code. In this class, the following information is stored: model (char array), size (integer) and price (float). The class already contains all the necessary constructors and destructor, operators, set and get methods. This class should not be changed.

Define a new class SneakersShop in which the following information should be stored: (5 points)

- store name (array of maximum 50 characters)
- sneakers offered by the store (dynamically allocated array of object of the class Sneakers)
- total number of items in the Sneakers array (integer)
- increasement (price rise expressed as a percentage, integer) - the same for all products available in the store initially set to 5. This value is subject to change.

For this class implement the following:

- necessary constructors and destructor (5 points)
- operator += for adding a new object of the Sneakers class to the store. (5 points)
- method float checkItemAvailability(char* model, int size) - which will check if the model that is passed as the first input argument is available in the store in the size that is passed as the second input argument. If the model is available in the given size (for example, NIKE FLEX RUNNER, size 38), the method returns the price of the sneakers, otherwise it returns a value of 0. (5 points)
- operator ++ (prefix notation) to increase the price of all sneakers for the value of the increasement. (5 points)

Define a new class OnlineSneakersShop that besides the basic information for the SneakersShop stores additional information for: (5 points)

- url of the website of the online sneakers store (array of maximum 50 characters).
- discount (expressed as a percentage, integer) - the same for all products available in the online store and initially set to 10. This value cannot be changed.

For this class implement the necessary constructors and destructor. (5 points) Additionally, for this class implement the following:

- method float checkItemAvailability(char* model, int size) - which will check if the model that is forwarded as the first input argument is available in the online sneaker store in the size that is forwarded as the second input argument. If the model is available in the given size (for example, NIKE FLEX RUNNER, size 38), the method returns the price and on the sneakers reduced for the discount available in the online store. Otherwise, the method returns a value of 0. (5 points)

For both classes overload the operator <<. You can see the printing format in the first two examples. (5 points)

# Task 2

Write an abstract class Evaluator for evaluation of algorithms for classification of elements into two categories (positive (+) or negative (-)). The class should have two purely virtual methods:

- double evaluate ()
- void print()

This class should additionally store two null terminated arrays of no more than 100 characters (strings) to represent:

- The actual categories of elements
- The predicted categories of elements

This strings must be of the same length. Allowed values in both arrays are only the characters + (denoting the positive category) and - (denoting the negative category). (5 points)

Explanation for the arrays of characters: For example, if the strings are "++++" (for the actual categories) and "+--+" (for the predicted categories) it means that the first and fourth element are of the positive category and were correctly predicted as positive, while the second and third element are of the positive category, but were erroneously predicted as negative.

Derive the AccuracyEvaluator and SensitivityEvaluator classes from the Evaluator class.  (5 points) For this classes you should implement the evaluate() method this way:

- In AccuracyEvaluator, the accuracy is calculated as a proportion of the number of accurate predictions and the number of elements. For example, for the given actual categories ++++ and predicted categories --++, the accuracy is 0.5 (the last two elements were correctly predicted as positive (+), and the first two elements were are incorrectly predicted as negative (-), so 2/4 = 0.5). (10 points)
- In SensitivityEvaluator, the sensitivity is calculated as a proportion of the number of correctly predicted elements of a positive category to the number of elements whose actual category is positive. For example, for the given actual categories +++- and the predicted categories +--+, only one element is correctly predicted in the positive category (the first element), of the total of 3 elements with the actual positive category, so the sensitivity is calculated as 1/3 = 0.33. (10 points)

The print() method should print information about the evaluators in the following format: (5 points)

- For the AccuracyEvaluator class: Number of data points: [the number of elements to be predicted] Prediction Accuracy: [the calculated accuracy]
- За SensitivityEvaluator : Number of data points:points [the number of elements to be predicted] Prediction Sensitivity: [the calculated sensitivity]

Define all the necessary methods in the classes for the proper functioning of the program. Use exceptions to prevent the creation of objects from the derived classes of the Evaluator class, if the string representing the categories are of different size. In such a scenario, throw an exception of type WrongLabelsFormatException. (5 points) The exception needs to be handled in the main function. When the exception is caught, print the appropriate message as in the test examples. (5 points) All strings in the test examples will be composed exclusively of the + и - signs.

Overload the operator >= to compare two evaluators according to the result of the method evaluate. (3 points)

Define a global function Evaluator* highestScore (Evaluator ** evaluators, int n), which will return a pointer to the evaluator with the highest score from the evaluate method. If there are multiple evaluators with a maximum score from the evaluate method, return the last one. (7 points)
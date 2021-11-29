/*
 *  UCF COP3330 Fall 2021 Assignment 5 Solution
 *  Copyright 2021 Kaylee Laughner
 */
 #include "main.h"

class numbers {
  // function to get number based on numerical or text string input
  public: int getNumber(string num) {
    if (num == "1" || num == "one") {
      return 1;
    }
    if (num == "2" || num== "two") {
      return 2;
    }
    if (num=="3" || num == "three") {
      return 3;
    }
    if (num=="4" || num=="four") {
      return 4;
    }
    if (num=="5" || num=="five") {
      return 5;
    }
    if (num=="6" || num=="six") {
      return 6;
    }
    if (num=="7" || num=="seven") {
      return 7;
    }
    if (num == "8" || num=="eight") {
      return 8;
    }
    if (num =="9" || num=="nine") {
      return 9;
    }
    else {
      return 0;
    }
  } 
};
class validateInput{
  // function to validate that correct operand was inputted
  public: bool validateOp(string op) {
    if (op == "+" || op == "plus" || op == "-" || op=="minus" || op =="/" || op == "divide" || op == "div" || op=="mul" || op == "multiply" || op == "*") {
      return true;
    }
    else {
      return false;
    }
  }
  // function to validate that correct number was inputted
  public:bool validateOperands(string o) {
    if (o == "one" || o=="1" || o=="two" || o=="2" || o=="3" || o=="three" || o=="4" || o=="four" || o=="five" || o=="5" || o=="6" || o=="six" || o=="7"|| o=="seven" || o=="8" || o=="eight" || o=="9" || o=="nine" || o=="0" ||o=="zero") {
      return true;
    }
    else {
      return false;
    }
  }
};
class doMath{
  // function to perform desired calculation
  public: double doCalc(string op, string op1, string op2) {
    double result;
    numbers n;
    // get number based on user input
    double operand1 = n.getNumber(op1);
    double operand2 = n.getNumber(op2);

    // perform calculations
    if (op == "*" || op=="multiply" || op == "mul") {
      result = operand1*operand2;
    }
    if (op == "/" || op=="divide" || op=="div") {
      result = operand1/operand2;
    }
    if (op =="+" || op== "plus") {
      result = operand1 + operand2;
    }
    if (op=="-" || op=="minus") {
      result = operand1 - operand2;
    }
    // return the result from operation
    return result;
  }
  // function to print result
  public: void printResult(double result, string op, string op1, string op2) {
    std::cout << op1 << " " << op << " " << op2 << " = " << result;
  }
};
int main() {
  // calling validation class
  validateInput v;
  string op;
  string operand1;
  string operand2;
  // only accept valid input
  do {
    std::cout << "Please enter a valid operator (*, /, +, -) followed by two single-digit integers (as numbers or text) seperated by spaces:";
    std::cin >> op >> operand1 >> operand2;
    
    // transforming operand inputs to lower case before sending to functions
    transform(operand1.begin(), operand1.end(), operand1.begin(), ::tolower);
    transform(operand2.begin(), operand2.end(), operand2.begin(), ::tolower);
  } while (v.validateOp(op)!=true || v.validateOperands(operand1) !=true || v.validateOperands(operand2) !=true);
  // calling doMath class
  doMath d;
  // getting result using doMath class
  double result = d.doCalc(op, operand1, operand2);
  // printing result using doMath class
  d.printResult(result, op, operand1, operand2);
} 

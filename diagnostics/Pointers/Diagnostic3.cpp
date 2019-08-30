#include <iostream>

//Indicates what type of numerical value is to be operated on
enum ValueType {INTEGER, FLOATING_POINT};

//Indicate the operation to be performed
enum Operation {ADD, SUBTRACT, MULTIPLY, DIVIDE};

//Data structure for holding all relevant operation data
typedef struct
{
	ValueType type;  //data types to operate on
	Operation op; //operation to perform
	void* A; //pointer to argument A
	void* B; //pointer to argument B
	int intResult; //space for integer results
	float floatResult; //space for float results

} CalculatorPacket;

/**
Function to perform calculation. Only need to support integer and floating point ADD
*/
void Calculator(CalculatorPacket& calc)
{
	switch (calc.op)
	{
	case Operation::ADD:
		if (calc.type == ValueType::INTEGER)
		{
			int* A = (int*)calc.A;
			int* B = (int*)calc.B;

			calc.intResult = *A + *B;
		}
		else if (calc.type == ValueType::FLOATING_POINT)
		{
			float* A = (float*)calc.A;
			float* B = (float*)calc.B;

			calc.floatResult = *A + *B;
		}

		break;

	case Operation::SUBTRACT:

		break;
	}


}

int main()
{

	//construct an integer packet to operate on
	int integerA = 3;
	int integerB = 7;

	CalculatorPacket integerAdd;
	integerAdd.type = ValueType::INTEGER;
	integerAdd.op = Operation::ADD;
	integerAdd.A = &integerA;
	integerAdd.B = &integerB;

	Calculator(integerAdd);

	std::cout << "Result should be 7: " << integerAdd.intResult << std::endl;

	//construct a floating point packet to operate on
	float floatA = 3.14159;
	float floatB = -42.0;

	CalculatorPacket floatAdd;
	floatAdd.type = ValueType::FLOATING_POINT;
	floatAdd.op = Operation::ADD;
	floatAdd.A = &floatA;
	floatAdd.B = &floatB;

	Calculator(floatAdd);

	std::cout << "Result should be -38.85841: " << floatAdd.floatResult << std::endl;

	return 0;
}
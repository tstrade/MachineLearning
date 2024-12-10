#include "LinearRegression.h"

#include <stdio.h>
#include <stdlib.h>


char *parseFile(FILE *input_data)
{
  if (input_data == NULL)
    {
      fprintf(stderr, "Error: Could not open file! Check file name and/or file path.\n");
      exit(-1);
    }

}


int splitData(float splitRatio, char *input);


int train();


int test(int numPredictors);


char *evaluate();


int main(int argc, char **argv) {
  if (argc != 2)
  {
    fprintf(stderr, "Too few or too many arguments. Please only provide name of CSV file.\n");
    return -1;
  }

  FILE *input_data = fopen(argv[1], "r");
  char *input = parseFile(input_data);

  float splitRatio;
  printf("\nPlease enter the ratio of the train-test data split (ex. for 80/20, enter 0.8): ");
  scanf("%f", &splitRatio);
  splitData(splitRatio, input);
  return 0;
}

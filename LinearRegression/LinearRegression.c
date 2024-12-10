#include "LinearRegression.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 512

struct LR {
  float **data;
  char *evaluation;
  float *predictorWeights;
  int numColumns;
  int numRows;
  float splitRatio;
  float **trainingSplit;
  float **testingSplit;
  float **testResults;
} *model;

int parseFile(char **argv) {
  FILE *input_data = fopen(argv[1], "r");
  if (input_data == NULL) {
    fprintf(stderr, "Error: Could not open file! Check file name and/or file path.\n");
    exit(EXIT_FAILURE);
  }

  model->numColumns = atoi(argv[2]);
  model->numRows = atoi(argv[3]);

  model->data = malloc(model->numRows * sizeof(float *));
  if (model->data == NULL) {
    fprintf(stderr, "Not enough memory - too many rows.\n");
    exit(EXIT_FAILURE);
  }

  model->predictorWeights = malloc(model->numColumns * sizeof(float));
  if (model->predictorWeights == NULL) {
    fprintf(stderr, "Not enough memory - too many columns.\n");
    exit(EXIT_FAILURE);

  for (int i = 0; i < model->numRows; i++) {
    model->data[i] = malloc(model->numColumns * sizeof(float));
    if (model->data[i] == NULL) {
      fprintf(stderr, "Not enough memory - too much data.\n");
      exit(EXIT_FAILURE);
    }
  }

  char *buffer, *character;
  int row, column;

  while (fgets(buffer, MAX_LINE, input_data) && row < model->numRows) {
    for (column = 0; column < model->numColumns; column++) {
      if ((character = strtok(buffer, ",")) != NULL) {
        model->data[row][column] = atof(character);
      }
    }
    row++;
  }

  // Close file
  fclose(input_data);

  return 0;
}


int splitData();


int train();


int test();


int evaluate();


int main(int argc, char **argv) {
  if (argc != 4) // executable, file path, number columns, number rows
  {
    fprintf(stderr, "Too few or too many arguments. Please only provide name of CSV file.\n");
    return -1;
  }

  parseFile(argv);

  printf("\nPlease enter the ratio of the train-test data split (ex. for 80/20, enter 0.8): ");
  scanf("%f", &splitRatio);
  splitData();
  return 0;
}

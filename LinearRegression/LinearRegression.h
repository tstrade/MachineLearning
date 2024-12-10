#ifndef _LINEARREGRESSION_H
#define _LIENARREGRESSION_H

#include <stdio.h>

// Numberer of parameters to train will be allocated based on the number of predictors provided by the input data
extern int *predictorWeights;
// Split to be defined by user
extern char *trainingSplit;
extern char *testingSplit;
// Two columns - one for predicted results, one for actual results (from testing split)
extern float *testResults;

char *parseFile(FILE *input_data); // Convert CSV file to buffer
char *cleanData(char *data); // Future implementation, currently assuming well-formatted CSV
// Functions below will return -1 on unexpected failure; else returned integer is success / other useful information (such as number of columns)
int splitData(float splitRatio, char *input); // User-defined train-test split (invalid input will default to 70-30 split)
int train(); // Identifies number of predictors (assuming the last column is the target), allocates predictorWeights, and trains parameters
int test(int numPredictors); // Uses predictorWeights on test data to produce predictor outcomes of target variable
// Evaluation will result in a file containing parameter rankings, R-squared value, etc. (largely motivated by outputs that RStudio would provide)
char *evaluate(); // Compares predicted outcome to target variable from testing split

#endif

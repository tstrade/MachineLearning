#ifndef _LINEARREGRESSION_H
#define _LINEARREGRESSION_H

#include <stdio.h>

// Linear regression structure will hold pointers to necessary info for model
// Will be used to call back model information during evaluation
typedef struct LR LR;

/*
  Input/Output buffers
   LR member: char *data
   LR member: char *evaluation;
  Numberer of parameters to train will be allocated based on the number of predictors provided by the input data
   LR member: int *predictorWeights;
   LR member: int numPredictors;
  Split to be defined by user
   LR member: float splitRatio
   LR member: float *trainingSplit;
   LR member: float *testingSplit;
  Two columns - one for predicted results, one for actual results (from testing split)
   LR member: float *testResults;
*/

// Functions below will return -1 on unexpected failure; else returned integer is success / other useful information (such as number of columns)
int parseFile(FILE *input_data); // Convert CSV file to buffer
int cleanData(); // Future implementation, currently assuming well-formatted CSV
int splitData(); // User-defined train-test split (invalid input will default to 70-30 split)
int train(); // Identifies number of predictors (assuming the last column is the target), allocates predictorWeights, and trains parameters
int test(); // Uses predictorWeights on test data to produce predictor outcomes of target variable

// Evaluation will result in a buffer containing parameter rankings, R-squared value, etc. (largely motivated by outputs that RStudio would provide)
int evaluate(); // Compares predicted outcome to target variable from testing split

// Write model evaluations to a new file and free the used memory
int writeAndDestory();

#endif

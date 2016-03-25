# Perceptron

**Note:** This library is still under initial development and shouldn't be used as of yet.

## Intro

The perceptron algorithm is a binary classifier which served as a stepping stone to some of the first artificial neural networks ever produced. The algorithm itself is a single neuron with the unit step function as its activation function. The alorithm returns a true or false, signifying if the given input vector is a part of the perceptron's learned classification space.

## Build It

Install [SCons](http://scons.org/) on your system and simply run the `scons` command in the root directory of this repository.

## Basic Usage

```c++
include "includes/perceptron.hpp"

// Construct a perceptron and a trainer...
perceptron::Perceptron perceptron;
perceptron::Trainer trainer;

// Train your perceptron...
trainer.AssignTrainee(perceptron);
trainer.SetRate(RateValue);
while(IsMoreData())
{
    trainer.Train(GetNextInput(), GetNextExpectedResult());
}

// Categorize with your perceptron...
if(perceptron.Evaluate(GetInput()))
{
    cout << "It's a match!";
}
else
{
    cout << "No match here.";
}
```

## API

__working on it...__

## Examples

__working on it...__
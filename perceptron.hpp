#ifndef _PERCEPTRON_HPP_INCLUDED_
#define _PERCEPTRON_HPP_INCLUDED_

#include <vector>

class Perceptron
{
public:
    Perceptron(int dimensions);
    bool Evaluate(std::vector<int>& input);
    friend class Trainer;

private:
    int dimensions_;
    std::vector<int>* weights_;
};


class Trainer
{
public:
    void SetRate(int rate);
    void AssignTrainee(Perceptron& trainee);
    void Train(std::vector<int>& input, bool expected);

private:
    Perceptron* trainee_;
    int dimensions_;
    float rate_;
};

#endif
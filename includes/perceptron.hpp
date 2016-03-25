#ifndef PERCEPTRON_HPP_INCLUDED_
#define PERCEPTRON_HPP_INCLUDED_

#include <vector>

namespace perceptron {

class Perceptron
{
public:
    Perceptron(int dimensions);
    Perceptron(vector<int> weights);
    Perceptron(Perceptron perceptron);
    ~Perceptron();
    bool Evaluate(std::vector<int>& input);
    std::vector<int> GetWeights();
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

} // namespace perceptron

#endif // PERCEPTRON_HPP_INCLUDED_
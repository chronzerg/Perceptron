#include "../includes/perceptron.hpp"
#include <vector>

namespace perceptron {

typedef Perceptron P;
typedef Trainer    T;
typedef std::vector<int>::iterator iter;


// Perceptron
// ==========

P::Perceptron(int dimensions)
{
    P::weights_ = new std::vector<int>(dimensions);
}

P::Perceptron(const std::vector<int>& weights)
{
    P::weights_ = new std::vector<int>(weights);
}

P::~Perceptron()
{
    delete P::weights_;
}

bool P::Evaluate(std::vector<int>& inputs)
{
    iter weight = (*P::weights_).begin();
    iter input = inputs.begin();
    int dot_product = 0;

    while(weight != (*P::weights_).end())
    {
        dot_product += (*weight) * (*input);
        weight++;
        input++;
    }

    return (dot_product > 0);
}

std::vector<int>* P::GetWeights()
{
    return new std::vector<int>(*P::weights_);
}


// Trainer
// =======

void T::SetRate(int rate)
{
    T::rate_ = rate;
}

void T::AssignTrainee(Perceptron& trainee)
{
    T::trainee_ = &trainee;
}

void T::Train(std::vector<int>& inputs, bool expected)
{
    bool actual = (*T::trainee_).Evaluate(inputs);
    int error = (int)expected - (int)actual;

    if (error != 0)
    {
        int adjustment = T::rate_ * error;

        iter w = (*(*T::trainee_).weights_).begin();
        while(w < (*(*T::trainee_).weights_).end())
        {
            (*w) += adjustment;
            w++;
        }
    }
}

} // namespace perceptron
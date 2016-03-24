#include "perceptron.hpp"

typedef Perceptron p;
typedef Trainer t;
typedef std::vector<int>::iterator viter;

p::Perceptron(int dimensions)
{
    p::dimensions_ = dimensions;
    p::weights_ = new std::vector<int>(dimensions);
}

bool p::Evaluate(std::vector<int>& input)
{
    viter w = (*p::weights_).begin();
    viter i = input.begin();
    int sum = 0;

    // Dot-product the two vectors.
    while(w != (*p::weights_).end())
    {
        sum += (*w) * (*i);
        w++;
        i++;
    }

    return (sum > 0);
}

void t::SetRate(int rate)
{
    t::rate_ = rate;
}

void t::AssignTrainee(Perceptron& trainee)
{
    t::trainee_ = &trainee;
}

void t::Train(std::vector<int>& input, bool expected)
{
    bool actual = (*t::trainee_).Evaluate(input);
    int error = (int)expected - (int)actual;

    if (error != 0)
    {
        int adjustment = t::rate_ * error;

        viter w = (*(*t::trainee_).weights_).begin();
        while(w < (*(*t::trainee_).weights_).end())
        {
            (*w) += adjustment;
            w++;
        }
    }
}
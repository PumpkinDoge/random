

#include <iostream>
#include <iomanip>
#include <cmath>
int input_size = 0;

// This module calculates the mean or average of the dataset.
float mean(float data[])
{
    float total = 0;
    for (int i = 0; i < input_size; i++)
    {
        total += data[i];
    }
    return (total / input_size);
}

// This module calculates the standard deviation of the dataset.
float std_dev(float data[])
{
    float total = 0;
    float mean_num = mean(data);
    for (int i = 0; i < input_size; i++)
    {
        total += pow((data[i] - mean_num), 2);
    }
    return sqrt(total/(input_size-1));
}

// This module calculates the standard deviation of the mean or the standard error of the dataset.
float std_error(float data[])
{
    return (std_dev(data)/sqrt(input_size));
}

// Main module takes in a sequence of numbers in a dataset and uses "q" as an endpoint. 
// Displays the mean, standard deviation, and standard error of the dataset.
// Accuracy is reduced to the thousandth place or 3 digits after the decimal.
int main()
{
    float input;
    float values[100];

    std::cout << std::fixed << std::setprecision(3);
    std::cout << "Please enter in a dataset of numbers, use q to indicate where to stop: ";

    while (std::cin >> input)
    {
        values[input_size] = input;
        ++input_size;
    }
    
    std::cout << "";
    std::cout << "\nThe mean of this dataset is: " << mean(values) << std::endl;
    std::cout << "";
    std::cout << "\nThe standard deviation of this dataset is: " << std_dev(values) << std::endl;
    std::cout << "";
    std::cout << "\nThe standard error of this dataset is: " << std_error(values) << std::endl;

    return 0;
}

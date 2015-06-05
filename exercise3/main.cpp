#include <iostream>
#include <omp.h>
#include <list>
#include <string>
#include <sstream>
#include <iomanip>
#include <sys/time.h>

struct solution {
    int x;
    int y;
    int z;
    int numberOfSolution;
};

std::list<solution> solutions;

int c = 0;

long usedCPUTime = 0;

int numberOfSolutions = 0;


// Check if a solution is valid
bool checkSolution(int x, int y, int z){
    return x + y + z == c;
}


// loop and try to find solutions
void guessSolutions(){

    int x;
    int y;
    int z;



    #pragma omp parallel for
    for(int x = 0; x <= c; x++)
    {
        for(int y = 0; y <= c-x; y++)
        {
            z = c - (x + y);

            if(checkSolution(x, y, z)){
                numberOfSolutions++;
                struct solution foundSolution = {x, y, z, numberOfSolutions};
                solutions.push_back(foundSolution);
            }
        }
    }
}


void printSolutions(){
    if(solutions.empty()){
        std::cout << "Keine Loesungen gefunden.";
    }
    else {
        int counter = 1;
        std::cout << "Gefundene Loesungen:" << std::endl << std::endl;

        // output stream
        std::stringstream output_stream;

        while(!solutions.empty()){
            // get first element in list
            struct solution currentSolution = solutions.front();

            // string length of list size
            const size_t MAXWIDTH_SOLUTIONSIZE = std::to_string(solutions.size()).size();

            // string length of maximum value for one variable
            const size_t  MAXWIDTH_VARIABLE = std::to_string(c).size() + 1;

            // print solution counter
            output_stream << "[";
            output_stream << std::right << std::setw(MAXWIDTH_SOLUTIONSIZE) << std::setfill('0') << counter;
            output_stream << "] ";

            // print x value
            output_stream << "x: "
            << std::right << std::setw(MAXWIDTH_VARIABLE) << std::setfill(' ')
            << currentSolution.x << "  |  ";

            // print y value
            output_stream << "y: "
            << std::right << std::setw(MAXWIDTH_VARIABLE) << std::setfill(' ')
            << currentSolution.y << "  |  ";

            // print z value
            output_stream << "z: "
            << std::right << std::setw(MAXWIDTH_VARIABLE) << std::setfill(' ')
            << currentSolution.z << std::endl;

            // delete the first element in list
            solutions.pop_front();

            // increment counter for printed solutions
            counter++;
        }

        // print to console
        std::cout << output_stream.str() << std::endl;

        std::cout << "Die Kalkulation dauerte: " << usedCPUTime << "ms";
    }
}


int main()
{
    std::cout << "Eine Konstante c (nur ganze Zahlen) eingeben:" << std::endl;
    std::cin >> c;
    std::cout << std::endl;

    struct timeval timerStart;
    struct timeval timerEnd;

    // save start time
    #pragma omp critical
    gettimeofday(&timerStart, NULL);

    guessSolutions();

    // save end time
    #pragma omp critical
    gettimeofday(&timerEnd, NULL);

    usedCPUTime = (timerEnd.tv_sec - timerStart.tv_sec) * 1000000u + timerEnd.tv_usec - timerStart.tv_usec;

    printSolutions();

    std::cin.get();
    return 0;
}
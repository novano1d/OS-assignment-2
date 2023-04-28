//Matthew Moore
#include <iostream>
#include <fstream>
#include <string>
const int NUM_PROCESSES = 5;
const int NUM_RESOURCES = 3;
bool checkSafe(int processesArr[], int available[], int max[][NUM_RESOURCES], int allocated[][NUM_RESOURCES]) 
{
    int need[NUM_PROCESSES][NUM_RESOURCES];
    for (int i = 0 ; i < NUM_PROCESSES ; i++) 
    {
        for (int j = 0 ; j < NUM_RESOURCES ; j++) need[i][j] = max[i][j] - allocated[i][j];
    }
    bool done[NUM_PROCESSES] = {0};
    int sequence[NUM_PROCESSES];
    int work[NUM_RESOURCES];
    for (int i = 0; i < NUM_RESOURCES; i++) work[i] = available[i];
    int count = 0;
    while (count < NUM_PROCESSES) 
    {
        bool found = false;
        for (int p = 0; p < NUM_PROCESSES; p++) 
        {
            if (done[p] == 0) 
            {
                int j = 0;
                for (j = 0; j < NUM_RESOURCES; j++) 
                {
                    if (need[p][j] > work[j]) break;
                }
                if (j == NUM_RESOURCES) 
                {
                    for (int k = 0 ; k < NUM_RESOURCES; k++) work[k] += allocated[p][k];
                    sequence[count++] = p;
                    done[p] = 1;
                    found = true;
                }
            }
        }
        if (!found) 
        {
            std::cout << "The system is not in a safe state." << std::endl;
            return false;
        }
    }
    std::cout << "The system is in safe state. Safe sequence is: ";
    for (int i = 0; i < NUM_PROCESSES ; i++) std::cout << sequence[i] << ' ';
    std::cout << std::endl;
    return true;
}
int main()
{
    int processesArr[] = { 0, 1, 2, 3, 4 };
    std::ifstream table("input.txt", std::ios_base::in);
    if (!table) 
    {
        std::cout << "Failed to open input.txt." << std::endl;
        return EXIT_FAILURE;
    }
    int max[NUM_PROCESSES][NUM_RESOURCES];
    int allocated[NUM_PROCESSES][NUM_RESOURCES];
    int available[NUM_RESOURCES];
    for (int i = 0; i < NUM_PROCESSES; ++i) 
    { 
        for (int j = 0; j < NUM_RESOURCES; ++j) table >> allocated[i][j];
        for (int j = 0; j < NUM_RESOURCES; ++j) table >> max[i][j];
        if (i == 0) for (int j = 0; j < NUM_RESOURCES; ++j) table >> available[j];
    }
    std::cout << "Allocated: ";
    for (int i = 0; i < NUM_PROCESSES; ++i)
        for (int j = 0; j < NUM_RESOURCES; ++j) std::cout << allocated[i][j] << ' ';
    std::cout << std::endl;
    std::cout << "Max: ";
    for (int i = 0; i < NUM_PROCESSES; ++i)
        for (int j = 0; j < NUM_RESOURCES; ++j) std::cout << max[i][j] << ' ';
    std::cout << std::endl;
    std::cout << "Available: ";
    for (int i = 0; i < NUM_RESOURCES; ++i) std::cout << available[i] << ' ';
    std::cout << std::endl;
    checkSafe(processesArr, available, max, allocated);
    return EXIT_SUCCESS;
}

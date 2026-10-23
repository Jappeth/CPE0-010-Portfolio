#ifndef ILOC_H
#define ILOC_H

#include <windows.h>


//1. Create a class called Job (comprising an ID for the job, the name of the user who submitted it, and thenumber of pages)
class Job {
    private:
        int Id;
        std::string Name;
        int Pages;

    public:
        Job(int id = 0, std::string name = "", int pages = 0) {
            Id = id;
            Name = name;
            Pages = pages;
        }

        int getID() {
            return Id;
        }
        std::string getName() {
            return Name;
        }
        int getPages() {
            return Pages;
        }

        void PrintDetails() {
            std::cout << "ID: " << Id << std::endl;
            std::cout << "Name: " << Name << std::endl;
            std::cout << "Page Count: " << Pages << std::endl << std::endl;
        }
};

class qNode{
    public: 
        Job data;
        qNode* next;

        qNode(Job newData) {
            data = newData;
            next = nullptr;
        }
};


//2. Create a class called Printer. This will provide an interface to add new jobs and process all the jobs added so far.
class Printer {
    private:
        qNode* firstJob;
        qNode* lastJob;
    public:
        Printer() {
            firstJob = nullptr;
            lastJob = nullptr;
        }

        ~Printer() {
            while(firstJob != nullptr) {
                qNode* temp = firstJob;
                firstJob = firstJob->next;
                delete temp;
            }
            lastJob = nullptr;
        }

        bool Empty() {
            return (firstJob == nullptr && lastJob == nullptr);
        }

        
        //3. To implement the printer class, it will need to store all the pending jobs. 
        void addJob(Job newJob) {
            qNode* newNode = new qNode(newJob);

            if(Empty()) {
                firstJob = newNode;
                lastJob = newNode;
            } else {
                lastJob->next = newNode;
                lastJob = newNode;
            }

            std::cout << "Added!" << std::endl;
            newJob.PrintDetails();
        }

        //We'll implement a very basic strategy – first come, first served. Whoever submits the job first will be the first to get the job done.
        void StartPrinting() {
            std::cout << "PRINTING_ _ _" << std::endl;

            if(Empty()) {
                std::cout << "There was nothing to print." << std::endl;
                return;
            }

            while(firstJob != nullptr) {
                qNode* temp = firstJob;

                Sleep(1000 * temp->data.getPages());

                std::cout << "Printed: " << temp->data.getName() << std::endl;
                

                if(firstJob == lastJob) {
                    firstJob = nullptr;
                    lastJob = nullptr;
                } else {
                    firstJob = firstJob->next;
                }

                temp->next = nullptr;
                delete temp;
            }

            std::cout << "Printing Finished!!!" << std::endl << std::endl;
        }
};


#endif
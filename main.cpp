#include "exercise_3_2.hpp"
#include <string>
#include <iostream>

int main() {
    LinkedList trainers = LinkedList();
    trainers.add_to_back("test1");

    trainers.add_to_front("test2");
    trainers.add_to_back("test0");
    trainers.add_at_index("test3", 0);

    trainers.print_names();
    trainers.remove_from_front();
    trainers.print_names();

    trainers.remove_from_back();

    trainers.print_names();
    trainers.remove_from_back();
    trainers.print_names();

    trainers.remove_from_back();
    trainers.print_names();


    trainers.add_to_back("test1");
    trainers.remove_from_front();
    trainers.print_names();
    
    return 1;
}

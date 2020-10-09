#include "exercise_3_2.hpp"
#include <iostream>

LinkedList::LinkedList() {
    head = nullptr;
}

void LinkedList::add_to_front(std::string name) {
    std::unique_ptr<Node> newNode = std::make_unique<Node>();
    newNode -> name = name;
    newNode -> next = std::move(head);
    head = std::move(newNode);
    return;
}

void LinkedList::add_to_back(std::string name) {
	std::unique_ptr<Node> newNode = std::make_unique<Node>();
    newNode -> name = name;
    newNode -> next = nullptr;
    if(head == nullptr) {
    	head = std::move(newNode);
    	return;
    }
    Node* curr = head.get();
    while(curr -> next != nullptr) {
    	curr = curr -> next.get();
    }
    curr -> next = std::move(newNode);

    return;
}

void LinkedList::add_at_index(std::string name, int index) {
	std::unique_ptr<Node> newNode = std::make_unique<Node>();
    newNode -> name = name;
    newNode -> next = nullptr;
    if(head == nullptr || index <= 0) {
    	add_to_front(name);
    	return;
    }
    Node* curr = head.get();
    for(int i = 0; i < index - 1;  i++) {
    	if(curr -> next == nullptr){
    		curr -> next = std::move(newNode);
    		return;
    	}
    	curr = curr -> next.get();
    }
    newNode->next = std::move(curr->next);
    curr->next = std::move(newNode);
    return;
}

void LinkedList::remove_from_front() {
	if(head != nullptr) {
		head = std::move(head->next);
	}
    return;
}

void LinkedList::remove_from_back() {
    Node* curr = head.get();
    if(head == nullptr) {
    	return;
    } else if (head ->next == nullptr) {
    	head = std::move(nullptr);
    	return;

    }
	while(curr->next->next != nullptr) {
		curr = curr->next.get();
	}
	curr -> next = nullptr;
    return;
}

void LinkedList::print_names() {
	Node* curr = head.get();
	while(curr != nullptr) {
		std::cout << curr->name << " ";
		curr = curr->next.get();
	}
	std::cout << std::endl;
    return;
}

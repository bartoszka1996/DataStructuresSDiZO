//
// Created by barto on 11.04.17.
//

#ifndef DATASTRUCTURESSDIZO_LIST_H
#define DATASTRUCTURESSDIZO_LIST_H


#include "Structure.h"

class List : public Structure {
private:

    class _listElement;

    _listElement* _firstElement;
    _listElement* _lastElement;

public:

    List();

    ~List();

    void loadDataFrom(std::string fileName) override ;

    bool lookFor(int value) override ;

    void add(int value, int index) override ;

    void remove(int value) override ;

    void remove(int index, int value) override ;

    void removePosition(int index) override ;

    std::string print() override ;

    void generate(int size) override ;

private:

    void addAtTheBeggining(int value);

    void addAtTheEnd(int value);

};


#endif //DATASTRUCTURESSDIZO_LIST_H